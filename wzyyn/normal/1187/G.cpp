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
const int N=105;
int id[N][N],nd,S,T;
int n,m,k,c,d,x[N],y[N];
struct edge{
	int from,to,next,f,v;
}e[N*N*N];
int head[N*N],tot=1;
pii info[N*N*N];
void add(int x,int y,int f,int v){
	e[++tot]=(edge){x,y,head[x],f,v};
	head[x]=tot;
	e[++tot]=(edge){y,x,head[y],0,-v};
	head[y]=tot;
}
int dis[N*N],q[N*N*N];
int vis[N*N],from[N*N];
int fl[N][N],ans;
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
	ans+=dis[T];
	for (int i=from[T];i;i=from[e[i].from]){
		e[i].f--; e[i^1].f++;
		if (!info[i].fi) continue;
		int t=info[i].fi,j=info[i].se;
		++fl[t][j];
		add(id[t][x[j]],id[t-1][y[j]],1,c+(2*fl[t][j]+1)*d);
		add(id[t][y[j]],id[t-1][x[j]],1,c+(2*fl[t][j]+1)*d);
		For(T,0,3) info[tot-T]=pii(t,j);
	}
}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&k,&c,&d);
	For(t,0,k+n) For(i,1,n) id[t][i]=++nd;
	S=++nd; T=++nd;
	For(t,0,k+n) add(id[t][1],T,1<<30,0);
	For(t,1,k+n) For(i,1,n)
		add(id[t][i],id[t-1][i],1<<30,c);
	For(i,1,k){
		int x;
		scanf("%d",&x);
		add(S,id[k+n][x],1,0);
	}
	For(i,1,m){
		scanf("%d%d",&x[i],&y[i]);
		For(j,1,k+n){
			add(id[j][x[i]],id[j-1][y[i]],1,c+d);
			add(id[j][y[i]],id[j-1][x[i]],1,c+d);
			For(T,0,3) info[tot-T]=pii(j,i);
		}
	}
	for (;bfs();del());
	printf("%d\n",ans);
}