#include<bits/stdc++.h>
using namespace std; 
#define ll int
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
#define EXIT(x)	return writeln(x),0;
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
	struct _{_(){freopen("cf.in","r",stdin);}}_;
#endif 
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
const ll N=400010;
ll vis[N],dfn[N],head[N],nxt[N],vet[N],lnk[N],a[N],b[N],c[N],n,m,cnt,tot=1;
void insert(ll x,ll y){nxt[++tot]=head[x];head[x]=tot;vet[tot]=y;}
void add(ll x,ll y){	if (lnk[x])	a[++cnt]=lnk[x],b[cnt]=x,c[cnt]=y,lnk[x]=0;	else	lnk[x]=y;	}
void dfs(ll x,ll pre){
	dfn[x]=1;
	for(ll i=head[x];i;i=nxt[i])if(!vis[i>>1])	vis[i>>1]=1,dfn[vet[i]]?add(x,vet[i])/**/:dfs(vet[i],x)/**/;
	if (pre)	lnk[x]?add(x,pre)/*,*/:add(pre,x)/*, */;
}
int main(){
	n=read();m=read();
	For(i,1,m){	ll x=read(),y=read();insert(x,y);insert(y,x);	}
	For(i,1,n)if (!dfn[i])dfs(i,0);
	writeln(cnt);For(i,1,cnt)printf("%d %d %d\n",a[i],b[i],c[i]);
}