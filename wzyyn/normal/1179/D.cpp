#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int M=1000005;
struct Func{
	ll k,b;
	ll F(ll x){
		return k*x+b;
	}
}t[M];
int ls[M],rs[M],nd,rt;
void insert(int &k,int l,int r,Func f){
	if (!k){
		k=++nd;
		t[k]=f;
		return;
	}
	int mid=(l+r)/2;
	if (t[k].F(mid)>f.F(mid)) swap(t[k],f);
	if (l==r) return;
	if (f.F(l)<t[k].F(l))
		insert(ls[k],l,mid,f);
	if (f.F(r)<t[k].F(r))
		insert(rs[k],mid+1,r,f);
}
ll ask(int k,int l,int r,int p){
	if (!k) return 1ll<<60;
	if (l==r) return t[k].F(p);
	int mid=(l+r)/2;
	if (p<=mid) return min(t[k].F(p),ask(ls[k],l,mid,p));
	return min(t[k].F(p),ask(rs[k],mid+1,r,p));
}
const int N=500005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n,sz[N];
ll ans,f[N];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot; 
}
void dfs(int x,int fa){
	sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs(e[i].to,x);
			sz[x]+=sz[e[i].to]; 
		}
}
ll F(int x){
	return 1ll*x*(x-1)/2;
}
void dfs1(int x,int fa){
	f[x]=F(sz[x]);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs1(e[i].to,x);
			f[x]=min(f[x],f[e[i].to]+F(sz[x]-sz[e[i].to]));
			ans=min(ans,f[e[i].to]+F(n-sz[e[i].to]));
		}
	for (;nd;ls[nd]=rs[nd]=0,--nd);
	rt=nd=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			int y=e[i].to;
			ll v=2*f[y]+1ll*sz[y]*sz[y]-2ll*n*sz[y]+sz[y];
			ans=min(ans,(ask(rt,1,sz[x],sz[y])+v+1ll*n*n-n)/2);
			insert(rt,1,sz[x],(Func){2*sz[y],v});
		}
}
int main(){
	ans=1ll<<60;
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	dfs1(1,0);
	printf("%lld\n",1ll*n*(n-1)-ans);
}
/*
f[1]+f[2]+F(n-sz[1]-sz[2])
f[1]+f[2]+(n^2+sz[1]^2+sz2^2-2nsz[1]-2nsz[2]+2sz[1]sz[2]-n+sz[1]+sz[2])
*/