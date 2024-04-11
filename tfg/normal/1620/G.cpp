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
    modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
    modBase<mod> operator + (modBase<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
    modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }

    friend std::ostream& operator << (std::ostream &os, const modBase<mod> &p) {
        return os << p.val;
    }
    friend std::istream& operator >> (std::istream &is, modBase<mod> &p) {
        return is >> p.val;
    }
};

template<const char ch, class T>
std::vector<T> FWHT(std::vector<T> a, const bool inv = false) {
    int n = (int) a.size();
    for(int len = 1; len < n; len += len) {
        for(int i = 0; i < n; i += 2 * len) {
            for(int j = 0; j < len; j++) {
                auto u = a[i + j], v = a[i + j + len];
                if(ch == '^') {
                    a[i + j] = u + v;
                    a[i + j + len] = u - v;
                }
                if(ch == '|') {
                    if(!inv) {
                        a[i + j + len] += a[i + j];
                    } else {
                        a[i + j + len] -= a[i + j];
                    }
                }
                if(ch == '&') {
                    if(!inv) {
                        a[i + j] += a[i + j + len];
                    } else {
                        a[i + j] -= a[i + j + len];
                    }
                }
            }
        }
    }
    if(ch == '^' && inv) {
        for(int i = 0; i < n; i++) {
            a[i] = a[i] / n;
        }
    }
    return a;
}

int f[26][26], st[26][26];
int n;

void gen(std::vector<modBase<>> &a, int on, int mask) {
    if(on == n) {
        modBase<> val(1);
        int sign = -1;
        for(int i = 0; i < 26; i++) {
            val *= st[on][i] + 1;
            if(mask & (1 << i)) sign = -sign;
        }
        if(sign == -1) val = modBase<>(0) - val;
        a[mask] = val;
    } else {
        for(int i = 0; i < 26; i++) {
            st[on+1][i] = st[on][i];
        }
        gen(a, on+1, mask);
        for(int i = 0; i < 26; i++) {
            st[on+1][i] = std::min(st[on+1][i], f[on][i]);
        }
        gen(a, on+1, mask | (1 << on));
    }
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::string str;
        std::cin >> str;
        for(auto ch : str) f[i][ch-'a']++;
    }
    std::vector<modBase<>> a(1 << n, 0);
    for(int i = 0; i < 26; i++) {
        st[0][i] = 1e9;
    }
    gen(a, 0, 0);
    a[0] = 0;
    a = FWHT<'|'>(a);
    long long ans = 0;
    for(int i = 1; i < (1 << n); i++) {
        //std::cout << "at " << i << " got " << a[i] << '\n';
        int k = 0, sum = 0;
        for(int j = 0; j < n; j++) if(i & (1 << j)) {
            sum += j + 1;
            k++;
        }
        ans ^= ((long long)a[i].val * k * sum);
    }
    std::cout << ans << '\n';
}