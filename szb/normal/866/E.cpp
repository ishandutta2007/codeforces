#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
#define fi first
#define se second
typedef complex<double> E;
namespace SHENZHEBEI{
#define NEG 1
    const int L=2333333;
    char SZB[L],*S=SZB,*T=SZB;
    inline char gc(){   if (S==T){  T=(S=SZB)+fread(SZB,1,L,stdin); if (S==T) return '\n';  }   return *S++;    }
#if NEG
    inline ll read(){    ll x=0,f=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') f=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*f; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline ll readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
    inline void writeln(ll x){  write(x);   puts("");   }
}using namespace SHENZHEBEI;
const ll inf=4e18;
ll all,f[1<<14|111],zyy[1<<14|111],sum[1<<14|111],answ=inf,n,vis[100],jinwei[100],A[100],a[100];char s[100];
ll get(char ch){return ch>='0'&&ch<='9'?(ch-'0'):(ch-'a'+10);}
char Get(ll x){return x>=0&&x<=9?(x+'0'):(x+'a'-10);}
void Print(ll S){FOr(i,n,1)putchar(Get((S>>(i-1)*4)&15));}
void Work(){
	memset(sum,0,sizeof sum);all=(1<<n)-1;
	For(i,0,all)f[i]=inf;f[0]=0;
	For(i,1,all)sum[i]=sum[i-(i&-i)]+A[n-zyy[i&-i]];
	For(i,0,all)if (f[i]<inf&&sum[i]>=0&&sum[i]<=15)rep(j,0,n)if (!(i>>j&1))Min(f[i^(1LL<<j)],f[i]|(sum[i]<<(4*j)));
	Min(answ,f[all]);
}
void dfs(ll x){
	if (x>n){ll sum=0;For(i,1,n)sum+=A[i];if (sum)return;Work();return;}
	dfs(x+1);
	if (x>1){A[x]-=16;A[x-1]++;dfs(x+1);A[x]+=16;A[x-1]--;}
}
int main(){
//	freopen("hex.in","r",stdin);
//	freopen("hex.out","w",stdout);
	scanf("%s",s+1);n=strlen(s+1);
	For(i,1,n)A[i]=get(s[i]);
	For(i,0,n)zyy[1<<i]=i;
	dfs(1);
	if (answ==inf)puts("NO");else Print(answ);
}