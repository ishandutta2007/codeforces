#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
#include <array>
#include <functional>
#include <stack>
#include <memory>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC

#ifdef LOCAL
#define debug(x) std::cerr << #x << ": " << x << '\n';
#define debug2(x, y) std::cerr << #x << ", " << #y << ": " << x << ", " << y << '\n';
#define debug3(x, y, z) std::cerr << #x << ", " << #y << ", " << #z << ": " << x << ", " << y << ", " << z << '\n';
#else
#define debug(x)
#define debug2(x, y) 
#define debug3(x, y, z) 
#endif

#define FORI(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) FORI(i,0,a)
#define ROFI(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i,a) ROFI(i,0,a)
#define rep(a) FOR(_,a)
#define each(a,x) for (auto& a: x)
#define FORN(i, n) FORI(i, 1, n + 1)

using vi = vector<int>;
template <typename T>
std::istream& operator >>(std::istream& input, std::pair <T, T> & data)
{
    input >> data.x >> data.y;
    return input;
}
template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& data)
{
    for (T& x : data)
        input >> x;
    return input;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const pair <T, T> & data)
{
    output << "(" << data.x << "," << data.y << ")";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
std::ostream& operator <<(std::ostream& output, const __int128 &x)
{
    __int128 n = x;
    if (n == 0) {
        output << "0";
        return output;
    }
    if (n < 0) {
        n = -n;
        output << "-";
    }
    string s;
    while (n) {
        s += '0' + (n%10);
        n /= 10;
    }
    reverse(all(s));
    cout << s;
    return output;
}
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
ll gcd(ll a, ll b) {
    while (b) {
        tie(a, b) = mp(b, a % b);
    }
    return a;
}
int Bit(int mask, int bit) { return (mask >> bit) & 1; }

int  md=998244353;
inline int sum(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}
inline int dif(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}
inline void add(int &a, const int &b) {
    a = sum(a, b);
}
inline void sub(int &a, const int &b) {
    a = dif(a, b);
}
inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}
int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b%2) return mul(a ,binpow(a, b - 1));
    int m = binpow(a,b/2);
    return mul(m,m);
}
int rev(int a) {
    return binpow(a, md - 2);
}

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;

    int sz =n+m + 1;
    vi fac(sz, 1), ifac(sz, 1);
    for (int i = 1; i < sz; ++i) {
        fac[i] = mul(fac[i - 1], i);
    }
    ifac[sz - 1] = rev(fac[sz - 1]);
    for (int i = sz - 2; i >= 0; --i) {
        ifac[i] = mul(ifac[i + 1], i + 1);
    }

    auto C = [&] (int n, int k) {
        assert(k >= 0 && k <= n);
        return mul(fac[n], mul(ifac[n - k], ifac[k]));
    };

    vi d(n);
    cin >> d;
    int sum = accumulate(all(d), 0ll);
    FOR (i, n) {
        d.app(d[i]);
    }

    vi pre(2 * n + 1);
    FOR (i, 2 * n) {
        pre[i + 1] = pre[i] + d[i];
    }

    int p = 0;
    FOR (i, n) {

        if (sum%2==0) {
            auto t = lower_bound(all(pre), pre[i] + sum/2);
            if (*t == pre[i] + sum/2) {
                p++;
            }

        }
    }
    assert(p%2==0);
    p/=2;

    int ans = 0;
    for (int k = 0; k <= p && k <= m; ++k) {

        int d = 1;
        d = mul(d, C(p, k));
        d = mul(d, C(m, k));
        d = mul(d, fac[k]);
        d = mul(d, binpow(m - k, n - p - k));
        d = mul(d, binpow(m - k - 1, p - k));

        add(ans, d);
    }
    cout << ans << endl;
}