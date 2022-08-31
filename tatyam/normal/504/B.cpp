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
#define _rrep3(i,a,b) for(ll i=(b)-1;i>=a;i--)
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
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size);in(name)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__));in(name)
#define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
inline constexpr ll gcd(ll a,ll b){if(!a||!b)return 0;while(b){ll c=b;b=a%b;a=c;}return a;}
inline constexpr ll lcm(ll a,ll b){if(!a||!b)return 0;return a*b/gcd(a,b);}
template<class T> inline constexpr T min(vector<T> &v){return *min_element(range(v));}
inline char min(string &v){return *min_element(range(v));}
template<class T> inline constexpr T max(vector<T> &v){return *max_element(range(v));}
inline char max(string &v){return *max_element(range(v));}
inline constexpr ll intpow(ll a,ll b){ll ans=1;for(ll i=1;b;i*=2){if(b&i){b^=i;ans*=a;}a*=a;}return ans;}
template<typename T>
inline constexpr bool chmin(T &mn,const T &cnt){if(mn>cnt){mn=cnt;return 1;}else return 0;}
template<typename T>
inline constexpr bool chmax(T &mx,const T &cnt){if(mx<cnt){mx=cnt;return 1;}else return 0;}
template<class T> unordered_map<T,ll> press(vector<T> &a){ auto b = a; sort(range(b)); b.erase(unique(range(b)), b.end()); unordered_map<T,ll> ans; rep(b.size()) ans[b[i]] = i; each(i, a) i = ans[i]; return ans; }
template<class T> map<T,ll> press_map(vector<T> &a){ auto b = a; sort(range(b)); b.erase(unique(range(b)), b.end()); map<T,ll> ans; rep(b.size()) ans[b[i]] = i; each(i, a) i = ans[i]; return ans; }
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
inline void scan(string &a){ cin >> a; }
template<class T> inline void scan(vector<T> &vec);
template<class T, size_t size> inline void scan(array<T, size> &vec);
template<class T, class L> inline void scan(pair<T, L> &p);
template<class T, size_t size> inline void scan(T (&vec)[size]);
template<class T> inline void scan(vector<T> &vec){ for(auto &i : vec) scan(i); }
template<class T, size_t size> inline void scan(array<T, size> &vec){ for(auto &i : vec) scan(i); }
template<class T, class L> inline void scan(pair<T, L> &p){ scan(p.first); scan(p.second); }
template<class T, size_t size> inline void scan(T (&vec)[size]){ for(auto &i : vec) scan(i); }
template<class T> inline void scan(T &a){ cin>>a; }
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
inline void print(const float &a){ printf("%.10f", a); }
inline void print(const double &a){ printf("%.10f", a); }
inline void print(const long double &a){ printf("%.10Lf", a); }
template<class T> void print(const vector<T> &vec);
template<class T, size_t size> void print(const array<T, size> &vec);
template<class T, class L> void print(const pair<T, L> &p);
template<class T, size_t size> inline void print(const T (&vec)[size]);
template<class T> void print(const vector<T> &vec){ if(vec.empty()) return; print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar(' '); print(*i); } }
template<class T, size_t size> void print(const array<T, size> &vec){ print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar(' '); print(*i); } }
template<class T, class L> void print(const pair<T, L> &p){ print(p.first); putchar(' '); print(p.second); }
template<class T, size_t size> inline void print(const T (&vec)[size]){ print(vec[0]); for(auto i = vec; ++i != end(vec); ){ putchar(' '); print(*i); } }
template<class T> inline void print(const T &a){ cout << a; }
inline int out(){ putchar('\n'); return 0; }
template<class T> inline int out(const T &t){ print(t); putchar('\n'); return 0; }
template<class Head, class... Tail> inline int out(const Head &head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }
template <class T> inline void err(T t){cerr<<t<<'\n';}
inline void err(){cerr<<'\n';}
inline int first(const bool &i){return out(i?"first":"second");}
inline int yes(const bool &i){return out(i?"yes":"no");}
inline int Yes(const bool &i){return out(i?"Yes":"No");}
inline int YES(const bool &i){return out(i?"YES":"NO");}
inline int Yay(const bool &i){return out(i?"Yay!":":(");}
inline int Possible(const bool &i){return out(i?"Possible":"Impossible");}
inline int POSSIBLE(const bool &i){return out(i?"POSSIBLE":"IMPOSSIBLE");}
inline void Case(ll i){printf("Case #%lld: ",i);}


template<class T>
struct SegmentTree{
    using F = function<T(T, T)>;
    ll size = 1;
    vector<T> data;
    const F f;
    const T def_value;
    SegmentTree(ll n, const T& def_value, const F& f): f(f), def_value(def_value){
        while(size < n) size *= 2;
        data.assign(size * 2, def_value);
    }
    SegmentTree(const vector<T>& v, const T& def_value, const F& f): f(f), def_value(def_value){
        while(size < data.size()) size *= 2;
        data.assign(size * 2, def_value);
        for(ll i = 0; i < v.size(); i++) data[size + i] = v[i];
        for(ll i = size; --i;) data[i] = f(data[i * 2], data[i * 2 + 1]);
    }
    T operator[](ll at) const {
        return data[size + at];
    }
    void update(ll at){
        while(at /= 2) data[at] = f(data[at * 2], data[at * 2 + 1]);
    }
    void set(ll at, const T& val){
        at += size;
        data[at] = val;
        update(at);
    }
    void add(ll at, const T& val){
        at += size;
        data[at] += val;
        update(at);
    }
    T get(ll l, ll r){
        T L = def_value, R = def_value;
        l += size; r += size;
        for(; l < r; l /= 2, r /= 2){
            if(l & 1) L = f(L, data[l++]);
            if(r & 1) R = f(data[--r], R);
        }
        return f(L, R);
    }
};
template<class T>
struct SegmentTree_Min : SegmentTree<T>{
    SegmentTree_Min(ll n, const T& def_value) : SegmentTree<T>(n, def_value, [](T a, T b){return min(a, b);}){}
    SegmentTree_Min(const vector<T>& v, const T& def_value) : SegmentTree<T>(v, def_value, [](T a, T b){return min(a, b);}){}
};
template<class T>
struct SegmentTree_Max : SegmentTree<T>{
    SegmentTree_Max(ll n, const T& def_value) : SegmentTree<T>(n, def_value, [](T a, T b){return max(a, b);}){}
    SegmentTree_Max(const vector<T>& v, const T& def_value) : SegmentTree<T>(v, def_value, [](T a, T b){return max(a, b);}){}
};
template<class T>
struct SegmentTree_Sum : SegmentTree<T>{
    SegmentTree_Sum(ll n, const T& def_value = T()) : SegmentTree<T>(n, def_value, [](T a, T b){return a + b;}){}
    SegmentTree_Sum(const vector<T>& v, const T& def_value = T()) : SegmentTree<T>(v, def_value, [](T a, T b){return a + b;}){}
};
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using gpp_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class L> using gpp_map = tree<T, L, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
signed main(){
    LL(n);
    VEC(ll,a,n);
    VEC(ll,b,n);
    SegmentTree_Sum<ll> seg(n), seg2(n);
    vector<ll>ans(n);
    rrep(n){
        ans[i]+=seg.get(0,a[i]);
        seg.set(a[i],1);
        ans[i]+=seg2.get(0,b[i]);
        seg2.set(b[i],1);
    }
    rrep(n){
        if(ans[i]>=n-i){
            ans[i]-=n-i;
            if(i>0)ans[i-1]++;
        }
    }
    gpp_set<ll> s;
    rep(n)s.insert(i);
    rep(n){
        auto p=s.find_by_order(ans[i]);
        ans[i]=*p;
        s.erase(p);
    }
    out(ans);
}