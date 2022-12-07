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
const int N=205;
struct edge{
	int to,next,f;
}e[N*20];
struct Edge{
	int x,y,v;
	bool operator <(const Edge &a)const{
		return v<a.v;
	}
}E[N];
int head[N],tot,n,m,top;
int dis[N],q[N],vis[N];
int X[N*5],Y[N*5],C[N*5];
int fa[N],ans;
vector<int> v[N];
void add(int x,int y,int f){
	e[++tot]=(edge){y,head[x],f};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],f};
	head[y]=tot;
}
bool bfs(int S,int T){
	//cout<<S<<' '<<T<<endl;
	For(i,1,n) dis[i]=-1;
	int h=0,t=1; q[1]=S; dis[S]=0;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]==-1&&e[i].f){
				dis[e[i].to]=dis[x]+1;
				if (e[i].to==T) return 1;
				q[++t]=e[i].to;
			}
	}
	return 0;
}
int dfs(int x,int flow,int T){
	if (x==T) return flow;
	int k,rest=flow;
	for (int i=head[x];i&&rest;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			int k=dfs(e[i].to,min(rest,e[i].f),T);
			e[i].f-=k; e[i^1].f+=k; rest-=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
int get_flow(int S,int T){
	int ans=0; tot=1;
	memset(head,0,sizeof(head));
	For(i,1,m) add(X[i],Y[i],C[i]);
	for (;bfs(S,T);ans+=dfs(S,1<<30,T));
	return ans;
}
void color(int x){
	vis[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]&&e[i].f)
			color(e[i].to);
}
void solve(vector<int> vec){
	//cout<<vec.size()<<endl;
	assert(vec.size());
	if (vec.size()==1) return;
	int val=get_flow(vec[0],vec[1]);
	memset(vis,0,sizeof(vis));
	color(vec[0]);
	vector<int> a,b;
	for (auto i:vec)
		vis[i]?a.PB(i):b.PB(i);
	E[++top]=(Edge){a[0],b[0],val};
	solve(a); solve(b);
}
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m) scanf("%d%d%d",&X[i],&Y[i],&C[i]);
	vector<int> vec;
	For(i,1,n) vec.PB(i);
	solve(vec);
	sort(E+1,E+top+1);
	For(i,1,n) fa[i]=i,v[i].PB(i);
	Rep(i,top,1){
		//cout<<E[i].x<<' '<<E[i].y<<' '<<E[i].v<<endl;
		int x=get(E[i].x);
		int y=get(E[i].y);
		ans+=E[i].v; fa[y]=x;
		for (auto j:v[y]) v[x].PB(j);
	}
	printf("%d\n",ans);
	for (auto i:v[get(1)]) printf("%d ",i);
}