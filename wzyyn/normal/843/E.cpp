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
const int N=2005;
int n,m,S,T,SS,TT;
struct Edge{
	int x,y,g;
}a[N];
struct edge{
	int to,next,f;
}e[N*10];
int head[N],tot=1;
int dis[N],q[N],be[N];
int id[N],in[N],ans;
void add(int x,int y,int f){
	e[++tot]=(edge){y,head[x],f};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;
}
bool bfs(int S,int T){
	For(i,1,n+2) dis[i]=-1;
	int h=0,t=1;
	q[1]=S; dis[S]=0;
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
int dfs(int x,int T,int flow){
	if (x==T) return flow;
	int k,rest=flow;
	for (int i=head[x];i&&rest;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			k=dfs(e[i].to,T,min(rest,e[i].f));
			rest-=k; e[i].f-=k; e[i^1].f+=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&S,&T);
	For(i,1,m){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].g);
		if (a[i].x==S&&a[i].y==T) ++ans;
		else if (a[i].g==0) add(a[i].x,a[i].y,1<<30);
		else{
			add(a[i].x,a[i].y,1);
			add(a[i].y,a[i].x,1<<30);
		}
	}
	for (;bfs(S,T);ans+=dfs(S,T,1<<30));
	printf("%d\n",ans);
	For(i,1,n) be[i]=(dis[i]!=-1);
	memset(head,0,sizeof(head));
	tot=1;
	For(i,1,m) if (a[i].g){
		id[i]=tot+2;
		add(a[i].x,a[i].y,10000);
		++in[a[i].y];
		--in[a[i].x];
	}
	SS=n+1; TT=SS+1;
	For(i,1,n){
		//cout<<in[i]<<' '<<ed
		if (in[i]<0) add(i,TT,-in[i]);
		if (in[i]>0) add(SS,i,in[i]);
	}
	add(T,S,1<<30);
	for (;bfs(SS,TT);dfs(SS,TT,1<<30));
	For(i,1,m)
		if (a[i].x==S&&a[i].y==T) puts("1 1");
		else if (!a[i].g) puts("0 1");
		else{
			int fl=e[id[i]].f+1;
			printf("%d %d\n",fl,be[a[i].x]^be[a[i].y]?fl:10000); 
		}
}