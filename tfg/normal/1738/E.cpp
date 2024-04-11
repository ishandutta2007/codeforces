#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T fexp(T x, long long e) {
    T ans(1);
    for(; e > 0; e /= 2) {
        if(e & 1) ans = ans * x;
        x = x * x;
    }
    return ans;
}

const int MOD = 998244353;

template <int mod = MOD>
struct modBase {
    modBase(int v = 0) : val(v < 0 ? v + mod : v) {}
    int val;
 
    void operator += (modBase<mod> o) { *this = *this + o; }
    void operator -= (modBase<mod> o) { *this = *this - o; }
    void operator *= (modBase<mod> o) { *this = *this * o; }
    //void operator /= (modBase<mod> o) { *this = *this / o; }
    modBase<mod> operator * (modBase<mod> o) { return (int)((long long) val * o.val % mod); }
    //modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
    modBase<mod> operator + (modBase<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
    modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }

    friend std::ostream& operator << (std::ostream &os, const modBase<mod> &p) {
        return os << p.val;
    }
    friend std::istream& operator >> (std::istream &is, modBase<mod> &p) {
        return is >> p.val;
    }
};

const int ms = 200200;

modBase<> fat[ms], ifat[ms];
void initComb() {
    fat[0] = 1;
    for(int i = 1; i < ms; i++) {
        fat[i] = fat[i-1] * i;
    }
    ifat[ms-1] = fexp(fat[ms-1], MOD - 2);
    for(int i = ms-1; i > 0; i--) {
        ifat[i-1] = ifat[i] * i;
    }
}
modBase<> comb(int n, int a) { return a < 0 || a > n ? modBase<>(0) : fat[n] * ifat[a] * ifat[n-a]; }

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    initComb();
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        std::vector<long long> a(n);
        std::map<long long, std::pair<int, int>> mp;
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i];
            mp[sum].first++;
        }
        sum = 0;
        for(int i = 0; i < n; i++) {
            sum += a[n-i-1];
            mp[sum].second++;
        }
        modBase<> ans(1);
        for(auto [total, par] : mp) {
            auto [f, s] = par;
            if(total * 2 == sum) {
                ans *= fexp(modBase<>(2), f - (total == 0 ? 1 : 0));
            } else if(total * 2 < sum) {
                ans *= comb(f+s, s);
            }
        }
        std::cout << ans << '\n';
    }
}