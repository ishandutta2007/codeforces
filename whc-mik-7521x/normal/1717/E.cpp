#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
namespace Def{
#define ll long long
#define lll __int128
#define lb long double
#define D double
#define emb emplace_back
#define mkp make_pair
#define Array vector<int>
#define Pair pair<int,int>
#define fi first
#define se second
#define rep(variable,leftrange,rightrange) for(int variable=leftrange;variable<=rightrange;++variable)
#define Rep(variable,leftrange,rightrange) for(int variable=leftrange;variable>=rightrange;--variable)
#define Find(a,b) (lower_bound(a.begin(),a.end(),b)-a.begin())
#define Uniq(v) v.erase(unique(v.begin(),v.end()),v.end())
#define All(x) x.begin(),x.end()
#define nxtl puts("")
#define sq(x) ((x)*(x))
#define lowbit(x) ((x)& -(x))
#define IF(x,y,z) (x)&&(y)||(z)
#define If(x,y) (x)&&(y)
#define Hash __gnu_pbds::gp_hash_table
}
namespace LOCAL{
#ifdef DEBUG
#define react puts("reacting now !")
#define debug(x) cout << #x << " = " <<  x << "\n"; 
#define debug2(l,r) cout << "[" #l "," #r "] = [" << l << "," << r << "]\n" ;
#define debug3(x,y,z) cout << "{" #x "," #y "," #z "} = " << "{" << x << "," << y << "," << z << "}\n" ; 
#define debug_vec(v) cout << #v": size= " << v.size() << "\nelement: " ; for(auto p:v)  cout << p << " " ;
#define FileIO(x) 
#else 
#define react
#define debug(x) 
#define debug2(l,r)
#define debug3(x,y,z)
#define debug_vec(v)
#define FileIO(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#endif 
}
namespace IO {
#define MAXSIZE (1<<20)
char *IO_p1,*IO_p2,IO_buf[MAXSIZE];
#ifdef DEBUG
#define gchar() getchar()
#else
#define gchar() (IO_p1==IO_p2&&(IO_p2=(IO_p1=IO_buf)+fread(IO_buf,1,MAXSIZE,stdin),IO_p1==IO_p2)?EOF:*IO_p1++)
#endif
template<typename _Tp>inline void read(_Tp &x){
    x=0;char ch=gchar();
    for(;!isdigit(ch);ch=gchar());
    for(;isdigit(ch);ch=gchar())x=(x<<1)+(x<<3)+(ch^48);
}
template<typename _Tp>inline void nread(_Tp &x){
    x=0;_Tp f=1;char ch=gchar();
    for(;!isdigit(ch);ch=gchar())ch=='-'&&(f=-1);
    for(;isdigit(ch);ch=gchar())x=(x<<1)+(x<<3)+(ch^48);
    x*=f;
}
template<typename _Tp,typename ...Args>
inline void read(_Tp &x,Args &...args){read(x),read(args...);}
template<typename _Tp,typename ...Args>
inline void nread(_Tp &x,Args &...args){nread(x),nread(args...);}
template<typename _Tp>inline void wrt(_Tp x){
    if(x<0)x=-x,putchar('-');
    if(x>9)wrt(x/10);
    putchar(x%10+48);
}
inline void wrt(char ch){putchar(ch);}
template<typename _Tp,typename ...Args>
inline void wrt(_Tp x,Args ...args){wrt(x),wrt(args...);}
#undef MAXSIZE
}
namespace Fast{
    inline void Read(pair<int,int> &x) { IO::read(x.fi,x.se); }
    inline void Read(vector<int> &v,int n){v.resize(n);for(auto &p:v) IO::read(p);}
    inline void Wrt(pair<int,int> x,char c) { IO::wrt(x.fi,' ',x.se,c); }
    inline void Wrt(vector<int> v,char c){for(auto p:v) IO::wrt(p,c);}    
    template<typename _Tp>inline void Swap(_Tp &x,_Tp &y) {x^=y^=x^=y;}
    template<typename _Tp>inline _Tp Min(_Tp x,_Tp y){return x<y?x:y;}
    template<typename _Tp>inline _Tp Max(_Tp x,_Tp y){return x>y?x:y;}
    template<typename _Tp>inline void Add(_Tp &x,_Tp y,_Tp p){x+=y;if(x>=p)x-=p;}
    template<typename _Tp>inline void upmax(_Tp &x,_Tp y){if(y>x)x=y;} 
    template<typename _Tp>inline void upmin(_Tp &x,_Tp y){if(y<x)x=y;}
}
using namespace IO ;
using namespace Def ;
using namespace Fast ; 
using namespace LOCAL ;
const int N = 2e5 + 20  ;
const int mod = 1e9 + 7 ;
#define int long long
int n , k ;
int res = 0 ;
int cc[N] ; 
Array fc[N] ; 
#define gcd(x,y) __gcd(x,y)
int lcm(int x,int y) {
    return (x / gcd(x , y) * y);
}
signed main()
{
    read(n) ;
    for(int i = 1 ; i <= n ; ++ i) {
        for(int j = i ; j <= n ; j += i) fc[j].emplace_back(i) ;
    }
    cc[2] = 1 ;
    for(int i = 3 ; i <= n ; ++ i) {
        cc[i] = i - 1 ;
        cc[i] -= cc[i] & 1 ;
        for(int j:fc[i]) {
            if(j * 2 != i && j != 1 && j != i) {
                cc[i] -= cc[i / j] ;
            }
        }
        // debug2(i, cc[i]) ;
    }
    for(int g = 1 ; g < n ; ++ g) {
        for(int add = g << 1 ; add < n ; add += g) {
            (res += (cc[add / g]) * lcm(n - add , g)) %= mod; 
        }
    }
    wrt(res) ; 
    return 0;
}