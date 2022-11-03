#include<bits/stdc++.h>
using namespace std; 
#define ll unsigned long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define fi first
#define se second
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))    
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
	struct _{_(){freopen("cf.in","r",stdin);}}_;
#endif 
#define NEG 0
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
map<ll,ll>mp0,mp1;
ll now;
const ll N=200010;	ll a[N],b[N],c[N],n,m,sum[N],ans,has[N];
ll calc(ll x){  return (x+1)*x*x/2-(x-1)*x/2-x*(x-1)*(2*x-1)/6;	}
int main(){
	srand(21312321);	n=read();	m=read();
	For(i,1,n){ll l=read(),r=read(),now=1;	now=(((now*rand()<<16|rand())<<16|rand())<<16|rand()),a[l]^=now,a[r+1]^=now,sum[l]++,sum[r+1]--,b[l]^=now,c[r]^=now;}
	For(i,1,m)	a[i]^=a[i-1],sum[i]+=sum[i-1];
	For(i,1,m)	a[i]^=a[i-1],b[i]^=b[i-1],c[i]^=c[i-1];
	For(i,0,m)	ans+=mp1[b[i]^a[i]]*i-mp0[b[i]^a[i]],mp1[a[i]^c[i]]++,mp0[a[i]^c[i]]+=i;
	for(ll i=1,j;i<=m;i=j+1){	j=i;	if (sum[i])	continue;	while(!sum[j+1]&&j<m)	++j;	ans-=calc(j-i+1);	}
	writeln(ans);
}