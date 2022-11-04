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
const ll N=1000010;
struct zyy{ll m[4][2][2];zyy(){memset(m,0,sizeof m);}}f[500010];
int head[N],nxt[N],vet[N],n,tot;
void insert(ll x,ll y){nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;}
zyy merge(zyy a,zyy b){
	zyy c;
	For(aj,0,1)For(ak,0,1)For(bj,0,1-aj)For(bk,0,ak){
		c.m[0][aj+bj][ak^bk]+=a.m[0][aj][ak]*b.m[0][bj][bk];
		c.m[1][aj+bj][ak^bk]+=a.m[0][aj][ak]*b.m[1][bj][bk];
		c.m[1][aj+bj][ak^bk]+=a.m[1][aj][ak]*b.m[0][bj][bk];
		c.m[2][aj+bj][ak^bk]+=a.m[0][aj][ak]*b.m[2][bj][bk];
		c.m[2][aj+bj][ak^bk]+=a.m[2][aj][ak]*b.m[0][bj][bk];
		c.m[3][aj+bj][ak^bk]+=a.m[1][aj][ak]*b.m[1][bj][bk];
		c.m[3][aj+bj][ak^bk]+=a.m[2][aj][ak]*b.m[2][bj][bk];
		c.m[3][aj+bj][ak^bk]+=a.m[0][aj][ak]*b.m[3][bj][bk];
		c.m[3][aj+bj][ak^bk]+=a.m[3][aj][ak]*b.m[0][bj][bk];
	}return c;
}
void link(zyy &x){	x.m[0][0][1]=x.m[1][0][0]=x.m[2][0][1]=1;	}
void cut(zyy &x){
	x.m[1][1][0]+=x.m[1][0][0];
	x.m[2][1][0]+=x.m[2][0][0];
}
void Dfs (int x,int pre){
	link(f[x]);
	for(ll i=head[x];i;i=nxt[i])
	if (vet[i]^pre)	Dfs(vet[i],x),f[x]=merge(f[x],f[vet[i]]);
	cut(f[x]);
}
int main(){
	n=read();
	For(i,2,n){	ll x=read(),y=read();	insert(x,y);	insert(y,x);	}
	Dfs(1,0);writeln(f[1].m[3][1][0]);
}