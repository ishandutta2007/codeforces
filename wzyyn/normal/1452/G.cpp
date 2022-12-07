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

const int N=200005;
int n,h,t,dis[N],q[N];
vector<int> e[N];
int d[22][N],fa[N],rt;
int dep[N],sz[N],vis[N];
vector<int> v[N];
void dfs(int x,int fa,int n){
	int mx=0;
	sz[x]=1;
	for (auto i:e[x])
		if (i!=fa&&!vis[i]){
			dfs(i,x,n);
			sz[x]+=sz[i];
			mx=max(mx,sz[i]);
		}
	if (sz[x]*2>=n&&mx*2<n)
		rt=x;
}
void dfs2(int x,int fa,int *d){
	for (auto i:e[x])
		if (i!=fa&&!vis[i])
			d[i]=d[x]+1,dfs2(i,x,d);
}
int solve(int x,int n,int d){
	dfs(x,0,n);
	vis[x=rt]=1; dep[x]=d;
	dfs2(x,0,::d[dep[x]]);
	v[x].resize(n+2);
	for (auto i:e[x])
		if (!vis[i]) fa[solve(i,(sz[i]>sz[x]?n-sz[x]:sz[i]),d+1)]=x;
	return x;
}

int query(int x){
	int ans=0;
	for (int y=x;y;y=fa[y])
		ans=max(ans,v[y][d[dep[y]][x]]);
	return ans;
}
void insert(int x,int r,int val){
	for (int y=x;y;y=fa[y]){
		int nr=r-d[dep[y]][x];
		if (nr>=0){
			if (nr>=v[y].size())
				nr=v[y].size()-1;
			//cout<<y<<' '<<nr<<' '<<val<<endl;
			v[y][nr]=max(v[y][nr],val);
		}
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	For(i,1,n) dis[i]=-1;
	scanf("%d",&t);
	For(i,1,t){
		scanf("%d",&q[i]);
		dis[q[i]]=0;
	}
	while (h!=t){
		int x=q[++h];
		//cout<<dis[x]<<' '<<x<<endl;
		for (auto i:e[x])
			if (dis[i]==-1){
				dis[i]=dis[x]+1;
				q[++t]=i;
			}
	}
	solve(1,n,0);
	//For(i,1,n)
	//	cout<<fa[i]<<' '<<dep[i]<<endl;
	For(i,1,n)
		insert(i,dis[i]-1,dis[i]);
	For(i,1,n)
		Rep(j,v[i].size()-2,0)
			v[i][j]=max(v[i][j],v[i][j+1]);
	For(i,1,n)
		printf("%d ",query(i));
}