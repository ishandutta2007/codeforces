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
const int N=10505;
int n,Q,id[55][205],S,T;
int head[N],tot=1,nd;
int dis[N],q[N],ans;
struct edge{
	int to,next,f;
}e[N*20];
void add(int x,int y,int f){
	e[++tot]=(edge){y,head[x],f};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;
}
bool bfs(){
	For(i,1,nd) dis[i]=-1;
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
	scanf("%d%d",&n,&Q);
	S=++nd; T=++nd;
	For(i,1,n) For(j,0,201) id[i][j]=++nd;
	For(i,1,n){
		int A,B,C;
		scanf("%d%d%d",&A,&B,&C);
		For(j,-100,100) add(id[i][j+100],id[i][j+101],1000000-A*j*j-B*j-C);
	}
	For(i,1,n){
		int l,r;
		scanf("%d%d",&l,&r);
		add(S,id[i][l+100],1<<30);
		add(id[i][r+101],T,1<<30);
	}
	For(i,1,Q){
		int x,y,v;
		scanf("%d%d%d",&y,&x,&v);
		For(j,-100,100)
			add(id[y][j+100],id[x][max(min(j+100-v,201),0)],1<<30);
	}
	for (;bfs();ans+=dfs(S,1<<30));
	printf("%d\n",1000000*n-ans);
}
/*
x<=y+d
y>=x-d
*/