#include<vector>
#include<cstdio> 
#include<cstring> 
#include<map>
#include<cmath> 
#include<algorithm>
#include<bitset>
#include<ctime> 
using namespace std; 
#define ll int
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
ll read(){  ll x=0,f=1; char ch=getchar();  for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-')    f=-1;   for(;ch>='0'&&ch<='9';ch=getchar())   x=x*10+ch-'0';  return x*f; } 
void write(ll x){   if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  } 
void writeln(ll x){ write(x);   puts("");   }
const ll N=1010,mod=1e9+7;
ll f[N][1<<12];
struct tr{
	ll c[N][N],head[N],nxt[N*2],vet[N*2],sz[N],son[N],hsh[N],n,tot;
	void insert(ll x,ll y){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	}
	void init(){	n=read();	For(i,2,n){	ll x=read(),y=read();	insert(x,y);	insert(y,x);	}	}
	void dfs(ll x,ll pre){	son[x]=hsh[x]=0;	for(ll i=head[x];i;i=nxt[i])	if (vet[i]^pre)	dfs(c[x][son[x]++]=vet[i],x),hsh[x]|=1<<vet[i]-1;	}
}a,b;
ll dfs(ll s,ll t,ll v){
	if (!t)	return !v;
	ll &ans=f[a.c[s][t-1]][v];
	if (ans)	return ans-1;
	ans=dfs(s,t-1,v);
	for(ll to=a.c[s][t-1],k=0;k<b.n;k++)	if (v>>k&1)	ans=(ans+1LL*dfs(s,t-1,v^(1<<k))*dfs(to,a.son[to],b.hsh[k+1]))%mod;
	return ans++;
}
ll Inv(ll x){
	return x==1?1:(1LL*Inv(mod%x)*(mod-mod/x))%mod;
}	
int main(){
	a.init();	b.init();	a.dfs(1,0);	ll ans=0;
	For(i,1,b.n){
		b.dfs(i,0);
		For(j,1,a.n)	ans=(ans+dfs(j,a.son[j],b.hsh[i]))%mod;
		memset(f,0,sizeof f);
	}a=b;	a.dfs(1,0);
	ll ANS=0;
	For(i,1,b.n){
		b.dfs(i,0);	For(j,1,a.n)	ANS=(ANS+dfs(j,a.son[j],b.hsh[i]))%mod;
		memset(f,0,sizeof (f[0])*15);
	}writeln(1LL*ans*Inv(ANS)%mod);
}