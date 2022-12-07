#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int mo=1000000007;
const int N=100005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n,Q;
int sz[N],dfn[N],fa[N],ed[N];
int dep[N],top[N],hson[N];
int C[505][505],inv[505],sum[N],mx;
int d[N],a[N*2],vis[N];
vector<int> E[N];
void init(){
	inv[0]=inv[1]=1;
	For(i,2,500) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,2,500) inv[i]=1ll*inv[i-1]*inv[i]%mo; 
	For(i,0,500) C[i][0]=1;
	For(i,1,500) For(j,1,i)
		C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
}
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs1(int x){
	sz[x]=1;
	dfn[x]=++*dfn;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			fa[e[i].to]=x;
			dep[e[i].to]=dep[x]+1;
			dfs1(e[i].to);
			sz[x]+=sz[e[i].to];
			if (sz[e[i].to]>sz[hson[x]])
				hson[x]=e[i].to;
		}
	ed[x]=*dfn;
}
void dfs2(int x){
	if (!top[x]) top[x]=x;
	if (hson[x]) top[hson[x]]=top[x];
	//cout<<x<<' '<<top[x]<<' '<<dep[x]<<endl;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x])
			dfs2(e[i].to);
}
bool cmp(int x,int y){
	return dfn[x]<dfn[y];
}
int LCA(int x,int y){
	for (;top[x]!=top[y];x=fa[top[x]])
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
	return dep[x]<dep[y]?x:y;
}
bool isfa(int x,int y){
	return dfn[x]<=dfn[y]&&ed[y]<=ed[x];
} 
void dfs(int x,int fa){
	if (vis[x]){
		if (++d[x]>mx)
			mx=d[x],sum[mx]=0;
		++sum[d[x]];
	}
	for (auto i:E[x]) if (i!=fa)
		d[i]=d[x],dfs(i,x);
}
int q[N],v[505];
void solve(){
	int k,kk,m,rt;
	scanf("%d%d%d",&k,&m,&rt);
	For(i,1,k){
		scanf("%d",&a[i]);
		vis[a[i]]=1;
	}
	a[++k]=rt;
	sort(a+1,a+k+1,cmp);
	For(i,1,k-1) a[k+i]=LCA(a[i],a[i+1]);
	sort(a+1,a+2*k,cmp); kk=k;
	k=unique(a+1,a+2*k)-a-1;
	int top=1;
	q[1]=a[1];
	For(i,2,k){
		for (;!isfa(q[top],a[i]);--top);
		E[q[top]].PB(a[i]);
		E[a[i]].PB(q[top]);
		//printf("EDGE %d %d\n",a[i],a[top]);
		q[++top]=a[i];
	}
	mx=d[rt]=sum[0]=0;
	dfs(rt,0);
	//cout<<mx<<endl;
	//For(i,1,mx) printf("%d ",sum[i]); puts("");
	if (mx>m) printf("0\n");
	else{
		int up=min(m,kk);
		For(j,0,up) v[j]=1;
		For(j,0,up) For(k,1,mx) For(l,1,sum[k])
			v[j]=1ll*v[j]*(j-k+1)%mo;
		For(j,0,up) For(k,j+1,up)
			v[k]=(v[k]+mo-1ll*v[j]*C[k][j]%mo)%mo;
		int ans=0; 
		For(j,0,up) ans=(ans+1ll*v[j]*inv[j])%mo;
		printf("%d\n",ans);
	}
	For(i,1,k){
		E[a[i]].resize(0);
		vis[a[i]]=0;
	}
}
int main(){
	init();
	scanf("%d%d",&n,&Q);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs1(1);
	dfs2(1);
	while (Q--) solve();
}