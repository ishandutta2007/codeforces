#include "bits/stdc++.h"
using namespace std;
using namespace std::chrono;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
#define _overload4(_1,_2,_3,_4,name,...) name
#define _overload3(_1,_2,_3,name,...) name
#define _overload2(_1,_2,name,...) name
#define _re(n) _rep(i,n)
#define _rep(i,n) _repi(i,0,n)
#define _repi(i,a,b) for(ll i=a;i<b;++i)
#define _repc(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) _overload4(__VA_ARGS__,_repc,_repi,_rep,_re)(__VA_ARGS__)
#define _rre(n) _rrep(i,n)
#define _rrep(i,n) _rrepi(i,0,n)
#define _rrepi(i,a,b) for(ll i=b-1;i>=a;i--)
#define _rrepc(i,a,b,c) for(ll i=a+(b-a-1)/c*c;i>=a;i-=c)
#define rrep(...) _overload4(__VA_ARGS__,_rrepc,_rrepi,_rrep,_rre)(__VA_ARGS__)
#define rbr(i,a) for(auto&& i:a)
#define sum(...) accumulate(range(__VA_ARGS__),0)
#define _range(i) (i).begin(),(i).end()
#define _rangek(i,k) (i).begin(),(i).begin()+k
#define range(...) _overload2(__VA_ARGS__,_rangek,_range)(__VA_ARGS__)
#define LINF 0x3999999999999999LL
#define MOD ll(1000000007)
#define MODD ll(998244353)
#define INF 0x39999999
#define Yes(i) out(i?"Yes":"No")
#define YES(i) out(i?"YES":"NO")
#define elif else if
//#define START auto start=system_clock::now()
//#define END auto end=system_clock::now();cerr<<duration_cast<milliseconds>(end-start).count()<<" ms\n"
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define vec(type,name,size) vector<type> name(size);
#define VEC(type,name,size) vector<type> name(size);in(name)
#define v(name,size,value) vector<ll>name(size,value)
#define vv(type,name,h,w,value) vector<vector<type>>name(h,vector<type>(w,value))
struct aaa{aaa(){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(15);};}aaaaaaa;
template<typename T>
inline constexpr T gcd (T a,T b) {if(a==b)return a;else return gcd(b,(a-1)%b+1);}
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
template<typename T,typename L>
ostream& operator << (ostream& os, pair<T,L>& p){os << p.first << " " << p.second;return os;}
template <class Head, class... Tail>
inline void in(Head&& head,Tail&&... tail){cin>>head;in(move(tail)...);}
template <typename T>
inline void out(T t){cout<<t<<'\n';}
inline void out(){cout<<'\n';}
template <class Head, class... Tail>
inline void out(Head head,Tail... tail){cout<<head<<' ';out(move(tail)...);}




int main(){
    INT(n);
    VEC(int,a,n);
    sort(a.begin(), a.end());
    out(a.back()-a.front()-n+1);
}