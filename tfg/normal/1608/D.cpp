#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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

const int ms = 200100;
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
    int n;
    std::cin >> n;
    int bas = 0;
    int e = 0;
    modBase<> dp[4] = {1, 0, 0, 0};
    auto can = [](const std::string &str, int mask) {
        for(int i = 0; i < 2; i++) if(str[i] != '?') {
            int val = str[i] == 'W' ? 1 : 0;
            val ^= i;
            if(val != (mask >> i) % 2) {
                return false;
            }
        }
        return true;
    };
    while(n--) {
        std::string str;
        std::cin >> str;
        modBase<> nxt[4] = {0, 0, 0, 0};
        if(can(str, 0)) nxt[1] += dp[0] + dp[1], nxt[3] += dp[2] + dp[3];
        if(can(str, 3)) nxt[2] += dp[0] + dp[2], nxt[3] += dp[1] + dp[3];
        for(int i = 0; i < 4; i++) dp[i] = nxt[i];
        if(str == "??") {
            e += 2;
            bas -= 1;
        } else if(str == "W?" || str == "?W") {
            e += 1;
        } else if(str == "B?" || str == "?B") {
            e += 1;
            bas -= 1;
        } else if(str[0] == str[1]) {
            if(str[0] == 'W') {
                bas++;
            } else {
                bas--;
            }
        }
    }
    /*
    number of AB is equal to BA
    -
    AA with BB or BB with AA
    
    ?? is (x^-1 + 2 + x^1) == x^-1 * (1 + x)^2
    and so on
    */
    std::cout << comb(e, -bas) - dp[3] << '\n';
}