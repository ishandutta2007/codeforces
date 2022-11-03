#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define fi first
#define se second
#define lf else if
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
const ll N=1000010;
struct data{	ll nxt,w;	}a[N];
ll f[N],dep[N],head[N],nxt[N],vet[N],n,tot,rt,cnt;
vector<ll>g[N];
void insert(ll x,ll y){	nxt[++tot]=head[x];head[x]=tot;vet[tot]=y;}
void get_dep(ll x){	for(ll i=head[x];i;i=nxt[i])	dep[vet[i]]=dep[x]+1,get_dep(vet[i]);	}
void dfs(ll x){
	for(ll i=head[x];i;i=nxt[i]){
		ll y=vet[i];	dfs(y);
		if (!a[x].nxt){	a[x].nxt=y;continue;	}//
		ll z=a[x].nxt;//
		for(;y;y=a[y].nxt,z=a[z].nxt){
			g[cnt].push_back(a[y].w);
			g[cnt].push_back(a[z].w);
			f[cnt]=f[a[y].w]+f[a[z].w];
			dep[cnt]=dep[x];
			a[z].w=cnt++;// 
			if (!a[z].nxt){	a[z].nxt=a[y].nxt;	break;	}
		}
	}
}
void DFS(ll x){	rep(i,0,g[x].size())	f[g[x][i]]=f[x]+(dep[g[x][i]]-dep[x])*f[g[x][i]],DFS(g[x][i]);	}
void Dfs(ll x){	for(ll i=head[x];i;i=nxt[i])	f[vet[i]]+=f[x],Dfs(vet[i]);	}
int main(){
	n=read();	cnt=n+1;
	For(i,1,n){	ll fa=read();	if (fa)	insert(fa,i);	else	rt=i;	}
	dep[rt]=1;	get_dep(rt);
	For(i,1,n)	a[i].w=i,f[i]=1;
	dfs(rt);
	for(ll i=rt;i;i=a[i].nxt){	ll x=a[i].w;	f[x]=dep[x]*f[x];	DFS(x);	}//, 
	Dfs(rt);
	For(i,1,n)	printf("%I64d ",f[i]-dep[i]);	puts("");
}