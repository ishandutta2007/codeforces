#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long double eps = 1e-10;

struct PT {
    typedef long double T;
    T x, y;
    //long long orix, oriy;
    PT(T _x = 0, T _y = 0) : x(_x), y(_y){}
    PT operator +(const PT &p) const { return PT(x+p.x,y+p.y); }
    PT operator -(const PT &p) const { return PT(x-p.x,y-p.y); }
    PT operator *(T c)         const { return PT(x*c,y*c);     }
    //PT operator /(double c)    const { return PT(x/c,y/c);     }
    T operator *(const PT &p)  const { return x*p.x+y*p.y;     }
    T operator %(const PT &p)  const { return x*p.y-y*p.x;     }
    //double operator !()        const { return sqrt(x*x+y*y);   }
    //double operator ^(const PT &p) const { return atan2(*this%p, *this*p);}
    bool operator < (const PT &p) const { return *this % p < 0; }

    friend std::ostream& operator << (std::ostream &os, const PT &p) {
        return os << p.x << ' ' << p.y;
    }
    friend std::istream& operator >> (std::istream &is, PT &p) {
        return is >> p.x >> p.y;
    }
};


void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    PT st(a, b), en(a, b);
    std::vector<PT> vectors(n);
    for(int i = 0; i < n; i++) {
        std::cin >> vectors[i].x;
    }
    for(int i = 0; i < n; i++) {
        std::cin >> vectors[i].y;
    }
    std::multiset<PT> slopes;
    std::cout << std::fixed << std::setprecision(15);
    for(int i = 0; i < n; i++) {
        auto vec = vectors[i];
        st = st + PT(-vec.x, vec.y);
        en = en + PT(vec.x, -vec.y);
        slopes.insert(PT(vec.x, -vec.y) * 2);
        // fix
        while(st.x < -eps) {
            auto it = slopes.begin();
            if(it->x <= -st.x) {
                st = st + *it;
                slopes.erase(it);
            } else {
                auto factor = -st.x / it->x;
                st = st + *it * factor;
                st.x = 0;
                PT newPoint = *it * (1.0 - factor);
                slopes.erase(it);
                slopes.insert(newPoint);
                break;
            }
        }
        // other side
        while(en.y < -eps) {
            auto it = --slopes.end();
            if(-it->y <= -en.y) {
                en = en - *it;
                slopes.erase(it);
            } else {
                auto factor = en.y / it->y;
                en = en - *it * factor;
                PT newPoint = *it * (1.0 - factor);
                en.y = 0;
                slopes.erase(it);
                slopes.insert(newPoint);
                break;
            }
        }
        std::cout << en.x << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }
}