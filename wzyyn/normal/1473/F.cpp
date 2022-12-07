#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=6005;
int n,a[N],b[N];
int S,T,nd,tot=1,ans;
int head[N],dis[N],q[N];
struct edge{
	int to,next,f;
}e[N*200];
void add(int x,int y,int v){
	if (!x||!y) return;
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;
}
bool bfs(){
	int h=0,t=1;
	For(i,1,nd) dis[i]=-1;
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
			e[i^1].f+=k; e[i].f-=k; rest-=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
int p[105];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) scanf("%d",&b[i]);
	For(i,1,n) if (b[i]>0) ans+=b[i];
	S=n+1; T=S+1; nd=T;
	For(i,1,n){
		if (b[i]>=0) add(S,i,b[i]);
		else add(i,T,-b[i]);
		For(j,1,a[i]) if (a[i]%j==0) add(i,p[j],1<<30);
		add(++nd,i,1<<30);
		add(nd,p[a[i]],1<<30);
		p[a[i]]=nd;
	}
	for (;bfs();ans-=dfs(S,1<<30));
	cout<<ans<<endl;
}