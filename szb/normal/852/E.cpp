#include<algorithm>
#include<memory.h>
#include<cmath>
#include<bitset>
#include<cstdio>
#include<map>
#include<ctime>
#include<bitset>
#define ll long long
#define maxn 410010
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0;char ch=getchar();   while(ch<'0'||ch>'9') ch=getchar();  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x; }
inline void write(ll x){    if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){  write(x);   puts("");   }
const ll mod=1e9+7;
ll son[maxn],a[maxn],b[maxn],f[maxn],h[maxn],head[maxn],q[maxn],nxt[maxn],vet[maxn],tot,n,ans,inv=mod/2+1;
void insert(ll x,ll y){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	}
void dfs(ll x,ll pre){
	f[x]=1;	
	for(ll i=head[x];i;i=nxt[i])
	if (vet[i]!=pre)	dfs(vet[i],x),++son[x],f[x]=f[x]*f[vet[i]]%mod;
	if (!son[x])	f[x]=1;
	else	f[x]=f[x]*2%mod;
}
void dfs1(ll x,ll pre){
	ans=(ans+h[x]*f[x]*(son[x]?1:2))%mod;	ll tot=0;
	for(ll i=head[x];i;i=nxt[i])
	if (vet[i]!=pre)	q[++tot]=f[vet[i]];
	if (x!=1)	q[++tot]=h[x];	ll T=tot;
	q[0]=q[tot+1]=1;
	For(i,0,tot+1)	a[i]=b[i]=q[i];
	For(i,1,tot)	a[i]=a[i]*a[i-1]%mod;
	FOr(i,tot,1)	b[i]=b[i]*b[i+1]%mod;
	tot=0;
	for(ll i=head[x];i;i=nxt[i])
	if (vet[i]!=pre){
		++tot;
		if (T==1)	h[vet[i]]=1;
		else	h[vet[i]]=a[tot-1]*b[tot+1]*2%mod;
	}
	for(ll i=head[x];i;i=nxt[i])
	if (vet[i]!=pre)	dfs1(vet[i],x);
}
int main(){
	n=read();	h[1]=1;
	For(i,2,n){
		ll x=read(),y=read();
		insert(x,y);	insert(y,x);
	}dfs(1,-1);	dfs1(1,-1);
	writeln(ans%mod);
}