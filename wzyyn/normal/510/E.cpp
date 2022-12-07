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
const int N=205,M=40005;
struct edge{
	int to,next,f;
}e[M];
int head[N],tot=1,sum;
int dis[N],q[N],n,top;
int fl[M],a[N],SS[2];
int id[N][N],vis[N],S,T;
vector<int> vec[N];
vector<int> ans[N];
void init(){
	For(i,2,(M-1))
		For(j,2,(M-1)/i)
			fl[i*j]=1;
}
void add(int x,int y,int f){
	e[++tot]=(edge){y,head[x],f};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;
}
bool bfs(){
	For(i,1,T) dis[i]=-1;
	int h=0,t=1;
	q[1]=S; dis[S]=0;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]==-1&&e[i].f){
				dis[e[i].to]=dis[x]+1;
				q[++t]=e[i].to;
			}
	}
	return dis[T]!=-1;
}
int dfs(int x,int flow){
	if (x==T) return flow;
	int k,rest=flow;
	for (int i=head[x];i&&rest;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			k=dfs(e[i].to,min(rest,e[i].f));
			e[i].f-=k; e[i^1].f+=k; rest-=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
void getans(int x,int be){
	ans[be].PB(x);
	vis[x]=1;
	for (auto i:vec[x]) if (!vis[i])
		getans(i,be);
}
int main(){
	init();
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d",&a[i]);
		++SS[a[i]&1];
	}
	if (SS[0]!=SS[1])
		return puts("Impossible"),0;
	S=n+1; T=S+1;
	For(i,1,n)
		if (a[i]&1) add(i,T,2);
		else add(S,i,2);
	For(i,1,n) For(j,1,n)
		if (a[i]%2==0&&!fl[a[i]+a[j]])
			add(i,j,1),id[i][j]=tot;
	for (;bfs();sum+=dfs(S,1<<30));
	if (sum!=n)
		return puts("Impossible"),0;
	For(i,1,n) For(j,1,n)
		if (id[i][j]&&e[id[i][j]].f)
			vec[i].PB(j),vec[j].PB(i);
	For(i,1,n) if (!vis[i])
		getans(i,++top);
	printf("%d\n",top);
	For(i,1,top){
		printf("%d",ans[i].size());
		for (auto j:ans[i]) printf(" %d",j);
		puts("");
	}
}