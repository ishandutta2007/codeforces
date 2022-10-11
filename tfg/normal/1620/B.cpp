#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct PT {
    typedef long long T;
    T x, y;
    PT(T _x = 0, T _y = 0) : x(_x), y(_y){}
    PT operator +(const PT &p) const { return PT(x+p.x,y+p.y); }
    PT operator -(const PT &p) const { return PT(x-p.x,y-p.y); }
    PT operator *(T c)         const { return PT(x*c,y*c);     }
    //PT operator /(double c)    const { return PT(x/c,y/c);     }
    T operator *(const PT &p)  const { return x*p.x+y*p.y;     }
    T operator %(const PT &p)  const { return x*p.y-y*p.x;     }
    //double operator !()        const { return sqrt(x*x+y*y);   }
    //double operator ^(const PT &p) const { return atan2(*this%p, *this*p);}
    bool operator < (const PT &p) const { return x != p.x ? x < p.x : y < p.y; }
    bool operator == (const PT &p)const { return x == p.x && y == p.y; }

    friend std::ostream& operator << (std::ostream &os, const PT &p) {
        return os << p.x << ' ' << p.y;
    }
    friend std::istream& operator >> (std::istream &is, PT &p) {
        return is >> p.x >> p.y;
    }
};


std::vector<PT> ConvexHull (std::vector<PT> pts, bool needs = true) {
    if(needs) {
        std::sort(pts.begin(), pts.end());
    }
    pts.resize(std::unique(pts.begin(), pts.end()) - pts.begin());
    if(pts.size() <= 1) return pts;
    std::vector<PT> ans(pts.size() * 2 + 1);
    int s = 0;
    for(int i = 0; i < (int) pts.size(); i++) {
        while(s > 1 && (pts[i] - ans[s - 2]) % (ans[s - 1] - ans[s - 2]) >= 0) {
            s--;
        }
        ans[s++] = pts[i];
    }
    for(int i = (int) pts.size() - 2, t = s + 1; i >= 0; i--) {
        while(s >= t && (pts[i] - ans[s - 2]) % (ans[s - 1] - ans[s - 2]) >= 0) {
            s--;
        }
        ans[s++] = pts[i];
    }
    ans.resize(s-1);
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        std::vector<PT> a;
        int w, h;
        std::cin >> w >> h;
        for(int rep = 0; rep < 4; rep++) {
            int sz;
            std::cin >> sz;
            while(sz--) {
                int val;
                std::cin >> val;
                PT pt(rep == 2 ? 0 : (rep == 3 ? w : val), rep == 0 ? 0 : (rep == 1 ? h : val));
                a.push_back(pt);
            }
        }
        a = ConvexHull(a);
        long long ans = 0;
        for(int i = 0; i < (int) a.size(); i++) {
            int j = (i+1) % (int) a.size();
            bool good = false;
            if(a[i].x == a[j].x && (a[i].x == 0 || a[i].x == w)) {
                good = true;
            } else if(a[i].y == a[j].y && (a[i].y == 0 || a[i].y == h)) {
                good = true;
            }
            if(good) for(int k = 0; k < (int) a.size(); k++) {
                ans = std::max(ans, (a[j] - a[i]) % (a[k] - a[i]));
            }
        }
        std::cout << ans << '\n';
    }
}