#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned int;
using pcc = pair<char, char>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using tuplis = array<ll, 3>;
template<class T> using pq = priority_queue<T, vector<T>, greater<T>>;
const ll LINF=0x1fffffffffffffff;
const ll MINF=0x7fffffffffff;
const int INF=0x3fffffff;
const int MOD=1000000007;
const int MODD=998244353;
const ld DINF=numeric_limits<ld>::infinity();
const ld EPS=1e-9;
const ld PI=3.1415926535897932;
const ll dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const ll dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
#define overload4(_1,_2,_3,_4,name,...) name
#define overload3(_1,_2,_3,name,...) name
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep1(n) for(ll i=(n)-1;i>=0;i--)
#define rrep2(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep3(i,a,b) for(ll i=(b)-1;i>=(a);i--)
#define rrep4(i,a,b,c) for(ll i=a+(b-a-1)/c*c;i>=a;i-=c)
#define rrep(...) overload4(__VA_ARGS__,rrep4,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define each(i,...) for(auto&& i:__VA_ARGS__)
#define all1(i) begin(i),end(i)
#define all2(i,a) begin(i),begin(i)+a
#define all3(i,a,b) begin(i)+a,begin(i)+b
#define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)
#define rall1(i) (i).rbegin(),(i).rend()
#define rall2(i,k) (i).rbegin(),(i).rbegin()+k
#define rall3(i,a,b) (i).rbegin()+a,(i).rbegin()+b
#define rall(...) overload3(__VA_ARGS__,rall3,rall2,rall1)(__VA_ARGS__)
#define sum(...) accumulate(all(__VA_ARGS__),0LL)
#define dsum(...) accumulate(all(__VA_ARGS__),0.0L)
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
#define Sort(a) sort(all(a))
#define Rev(a) reverse(all(a))
#define Uniq(a) sort(all(a));a.erase(unique(all(a)),end(a))
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size);in(name)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));in(name)
#define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
template<class T> inline auto max(const T& a){ return *max_element(all(a)); }
template<class T> inline auto min(const T& a){ return *min_element(all(a)); }
inline ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
inline ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
inline constexpr ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
inline ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
template<class T, class U> inline bool chmin(T& a, const U& b){ if(a > b){ a = b; return 1; } return 0; }
template<class T, class U> inline bool chmax(T& a, const U& b){ if(a < b){ a = b; return 1; } return 0; }
inline vector<pll> factor(ull x){ vector<pll> ans; for(ll i = 2; i * i <= x; i++) if(x % i == 0){ ans.push_back({i, 1}); while((x /= i) % i == 0) ans.back().second++; } if(x != 1) ans.push_back({x, 1}); return ans; }
inline vector<ll> divisor(ull x){ vector<ll> ans; for(ll i = 1; i * i <= x; i++) if(x % i == 0) ans.push_back(i); rrep(ans.size() - (ans.back() * ans.back() == x)) ans.push_back(x / ans[i]); return ans; }
template<class T> inline unordered_map<T, ll> press(vector<T>& a){ auto b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); unordered_map<T,ll> ans; rep(b.size()) ans[b[i]] = i; each(i, a) i = ans[i]; return ans; }
template<class T> inline map<T, ll> press_map(vector<T>& a){ auto b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); map<T,ll> ans; rep(b.size()) ans[b[i]] = i; each(i, a) i = ans[i]; return ans; }
inline int scan(){ return getchar(); }
inline void scan(int& a){ scanf("%d", &a); }
inline void scan(unsigned& a){ scanf("%u", &a); }
inline void scan(long& a){ scanf("%ld", &a); }
inline void scan(long long& a){ scanf("%lld", &a); }
inline void scan(unsigned long long& a){ scanf("%llu", &a); }
inline void scan(char& a){ do{ a = getchar(); }while(a == ' ' || a == '\n'); }
inline void scan(float& a){ scanf("%f", &a); }
inline void scan(double& a){ scanf("%lf", &a); }
inline void scan(long double& a){ scanf("%Lf", &a); }
inline void scan(vector<bool>& a){ for(unsigned i = 0; i < a.size(); i++){ int b; scan(b); a[i] = b; } }
inline void scan(char a[]){ scanf("%s", a); }
inline void scan(string& a){ cin >> a; }
template<class T> inline void scan(vector<T>&);
template<class T, size_t size> inline void scan(array<T, size>&);
template<class T, class L> inline void scan(pair<T, L>&);
template<class T, size_t size> inline void scan(T(&)[size]);
template<class T> inline void scan(vector<T>& a){ for(auto&& i : a) scan(i); }
template<class T> inline void scan(deque<T>& a){ for(auto&& i : a) scan(i); }
template<class T, size_t size> inline void scan(array<T, size>& a){ for(auto&& i : a) scan(i); }
template<class T, class L> inline void scan(pair<T, L>& p){ scan(p.first); scan(p.second); }
template<class T, size_t size> inline void scan(T (&a)[size]){ for(auto&& i : a) scan(i); }
template<class T> inline void scan(T& a){ cin >> a; }
inline void in(){}
template <class Head, class... Tail> inline void in(Head& head, Tail&... tail){ scan(head); in(tail...); }
inline void print(){ putchar(' '); }
inline void print(bool a){ printf("%d", a); }
inline void print(int a){ printf("%d", a); }
inline void print(unsigned a){ printf("%u", a); }
inline void print(long a){ printf("%ld", a); }
inline void print(long long a){ printf("%lld", a); }
inline void print(unsigned long long a){ printf("%llu", a); }
inline void print(char a){ printf("%c", a); }
inline void print(char a[]){ printf("%s", a); }
inline void print(const char a[]){ printf("%s", a); }
inline void print(float a){ printf("%.15f", a); }
inline void print(double a){ printf("%.15f", a); }
inline void print(long double a){ printf("%.15Lf", a); }
inline void print(const string& a){ for(auto&& i : a) print(i); }
template<class T> inline void print(const vector<T>&);
template<class T, size_t size> inline void print(const array<T, size>&);
template<class T, class L> inline void print(const pair<T, L>& p);
template<class T, size_t size> inline void print(const T (&)[size]);
template<class T> inline void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T> inline void print(const deque<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T, size_t size> inline void print(const array<T, size>& a){ print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T, class L> inline void print(const pair<T, L>& p){ print(p.first); putchar(' '); print(p.second); }
template<class T, size_t size> inline void print(const T (&a)[size]){ print(a[0]); for(auto i = a; ++i != end(a); ){ putchar(' '); print(*i); } }
template<class T> inline void print(const T& a){ cout << a; }
inline int out(){ putchar('\n'); return 0; }
template<class T> inline int out(const T& t){ print(t); putchar('\n'); return 0; }
template<class Head, class... Tail> inline int out(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }
#ifdef DEBUG
void err(){ putchar('\n'); }
template<class T> void err(const T& t){ print(t); putchar('\n'); }
template<class Head, class... Tail> void err(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); }

#else
template<class... T> void err(const T&...){}
#endif
int first(bool i = true){ return out(i?"first":"second"); }
int yes(bool i = true){ return out(i?"yes":"no"); }
int Yes(bool i = true){ return out(i?"Yes":"No"); }
int No(){ return out("No"); }
int YES(bool i = true){ return out(i?"YES":"NO"); }
int NO(){ return out("NO"); }
int Yay(bool i = true){ return out(i?"Yay!":":("); }
int possible(bool i = true){ return out(i?"possible":"impossible"); }
int Possible(bool i = true){ return out(i?"Possible":"Impossible"); }
int POSSIBLE(bool i = true){ return out(i?"POSSIBLE":"IMPOSSIBLE"); }
void Case(ll i){ printf("Case #%lld: ", i); }



void solve(){
    ll ans=LINF;
    LL(n);
    VEC(ll,a,n);
    VEC(ll,c,n);
    each(i,a)i--;
    vec(bool,used,n);
    rep(n)if(!used[i]){
        vector<ll>b;
        ll at=i;
        while(!used[at]){
            used[at]=1;
            b.push_back(c[at]);
            at=a[at];
        }
        each(i,divisor(b.size())){
            if(ans<i)break;
            rep(s,i){
                ll cc=b[s];
                bool flag=1;
                rep(j,s+i,b.size(),i)if(b[j]!=cc){
                    flag=0;
                    break;
                }
                if(flag){
                    chmin(ans,i);
                    break;
                }
            }
        }
    }
    out(ans);
}
signed main(){
    LL(t);
    rep(t)solve();
}