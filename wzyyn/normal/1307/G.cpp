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
const int M=100005;
const int N=55;
struct edge{
	int from,to,next,f,v;
}e[N*N*2];
int x[M],n,m,Q;
int head[N],tot=1;
int dis[N],q[N*N];
int from[N],vis[N];
double ans[M];
void add(int x,int y,int f,int v){
	e[++tot]=(edge){x,y,head[x],f,v};
	head[x]=tot;
	e[++tot]=(edge){y,x,head[y],0,-v};
	head[y]=tot;
}
int bfs(){
	For(i,1,n) vis[i]=0,dis[i]=1<<30;
	int h=0,t=1;
	q[1]=1; dis[1]=0;
	while (h!=t){
		int x=q[++h]; vis[x]=0;
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]>dis[x]+e[i].v&&e[i].f){
				dis[e[i].to]=dis[x]+e[i].v;
				from[e[i].to]=i;
				if (!vis[e[i].to]){
					q[++t]=e[i].to;
					vis[e[i].to]=1;
				}
			}
	}
	if (dis[n]!=(1<<30))
		for (int i=from[n];i;i=from[e[i].from])
			e[i].f--,e[i^1].f++;
	return dis[n];
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,1,v);
	}
	scanf("%d",&Q);
	For(i,1,Q){
		scanf("%d",&x[i]);
		ans[i]=1e18;
	}
	int S1=0,S2=0;
	for (;;){
		int v=bfs();
		if (v==(1<<30)) break;
		S1+=v; S2++;
		For(i,1,Q) ans[i]=min(ans[i],1.0*(S1+x[i])/S2);
	}
	For(i,1,Q)
		printf("%.10lf\n",ans[i]);
}