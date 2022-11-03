#include<bits/stdc++.h>
using namespace std;
#define ll int
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define lf else if
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)      ((x)*(x))
#define abs(x)      ((x)>0?(x):-(x))
#define Mul(x,y)    ((x)=1LL*(x)*(y)%mod)
#define Add(x,y)    ((x)=((x)+(y))%mod)
#define Max(x,y)    ((x)=((x)<(y)?(y):(x)))
#define Min(x,y)    ((x)=((x)>(y)?(y):(x)))
#define E(x)        return writeln(x),0
#define p(x)        printf("~%d~\n",x)
#define pp(x,y)     printf("~~%d %d~~\n",x,y)
#define ppp(x,y,z)  printf("~~~%d %d %d~~~\n",x,y,z)
#define pppp(a,b,c,d)	printf("~~~%d %d %d %d\n",a,b,c,d)
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_;
#endif
#define NEG 1
    const ll L=2333333;
    inline char gc(){	return getchar();	}
#if NEG
    inline ll read(){    ll x=0,fa=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') fa=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*fa; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline ll readstr(char *s){ char ch=gc();   ll cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[++cur]=ch;    s[cur+1]='\0';    return cur; }
    inline void writeln(ll x){  write(x);   puts("");   }
}using namespace SHENZHEBEI;
const ll N=130000;
bool edge[27][27];
ll n,m,fa[100],num[100];
char s[N],t[N];
inline ll find(ll x){if(x==fa[x])return x;return fa[x]=find(fa[x]);}
int main(){
	//f_in("cf");
	n=readstr(s);m=readstr(t);
	rep(i,0,n-m+1){
		memset(edge,0,sizeof edge);
		For(j,1,m)edge[t[j]-'a'][s[i+j]-'a']=true;
		rep(j,0,26)fa[j]=j,num[j]=1;
		rep(j,0,26)rep(k,0,26)if(edge[j][k]){
			ll fj=find(j),fk=find(k);
			if(fj!=fk)fa[fj]=fk,num[fk]+=num[fj];
		}
		ll ans=0;
		rep(j,0,26)if(find(j)==j)ans+=num[j]-1;
		write(ans);putchar(' ');
	}
}