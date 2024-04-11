#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;
const int MOD = 998244353;

template <class T>
T fexp(T x, long long e) {
    T ans(1);
    for(; e > 0; e /= 2) {
        if(e & 1) ans = ans * x;
        x = x * x;
    }
    return ans;
}

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

int a[ms], LIM;
modBase<> two[ms];

int getMid(int l, int r, int bit) {
    int ans = l;
    while(ans < r && ((a[ans] >> bit) & 1) == 0) ans++;
    return ans;
}

modBase<> solve(int l0, int r0, int l1, int r1, int bit) {
    if(bit == -1 || l0 == r0 || l1 == r1) {
        modBase<> ans = (two[r0-l0]) * (two[r1-l1])-1;
        //std::cout << "base case at [" << l0 << ", " << r0 << ") , [" << l1 << ", " << r1 << ") bit " << bit << " == " << ans << '\n';
        return ans;
    }
    int mid0 = getMid(l0, r0, bit);
    int mid1 = getMid(l1, r1, bit);
    modBase<> ans;
    if(LIM & (1 << bit)) {
        ans = (solve(l0, mid0, mid1, r1, bit-1) + 1) * (solve(mid0, r0, l1, mid1, bit-1) + 1) - 1;
    } else {
        // can't be mixed
        ans = solve(l0, mid0, l1, mid1, bit-1) + solve(mid0, r0, mid1, r1, bit-1) - (two[mid0-l0]-1 + two[r0-mid0]-1) - (two[mid1-l1]-1 + two[r1-mid1]-1) + (two[r0-l0]-1 + two[r1-l1]-1);
    }
    //std::cout << "at [" << l0 << ", " << r0 << ") , [" << l1 << ", " << r1 << ") bit " << bit << " == " << ans << '\n';
    return ans;
}

modBase<> solve(int l, int r, int bit) {
    if(l == r) return 0;
    if(bit == -1) {
        return two[r-l] - 1;
    }
    int mid = getMid(l, r, bit);
    modBase<> ans;
    if(LIM & (1 << bit)) {
        // can be mixed
        ans = solve(l, mid, mid, r, bit-1);
    } else {
        // can't be mixed
        ans = solve(l, mid, bit-1) + solve(mid, r, bit-1);
    }
    //std::cout << "at solve(" << l << ", " << r << ", " << bit << ") == " << ans << std::endl;
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n;
    std::cin >> n >> LIM;
    two[0] = 1;
    for(int i = 1; i <= n; i++) two[i] = two[i-1] * 2;
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a, a + n);
    std::cout << solve(0, n, 29) << '\n';
}