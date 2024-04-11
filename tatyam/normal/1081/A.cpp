#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
using ll=long long;
using ull=unsigned long long;
using uint=unsigned int;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using pdd=pair<double,double>;
const ll LINF=0x3fffffffffffffff;
const ll MOD=1000000007;
const ll MODD=0x3b800001;
const int INF=0x3fffffff;
const double DINF=numeric_limits<double>::infinity();
const vector<pii> four={{-1,0},{0,1},{1,0},{0,-1}};
#define _overload4(_1,_2,_3,_4,name,...) name
#define _overload3(_1,_2,_3,name,...) name
#define _rep1(n) _rep2(i,n)
#define _rep2(i,n) _rep3(i,0,n)
#define _rep3(i,a,b) for(ll i=a;i<b;++i)
#define _rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) _overload4(__VA_ARGS__,_rep4,_rep3,_rep2,_rep1)(__VA_ARGS__)
#define _rrep1(n) _rrep2(i,n)
#define _rrep2(i,n) _rrep3(i,0,n)
#define _rrep3(i,a,b) for(ll i=b-1;i>=a;i--)
#define _rrep4(i,a,b,c) for(ll i=a+(b-a-1)/c*c;i>=a;i-=c)
#define rrep(...) _overload4(__VA_ARGS__,_rrep4,_rrep3,_rrep2,_rrep1)(__VA_ARGS__)
#define each(i,a) for(auto&& i:a)
#define sum(...) accumulate(range(__VA_ARGS__),0LL)
#define dsum(...) accumulate(range(__VA_ARGS__),double(0))
#define _range(i) (i).begin(),(i).end()
#define _range2(i,k) (i).begin(),(i).begin()+k
#define _range3(i,a,b) (i).begin()+a,(i).begin()+b
#define range(...) _overload3(__VA_ARGS__,_range3,_range2,_range)(__VA_ARGS__)
#define yes(i) out(i?"yes":"no")
#define Yes(i) out(i?"Yes":"No")
#define YES(i) out(i?"YES":"NO")
#define elif else if
#define unless(a) if(!(a))
#define mp make_pair
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size);in(name)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__));in(name)
__attribute__((constructor)) void SETTINGS(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(15);};
template<class T>
inline constexpr T gcd (T a,T b) {if(a==b)return a;else return gcd(b,(a-1)%b+1);}
template<class T>
inline constexpr T lcm (T a,T b) {a*b/gcd(a,b);}
template<class T>
inline constexpr T min(vector<T>& v){return *min_element(range(v));}
inline char min(string& v){return *min_element(range(v));}
template<class T>
inline constexpr T max(vector<T>& v){return *max_element(range(v));}
inline char max(string& v){return *max_element(range(v));}
template<typename T>
inline bool update_min(T& mn,const T& cnt){if(mn>cnt){mn=cnt;return 1;}else return 0;}
template<typename T>
inline bool update_max(T& mx,const T& cnt){if(mx<cnt){mx=cnt;return 1;}else return 0;}
inline void in() {}
template<class T>
istream& operator >> (istream& is, vector<T>& vec);
template<class T,size_t size>
istream& operator >> (istream& is, array<T,size>& vec);
template<class T,class L>
istream& operator >> (istream& is, pair<T,L>& p);
template<class T>
ostream& operator << (ostream& os, vector<T>& vec);
template<class T,class L>
ostream& operator << (ostream& os, pair<T,L>& p);
template<class T>
istream& operator >> (istream& is, vector<T>& vec){for(T& x: vec) is >> x;return is;}
template<class T,class L>
istream& operator >> (istream& is, pair<T,L>& p){is >> p.first;is >> p.second;return is;}
template<class T>
ostream& operator << (ostream& os, vector<T>& vec){os << vec[0];rep(i,1,vec.size()){os << ' ' << vec[i];}return os;}
template<class T>
ostream& operator << (ostream& os, deque<T>& deq){os << deq[0];rep(i,1,deq.size()){os << ' ' << deq[i];}return os;}
template<class T,class L>
ostream& operator << (ostream& os, pair<T,L>& p){os << p.first << " " << p.second;return os;}
template<class T,class L>
pair<T,L> operator + (pair<T,L> a, pair<T,L> b){return {a.first + b.first, a.second + b.second};}
template <class Head, class... Tail>
inline void in(Head&& head,Tail&&... tail){cin>>head;in(move(tail)...);}
template <class T>
inline bool out(T t){cout<<t<<'\n';return 0;}
inline bool out(){cout<<'\n';return 0;}
template <class Head, class... Tail>
inline bool out(Head head,Tail... tail){cout<<head<<' ';out(move(tail)...);return 0;}
template <class T>
inline void err(T t){cerr<<t<<'\n';}
inline void err(){cerr<<'\n';}
template <class Head, class... Tail>
inline void err(Head head,Tail... tail){cerr<<head<<' ';out(move(tail)...);}





signed main(){
    LL(n);
    out(1+(n==2));
}