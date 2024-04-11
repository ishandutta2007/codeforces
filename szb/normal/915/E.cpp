#include<bits/stdc++.h>
using namespace std; 
#define ll int
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define lf else if
#define fi first
#define se second
typedef complex<double> E;
namespace SHENZHEBEI{
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
const ll N=15000000;
ll ls[N],rs[N],sum[N],n,Q,cnt,tp[N],rt;
void pushdown(ll p,ll s,ll t){
	if (!ls[p])	ls[p]=++cnt;
	if (!rs[p])	rs[p]=++cnt;
	if (tp[p]){
		tp[ls[p]]=tp[p];
		tp[rs[p]]=tp[p];
		sum[ls[p]]=s*(tp[p]-1);
		sum[rs[p]]=t*(tp[p]-1);
		tp[p]=0;
	}
}
void cover(ll &p,ll l,ll r,ll s,ll t,ll opt){
	if (!p)	p=++cnt,sum[p]=0;
	if (l==s&&r==t){	sum[p]=(r-l+1)*opt;	tp[p]=opt+1;return;	}
	ll mid=(l+r)>>1;
	pushdown(p,mid-l+1,r-mid);
	if (t<=mid)	cover(ls[p],l,mid,s,t,opt);
	else if (s>mid)	cover(rs[p],mid+1,r,s,t,opt);
	else	cover(ls[p],l,mid,s,mid,opt),cover(rs[p],mid+1,r,mid+1,t,opt);
	sum[p]=sum[ls[p]]+sum[rs[p]];
}
	
int main(){
	n=read();
	Q=read();
	while(Q--){
		ll l=read(),r=read(),opt=2-read();
		cover(rt,1,n,l,r,opt);
		writeln(n-sum[rt]);
	}
}