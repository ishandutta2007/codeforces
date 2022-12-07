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
const int N=15005;
struct edge{
	int to,next,f;
}e[N*15];
int n,m,G,tot=1,S,T;
int head[N],sex[N],ans;
int dis[N],q[N];
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
				if (e[i].to==T) return 1;
				q[++t]=e[i].to; 
			}
	}
	return 0;
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
int main(){
	scanf("%d%d%d",&n,&m,&G);
	For(i,1,n) scanf("%d",&sex[i]);
	S=n+m+1; T=n+m+2;
	For(i,1,n){
		int x;
		scanf("%d",&x);
		sex[i]?add(i,T,x):add(S,i,x);
	}
	For(i,1,m){
		int tp,x,cnt,y;
		scanf("%d%d%d",&tp,&x,&cnt);
		For(j,1,cnt){
			scanf("%d",&y);
			tp?add(y,i+n,1<<30):add(i+n,y,1<<30);
		}
		scanf("%d",&cnt);
		ans+=x; x+=cnt*G;
		tp?add(n+i,T,x):add(S,n+i,x);
	}
	for (;bfs();ans-=dfs(S,1<<30));
	printf("%d\n",ans);
}