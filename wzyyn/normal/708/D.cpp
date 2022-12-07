#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=105;
struct edge{
	int from,to,next,f,v;
}e[N*15];
int head[N],tot=1;
int n,m,S,T,ans,sum;
int deg[N],q[N*10],vis[N];
int from[N],dis[N];
void add(int x,int y,int f,int v){
	e[++tot]=(edge){x,y,head[x],f,v};
	head[x]=tot;
	e[++tot]=(edge){y,x,head[y],0,-v};
	head[y]=tot;
}
bool bfs(){
	For(i,1,T)
		dis[i]=1<<30,vis[i]=0;
	int h=0,t=1;
	q[1]=S; dis[S]=0;
	while (h!=t){
		int x=q[++h]; vis[x]=0;
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]>dis[x]+e[i].v&&e[i].f){
				dis[e[i].to]=dis[x]+e[i].v;
				from[e[i].to]=i;
				if (!vis[e[i].to]){
					vis[e[i].to]=1;
					q[++t]=e[i].to;
				}
			}
	}
	return dis[T]!=(1<<30);
}
void del(){
	int v=1<<30;
	for (int i=from[T];i;i=from[e[i].from])
		v=min(v,e[i].f);
	ans+=dis[T]*v; sum-=v;
	for (int i=from[T];i;i=from[e[i].from])
		e[i].f-=v,e[i^1].f+=v;
}
int main(){
	scanf("%d%d",&n,&m);
	S=n+1; T=n+2;
	For(i,1,m){
		int x,y,f,c;
		scanf("%d%d%d%d",&x,&y,&c,&f);
		deg[x]+=f; deg[y]-=f;
		if (f<=c){
			add(x,y,c-f,1);
			add(x,y,1<<30,2);
			add(y,x,f,1);
		}
		else{
			ans+=f-c;
			add(y,x,f-c,0);
			add(x,y,1<<30,2);
			add(y,x,c,1);
		}
	}
	add(n,1,1e9,0);
	For(i,1,n)
		if (deg[i]>0){
			sum+=deg[i];
			add(i,T,deg[i],0);
		}
		else
			add(S,i,-deg[i],0);
	for (;bfs();del());
	assert(sum==0);
	printf("%d\n",ans);
}