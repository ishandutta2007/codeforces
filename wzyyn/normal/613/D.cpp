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
const int inf=(1<<30)-233;
const int N=100005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n;
int sz[N],fa[N],dep[N];
int dfn[N],ed[N],top[N];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs1(int x){
	sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			fa[e[i].to]=x;
			dep[e[i].to]=dep[x]+1;
			dfs1(e[i].to);
			sz[x]+=sz[e[i].to];
		}
}
void dfs2(int x,int tp){
	dfn[x]=++*dfn;
	top[x]=tp;
	int k=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&sz[e[i].to]>sz[k])
			k=e[i].to;
	if (k) dfs2(k,tp);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=k)
			dfs2(e[i].to,e[i].to);
	ed[x]=*dfn;
}
int LCA(int x,int y){
	for (;top[x]!=top[y];x=fa[top[x]])
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
	return dep[x]<dep[y]?x:y;
}
bool isfa(int x,int y){
	return dfn[x]<=dfn[y]&&ed[y]<=ed[x];
}
int q[N*2],vis[N],T;
vector<int> ee[N];
int f[N][2];
bool cmp(int x,int y){
	return dfn[x]<dfn[y];
}
void dfs(int x){
	for (auto i:ee[x]) dfs(i);
	if (vis[x]==T){
		f[x][0]=inf;
		f[x][1]=0;
		for (auto i:ee[x])
			f[x][1]=min(inf,f[x][1]+f[i][0]);
	}
	else{
		int tmp=0;
		for (auto i:ee[x])
			tmp=min(inf,tmp+min(f[i][0],f[i][1]));
		f[x][0]=tmp+1; f[x][1]=inf;
		int v0=0,v1=0;
		for (auto i:ee[x]){
			v1=min(inf,min(v0+f[i][1],v1+f[i][0]));
			v0=min(inf,v0+f[i][0]);
		}
		f[x][0]=min(f[x][0],v0);
		f[x][1]=min(f[x][1],v1);
	}
	//cout<<"F "<<x<<' '<<f[x][0]<<' '<<f[x][1]<<endl;
}
void solve(){
	++T;
	int m;
	scanf("%d",&m);
	For(i,1,m) scanf("%d",&q[i]);
	For(i,1,m) vis[q[i]]=T;
	int mm=m;
	For(i,1,m) if (q[i]!=1) q[++mm]=fa[q[i]];
	sort(q+1,q+mm+1,cmp);
	mm=unique(q+1,q+mm+1)-q-1;
	For(i,1,mm-1) q[mm+i]=LCA(q[i],q[i+1]);
	mm=2*mm-1;
	sort(q+1,q+mm+1,cmp);
	mm=unique(q+1,q+mm+1)-q-1;
	int top=1;
	For(i,1,mm) ee[q[i]].resize(0);
	//For(i,1,mm) cout<<q[i]<<' '; cout<<endl;
	For(i,2,mm){
		for (;!isfa(q[top],q[i]);--top);
		ee[q[top]].PB(q[i]);
		//cout<<"EDGE "<<q[top]<<' '<<q[i]<<endl;
		q[++top]=q[i];
	}
	dfs(q[1]);
	int ans=min(f[q[1]][0],f[q[1]][1]);
	printf("%d\n",ans>=inf?-1:ans);
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs1(1);
	dfs2(1,1);
	int Q;
	scanf("%d",&Q);
	For(i,1,Q) solve();
}