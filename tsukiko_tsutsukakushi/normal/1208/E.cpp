/**
 *    author:  otera
 *    created: 11.04.2021 19:14:49 
**/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
const int inf=1e9+7;
const ll INF=1LL<<60;
#define repa(i, n) for(int i = 0; i < n; ++ i)
#define repb(i, a, b) for(int i = a; i < b; ++ i)
#define repc(i, a, b, c) for(int i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, repc, repb, repa)(__VA_ARGS__)
#define rep1a(i, n) for(int i = 0; i <= n; ++ i)
#define rep1b(i, a, b) for(int i = a; i <= b; ++ i)
#define rep1c(i, a, b, c) for(int i = a; i <= b; i += c)
#define rep1(...) overload4(__VA_ARGS__, rep1c, rep1b, rep1a)(__VA_ARGS__)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>=1;i--)
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
ll intpow(ll a, ll b, ll m) {ll ans = 1; while(b){ if(b & 1) (ans *= a) %= m; (a *= a) %= m; b /= 2; } return ans; }
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

#define int long long

template <class Abel> struct BIT {
    Abel UNITY_SUM = 0;
    vector<Abel> dat[2];

    // [0, n)
    BIT(int n, Abel unity = 0) : UNITY_SUM(unity) {
        init(n);
    }
    void init(int n) {
        for (int iter = 0; iter < 2; ++iter)
            dat[iter].assign(n + 1, UNITY_SUM);
    }
    
    // [a, b), a and b are 0-indexed
    inline void sub_add(int p, int a, Abel x) {
        for (int i = a; i < (int)dat[p].size(); i |= i + 1)
            dat[p][i] = dat[p][i] + x;
    }
    inline void add(int a, int b, Abel x) {
        sub_add(0, a, x * (-a));
        sub_add(1, a, x);
        sub_add(0, b, x * b);
        sub_add(1, b, x * (-1));
    }
    
    // [a, b), a and b are 0-indexed
    inline Abel sub_sum(int p, int a) {
        Abel res = UNITY_SUM;
        for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)
            res = res + dat[p][i];
        return res;
    }
    inline Abel sum(int a, int b) {
        return sub_sum(0, b)
            + sub_sum(1, b) * b
            - sub_sum(0, a)
            - sub_sum(1, a) * a;
    }
};

void solve() {
    INT(n, w);
    vc<int> l(n);
    vvc<ll> a(n);
    rep(i, n) {
        in(l[i]);
        a[i].resize(l[i]);
        rep(j, l[i]) {
            in(a[i][j]);
        }
    }
    BIT<ll> ans(w);
    rep(i, n) {
        vc<ll> suml(l[i] + 1, 0), sumr(l[i] + 1, 0);
        // vc<ll> left(l[i], -INF), right(l[i], -INF);
        // rep(j, l[i]) {
        //     if(j == 0) left[j] = a[i][0];
        //     else left[j] = max(a[i][j], left[j - 1]);
        // }
        // rep(j, l[i]) {
        //     if(j == 0) right[j] = a[i][l[i] - 1];
        //     else right[j] = max(a[i][l[i] - 1 - j], right[j - 1]);
        // }
        rep(j, l[i]) {
            suml[j + 1] = max(suml[j], a[i][j]);
        }
        rep(j, l[i]) {
            sumr[j + 1] = max(sumr[j], a[i][l[i] - 1 - j]);
        }
        if(l[i] * 2 <= w) {
            rep(j, l[i]) {
                ans.add(j, j + 1, suml[j + 1]);
            }
            rep(j, l[i]) {
                ans.add(w - 1 - j, w - j, sumr[j + 1]);
            }
            ans.add(l[i], w - l[i], suml[l[i]]);
        } else {
            rep(j, w - l[i]) {
                ans.add(j, j + 1, suml[j + 1]);
            }
            rep(j, w - l[i]) {
                ans.add(w - 1 - j, w - j, sumr[j + 1]);
            }
            // slide max
            deque<ll> deq;
            int len = w - l[i] + 1;
            rep(j, w - l[i]) {
                while(deq.size() and a[i][deq.back()] <= a[i][j]) deq.pop_back();
                deq.push_back(j);
            }
            for(int j = w - l[i]; j < l[i]; ++ j) {
                while(deq.size() and deq.front() <= j - len) deq.pop_front();
                while(deq.size() and a[i][deq.back()] <= a[i][j]) deq.pop_back();
                deq.push_back(j);
                ans.add(j, j + 1, a[i][deq.front()]);
            }
        }
    }
    rep(i, w) {
        cout << ans.sum(i, i + 1) << " \n"[i == w - 1];
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