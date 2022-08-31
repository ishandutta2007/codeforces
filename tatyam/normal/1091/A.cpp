#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
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
#define _range(i) (i).begin(),(i).end()
#define _range2(i,k) (i).begin(),(i).begin()+k
#define _range3(i,a,b) (i).begin()+a,(i).begin()+b
#define range(...) _overload3(__VA_ARGS__,_range3,_range2,_range)(__VA_ARGS__)
const ll LINF=0x3fffffffffffffff;
const ll MOD=1000000007;
const ll MODD=0x3b800001;
const int INF=0x3fffffff;
const vector<pii> four={{0,1},{1,0},{0,-1},{-1,0}};
#define yes(i) out(i?"yes":"no")
#define Yes(i) out(i?"Yes":"No")
#define YES(i) out(i?"YES":"NO")
#define Possible(i)out(i?"Possible":"Impossible")
#define unless(a) if(!(a))
#define elif else if
//#define START auto start=system_clock::now()
//#define END auto end=system_clock::now();cerr<<duration_cast<milliseconds>(end-start).count()<<" ms\n"
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define vec(type,name,...) vector<type> name(__VA_ARGS__);
#define VEC(type,name,size) vector<type> name(size);in(name)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define pll pair<ll,ll>
struct SETTINGS{SETTINGS(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);};}SETTINGS;
template<typename T>
inline bool update_min(T& mn,const T& cnt){if(mn>cnt){mn=cnt;return 1;}else return 0;}
template<typename T>
inline bool update_max(T& mx,const T& cnt){if(mx<cnt){mx=cnt;return 1;}else return 0;}
template<typename T>
inline T min(vector<T>& vec){return *min_element(range(vec));}
template<typename T>
inline T max(vector<T>& vec){return *max_element(range(vec));}
template<typename T>
inline constexpr T gcd (T a,T b) {if(a==b)return a;else return gcd(b,(a-1)%b+1);}
inline constexpr ll POW(ll a,ll b){if(b==1)return a;ll ans=POW(a,b/2);ans*=ans;if(b&1)ans*=a;return ans;}
inline constexpr ll MODPOW(ll a,ll b,ll mod){if(a>=mod)a%=mod;if(b==1)return a;ll ans=MODPOW(a,b/2,mod);ans*=ans;ans%=mod;if(b&1){ans*=a;ans%=mod;}return ans;}
inline void in() {}
template<typename T>
istream& operator >> (istream& is, vector<T>& vec);
template<typename T,size_t size>
istream& operator >> (istream& is, array<T,size>& vec);
template<typename T,typename L>
istream& operator >> (istream& is, pair<T,L>& p);
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec);
template<typename T,typename L>
ostream& operator << (ostream& os, pair<T,L>& p);
template<typename T>
istream& operator >> (istream& is, vector<T>& vec){for(T& x: vec) is >> x;return is;}
template<typename T,typename L>
istream& operator >> (istream& is, pair<T,L>& p){is >> p.first;is >> p.second;return is;}
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec){os << vec[0];rep(i,1,vec.size()){os << ' ' << vec[i];}return os;}
template<typename T>
ostream& operator << (ostream& os, deque<T>& vec){os << vec[0];rep(i,1,vec.size()){os << ' ' << vec[i];}return os;}
template<typename T,typename L>
ostream& operator << (ostream& os, pair<T,L>& p){os << p.first << " " << p.second;return os;}
template <class Head, class... Tail>
inline void in(Head&& head,Tail&&... tail){cin>>head;in(move(tail)...);}
template <typename T>
inline void out(T t){cout<<t<<endl;}
inline void out(){cout<<'\n';}
template <class Head, class... Tail>
inline void out(Head head,Tail... tail){cout<<head<<' ';out(move(tail)...);}
inline void _in(int&a){scanf("%d",&a);}
inline void _in(ll&a){scanf("%lld",&a);}
inline void _in(char&a){scanf("%c",&a);}
inline void _in(string&a){cin>>a;}
template<class T>
inline void _in(vector<T>&a){each(i,a)_in(i);}
template<class T>
inline void _in(deque<T>&a){each(i,a)_in(i);}



signed main(){
    LL(a,b,c);
    a++;
    c--;
    out(min({a,b,c})*3);
}