/**
 *    author:  otera
 *    created: 19.03.2021 00:13:15 
**/
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
const int inf=1e9+7;
const ll INF=1LL<<60;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define pb push_back
#define eb emplace_back
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define Sort(a) sort(all(a))
#define Rev(a) reverse(all(a))
#define Uniq(a) sort(all(a));a.erase(unique(all(a)),end(a))
#define si(c) (int)(c).size()
inline ll popcnt(ull a){ return __builtin_popcountll(a); }
#define tpow(n) (1LL<<(n))
#define unless(A) if(!(A))
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
#define vec(type,name,...) vector<type>name(__VA_ARGS__)
#define VEC(type,name,size) vector<type>name(size);in(name)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));in(name)
#define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> void scan(T& a){ cin >> a; }
template<class T> void scan(vector<T>& a){ for(auto&& i : a) scan(i); }
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){ scan(head); in(tail...); }
void print(){ cout << ' '; }
template<class T> void print(const T& a){ cout << a; }
template<class T> void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout << ' '; print(*i); } }
int out(){ cout << '\n'; return 0; }
template<class T> int out(const T& t){ print(t); cout << '\n'; return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); cout << ' '; out(tail...); return 0; }
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,a4,x,...) x
#define debug_1(x1) cout<<#x1<<": "<<x1<<endl
#define debug_2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl
#define debug_3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl
#define debug_4(x1,x2,x3,x4) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<endl
#define debug_5(x1,x2,x3,x4,x5) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<", "#x5<<": "<<x5<<endl
#ifdef DEBUG
#define debug(...) CHOOSE((__VA_ARGS__,debug_5,debug_4,debug_3,debug_2,debug_1,~))(__VA_ARGS__)
#define dump(...) { print(#__VA_ARGS__); print(":"); out(__VA_ARGS__); }
#else
#define debug(...)
#define dump(...)
#endif

// #define int long long

map<int, int> mp;

// int extgcd(int a, int b, int& x, int& y) {
//     int d = a;
//     if(b != 0) {
//         d = extgcd(b, a % b, y, x);
//         y -= (a / b) * x;
//     } else {
//         x = 1; y = 0;
//     }
//     return d;
// }

// isprime[n] := is n prime?
// mebius[n] := mebius value of n
// min_factor[n] := the min prime-factor of n
struct Eratos {
    vector<int> primes;
    vector<bool> isprime;
    vector<int> min_factor;
    vector<int> cnt;

    Eratos(int MAX) : primes(),
                      isprime(MAX+1, true),
                    //   min_factor(MAX+1, -1),
                      cnt(MAX+1, 0) {
        isprime[0] = isprime[1] = false;
        // min_factor[0] = 0, min_factor[1] = 1;
        for (int i = 2; i <= MAX; ++i) {
            if (!isprime[i]) continue;
            primes.push_back(i);
            // min_factor[i] = i;
            cnt[i] ++;
            for (int j = i*2; j <= MAX; j += i) {
                isprime[j] = false;
                cnt[j] ++;
                // if (min_factor[j] == -1) min_factor[j] = i;
            }
        }
    }

    // prime factorization
    int prime_factors(int n) {
        return cnt[n];
        // if(n == 1) return 0;
        // if(mp.count(n)) {
        //     return mp[n];
        // }
        // int cnt = 0;
        // while (n != 1) {
        //     int prime = min_factor[n];
        //     int exp = 0;
        //     while (min_factor[n] == prime) {
        //         ++exp;
        //         n /= prime;
        //     }
        //     ++ cnt;
        // }
        // return mp[n] = cnt;
    }
};

const int MAX = 20'000'010;

void solve() {
    Eratos er(MAX);
    INT(t);
    rep(_, t) {
        LL(c, d, x);
        // ll C = c, D = d;
        // ll g = __gcd(c, d);
        // if(x % g != 0) out(0);
        // else {
        //     ll y, z;
        //     c /= g, d /= g;
        //     extgcd(c, d, y, z);
        //     z = -z;
        //     assert(c * y - d * z == 1);
        //     // if(y <= 0 or z <= 0) {
        //         ll k = 0;
        //         if(y < 0) chmax(k, (-y + d - 1) / d);
        //         if(z < 0) chmax(k, (-z + c - 1) / c);
        //         // y += d * k;
        //         // z += c * k;
        //     // }
        //     if(y + d * k == 0) ++ k;
        //     if(z + c * k == 0) ++ k;
        //     y += d * k;
        //     z += c * k;
        //     if(y > 0 and z > 0) {
        //         ll t = min(y / d, z / c);
        //         debug(t);
        //         y -= d * t;
        //         z -= c * t;
        //     }
        //     ll v = x / g;
        //     // debug(y, z);
        //     y *= (x / g), z *= (x / g);
        //     debug(y, z, d, c);
        //     assert(C * y - D * z == x);

        // }
        ll ans = 0;
        for(int i = 1; i * i <= x; ++ i) {
            if(x % i == 0) {
                int g = i;
                int t = x / g + d;
                if(t % c == 0) {
                    t /= c;
                    debug(g, t);
                    ans += (1LL<<er.prime_factors(t));
                }
                if(i * i != x) {
                    int g2 = x / i;
                    int t2 = x / g2 + d;
                    if(t2 % c == 0) {
                        t2 /= c;
                        debug(g2, t2);
                        ans += (1LL<<er.prime_factors(t2));
                    }
                }
            }
        }
        out(ans);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(20);
    // INT(t); rep(i, t)solve();
    solve();
    return 0;
}