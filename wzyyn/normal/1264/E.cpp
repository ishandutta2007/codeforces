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
const int N=55;
int n,m,nd,S,T,head[N*N],tot=1;
int fl[N][N],id[N][N],ans[N][N];
int dis[N*N],q[N*N*10],vis[N*N],from[N*N];
struct edge{
	int from,to,next,f,v;
}e[N*N*10];
void add(int x,int y,int f,int v){
	e[++tot]=(edge){x,y,head[x],f,v};
	head[x]=tot;
	e[++tot]=(edge){y,x,head[y],0,-v};
	head[y]=tot;
}
bool bfs(){
	For(i,1,nd) dis[i]=1<<30,vis[i]=0;
	int h=0,t=1; q[1]=S; dis[S]=0;
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
	return dis[T]!=1<<30;
}
void del(){
	for (int i=from[T];i;i=from[e[i].from])
		e[i].f--,e[i^1].f++;
}
int main(){
	scanf("%d%d",&n,&m);
	nd=n; S=++nd; T=++nd;
	For(i,1,n) For(j,1,n-1) add(i,T,1,j-1);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		fl[y][x]=1;
	}
	For(i,1,n) For(j,i+1,n){
		id[i][j]=++nd;
		add(S,nd,1,0);
		if (!fl[i][j]) add(nd,i,1,0);
		if (!fl[j][i]) add(nd,j,1,0);
	}
	for (;bfs();del());
	For(i,1,n) For(j,i+1,n)
		for (int k=head[id[i][j]];k;k=e[k].next){
			if (e[k].to==i) ans[i][j]=1-e[k].f;
			if (e[k].to==j) ans[j][i]=1-e[k].f;
		}
	For(i,1,n){
		For(j,1,n) printf("%d",ans[i][j]);
		puts("");
	}
}