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
const int N=205;
struct edge{
	int to,next,f;
}e[N*N];
int head[N],tot=1,n,m;
int lx[N],rx[N],ly[N],ry[N];
int x[N],y[N],q[N],dis[N];
int S,T,s[N][N];
void add(int x,int y,int v){
	//printf("%d %d %d\n",x,y,v);
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;
}
bool bfs(){
	For(i,1,T) dis[i]=-1;
	int h=0,t=1; dis[S]=0; q[1]=S;
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
	for (int i=head[x];i;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			k=dfs(e[i].to,min(rest,e[i].f));
			e[i].f-=k; e[i^1].f+=k; rest-=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		scanf("%d%d%d%d",&lx[i],&ly[i],&rx[i],&ry[i]);
		x[++*x]=lx[i]; x[++*x]=++rx[i];
		y[++*y]=ly[i]; y[++*y]=++ry[i];
	}
	sort(x+1,x+*x+1);
	sort(y+1,y+*y+1);
	*x=unique(x+1,x+*x+1)-x-1;
	*y=unique(y+1,y+*y+1)-y-1;
	For(i,1,m){
		lx[i]=lower_bound(x+1,x+*x+1,lx[i])-x;
		rx[i]=lower_bound(x+1,x+*x+1,rx[i])-x;
		ly[i]=lower_bound(y+1,y+*y+1,ly[i])-y;
		ry[i]=lower_bound(y+1,y+*y+1,ry[i])-y;
		s[lx[i]][ly[i]]++;
		s[lx[i]][ry[i]]--;
		s[rx[i]][ly[i]]--;
		s[rx[i]][ry[i]]++;
	}
	S=(*x)+(*y)+1,T=S+1;
	For(i,1,(*x)-1) add(S,i,x[i+1]-x[i]);
	For(i,1,(*y)-1) add(i+(*x),T,y[i+1]-y[i]);
	For(i,1,(*x)-1) For(j,1,(*y)-1){
		s[i][j]+=s[i][j-1]+s[i-1][j]-s[i-1][j-1];
		if (s[i][j]) add(i,j+(*x),1<<30);
	}
	int ans=0;
	for (;bfs();ans+=dfs(S,1<<30));
	printf("%d\n",ans);
}