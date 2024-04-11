#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using ull=unsigned long long;
using uint=unsigned int;
using pcc=pair<char,char>;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using pdd=pair<double,double>;
using tuplis=pair<ll,pll>;
using tuplis2=pair<pll,ll>;
template<class T> using pq=priority_queue<T,vector<T>,greater<T>>;
const ll LINF=0x1fffffffffffffff;
const ll MINF=0x7fffffffffff;
const int INF=0x3fffffff;
const ll MOD=1000000007;
const ll MODD=998244353;
const ld DINF=numeric_limits<ld>::infinity();
const ld EPS=1e-9;
const ld PI=3.141592653589793238462643383279;
const vector<ll>four{0,1,0,-1,0};
#define _overload4(_1,_2,_3,_4,name,...) name
#define _overload3(_1,_2,_3,name,...) name
#define _rep1(n) for(int i=0;i<n;++i)
#define _rep2(i,n) for(int i=0;i<n;++i)
#define _rep3(i,a,b) for(int i=a;i<b;++i)
#define _rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) _overload4(__VA_ARGS__,_rep4,_rep3,_rep2,_rep1)(__VA_ARGS__)
#define _rrep1(n) for(ll i=(n)-1;i>=0;i--)
#define _rrep2(i,n) for(ll i=(n)-1;i>=0;i--)
#define _rrep3(i,a,b) for(ll i=(b)-1;i>=(a);i--)
#define _rrep4(i,a,b,c) for(ll i=a+(b-a-1)/c*c;i>=a;i-=c)
#define rrep(...) _overload4(__VA_ARGS__,_rrep4,_rrep3,_rrep2,_rrep1)(__VA_ARGS__)
#define each(i,a) for(auto &i:a)
#define sum(...) accumulate(range(__VA_ARGS__),0LL)
#define dsum(...) accumulate(range(__VA_ARGS__),double(0))
#define _range(i) (i).begin(),(i).end()
#define _range2(i,k) (i).begin(),(i).begin()+k
#define _range3(i,a,b) (i).begin()+a,(i).begin()+b
#define range(...) _overload3(__VA_ARGS__,_range3,_range2,_range)(__VA_ARGS__)
#define _rrange(i) (i).rbegin(),(i).rend()
#define _rrange2(i,k) (i).rbegin(),(i).rbegin()+k
#define _rrange3(i,a,b) (i).rbegin()+a,(i).rbegin()+b
#define rrange(...) _overload3(__VA_ARGS__,_rrange3,_rrange2,_rrange)(__VA_ARGS__)
#define elif else if
#define unless(a) if(!(a))
#define mp make_pair
#define mt make_tuple
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size);in(name)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__));in(name)
#define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
inline ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
inline ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
template<class T> inline T min(const vector<T> &v){ return *min_element(range(v)); }
inline char min(const string &v){ return *min_element(range(v)); }
template<class T> inline T max(const vector<T> &v){ return *max_element(range(v)); }
inline char max(const string &v){ return *max_element(range(v)); }
inline ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
inline ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return 1; } return 0; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } return 0; }
map<ll, ll> factor(ull x){ map<ll, ll> ans; for(ll i = 2; i * i <= x; i++) while(x % i == 0){ ans[i]++; x /= i; } if(x != 1) ans[x]++; return ans; }
set<ll> divisor(ull x){ set<ll> ans; for(ll i = 1; i * i <= x; i++) if(x % i == 0){ ans.insert(i); ans.insert(x / i); } return ans; }
template<class T> unordered_map<T, ll> press(vector<T> &a){ auto b = a; sort(range(b)); b.erase(unique(range(b)), b.end()); unordered_map<T,ll> ans; rep(b.size()) ans[b[i]] = i; each(i, a) i = ans[i]; return ans; }
template<class T> map<T, ll> press_map(vector<T> &a){ auto b = a; sort(range(b)); b.erase(unique(range(b)), b.end()); map<T,ll> ans; rep(b.size()) ans[b[i]] = i; each(i, a) i = ans[i]; return ans; }
inline int scan(){ return getchar(); }
inline void scan(int &a){ scanf("%d", &a); }
inline void scan(unsigned &a){ scanf("%u", &a); }
inline void scan(long &a){ scanf("%ld", &a); }
inline void scan(long long &a){ scanf("%lld", &a); }
inline void scan(unsigned long long &a){ scanf("%llu", &a); }
inline void scan(char &a){ cin >> a; }
inline void scan(float &a){ scanf("%f", &a); }
inline void scan(double &a){ scanf("%lf", &a); }
inline void scan(long double &a){ scanf("%Lf", &a); }
inline void scan(vector<bool> &vec){ for(unsigned i = 0; i < vec.size(); i++) { int a; scan(a); vec[i] = a; } }
inline void scan(char a[]){ scanf("%s", a); }
inline void scan(string &a){ cin >> a; }
template<class T> inline void scan(vector<T> &vec);
template<class T, size_t size> inline void scan(array<T, size> &vec);
template<class T, class L> inline void scan(pair<T, L> &p);
template<class T, size_t size> inline void scan(T (&vec)[size]);
template<class T> inline void scan(vector<T> &vec){ for(auto &i : vec) scan(i); }
template<class T> inline void scan(deque<T> &vec){ for(auto &i : vec) scan(i); }
template<class T, size_t size> inline void scan(array<T, size> &vec){ for(auto &i : vec) scan(i); }
template<class T, class L> inline void scan(pair<T, L> &p){ scan(p.first); scan(p.second); }
template<class T, size_t size> inline void scan(T (&vec)[size]){ for(auto &i : vec) scan(i); }
template<class T> inline void scan(T &a){ cin >> a; }
inline void in(){}
template <class Head, class... Tail> inline void in(Head &head, Tail&... tail){ scan(head); in(tail...); }
inline void print(){ putchar(' '); }
inline void print(const bool &a){ printf("%d", a); }
inline void print(const int &a){ printf("%d", a); }
inline void print(const unsigned &a){ printf("%u", a); }
inline void print(const long &a){ printf("%ld", a); }
inline void print(const long long &a){ printf("%lld", a); }
inline void print(const unsigned long long &a){ printf("%llu", a); }
inline void print(const char &a){ printf("%c", a); }
inline void print(const char a[]){ printf("%s", a); }
inline void print(const float &a){ printf("%.15f", a); }
inline void print(const double &a){ printf("%.15f", a); }
inline void print(const long double &a){ printf("%.15Lf", a); }
inline void print(const string &a){ for(auto&& i : a) print(i); }
template<class T> inline void print(const vector<T> &vec);
template<class T, size_t size> inline void print(const array<T, size> &vec);
template<class T, class L> inline void print(const pair<T, L> &p);
template<class T, size_t size> inline void print(const T (&vec)[size]);
template<class T> inline void print(const vector<T> &vec){ if(vec.empty()) return; print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar(' '); print(*i); } }
template<class T> inline void print(const deque<T> &vec){ if(vec.empty()) return; print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar(' '); print(*i); } }
template<class T, size_t size> inline void print(const array<T, size> &vec){ print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar(' '); print(*i); } }
template<class T, class L> inline void print(const pair<T, L> &p){ print(p.first); putchar(' '); print(p.second); }
template<class T, size_t size> inline void print(const T (&vec)[size]){ print(vec[0]); for(auto i = vec; ++i != end(vec); ){ putchar(' '); print(*i); } }
template<class T> inline void print(const T &a){ cout << a; }
inline int out(){ putchar('\n'); return 0; }
template<class T> inline int out(const T &t){ print(t); putchar('\n'); return 0; }
template<class Head, class... Tail> inline int out(const Head &head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }
#ifdef DEBUG
inline void err(){ putchar('\n'); }
template<class T> inline void err(const T &t){ print(t); putchar('\n'); }
template<class Head, class... Tail> inline void err(const Head &head, const Tail&... tail){ print(head); putchar(' '); out(tail...); }
#else
template<class... T> inline void err(const T&...){}
#endif
inline int first(bool i = true){ return out(i?"first":"second"); }
inline int yes(bool i = true){ return out(i?"yes":"no"); }
inline int Yes(bool i = true){ return out(i?"Yes":"No"); }
inline int No(){ return out("No"); }
inline int YES(bool i = true){ return out(i?"YES":"NO"); }
inline int NO(){ return out("NO"); }
inline int Yay(bool i = true){ return out(i?"Yay!":":("); }
inline int possible(bool i = true){ return out(i?"possible":"impossible"); }
inline int Possible(bool i = true){ return out(i?"Possible":"Impossible"); }
inline int POSSIBLE(bool i = true){ return out(i?"POSSIBLE":"IMPOSSIBLE"); }
inline void Case(ll i){ printf("Case #%lld: ", i); }



signed main(){
    LL(n);
    rep(n){
        LL(a,b);
        ll ans=0;
        while(a){
            ll c=b/a;
            ans+=c*c;
            b-=c;
            a--;
        }
        out(ans);
    }
}