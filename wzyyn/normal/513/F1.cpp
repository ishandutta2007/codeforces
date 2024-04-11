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
const int N=25,M=455;
char mp[N][N];
int n,m,A,B,nd;
int d[M][M],id[N][N];
int xa[M],ya[M],va[M];
int xb[M],yb[M],vb[M];
int head[M*4],tot,S,T;
int dis[M*4],q[M*4];
struct edge{
	int to,next,f,v;
}e[M*M*10];
void add(int x,int y,int f){
	//cout<<x<<' '<<y<<endl;
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
				if (e[i].to==T) return 1; 
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
	if (!rest) dis[x]=-1;
	return flow-rest;
}
bool check(ll v){
	tot=1;
	memset(head,0,sizeof(head));
	if (A>nd) return 0;
	S=2*(nd+A)+1; T=S+1;
	For(i,1,A) add(S,i,1);
	For(i,1,A) add(i+A+nd+nd,T,1);
	For(i,1,nd) add(A+i,A+nd+i,1);
	For(i,1,A){
		int p=id[xa[i]][ya[i]];
		For(j,1,nd)
			if (d[p][j]<=500&&1ll*d[p][j]*va[i]<=v)
				add(i,A+j,1);
	}
	For(i,1,A){
		int p=id[xb[i]][yb[i]];
		For(j,1,nd)
			if (d[p][j]<=500&&1ll*d[p][j]*vb[i]<=v)
				add(A+nd+j,A+nd+nd+i,1);
	}
	int sum=0;
	for (;bfs();sum+=dfs(S,1<<30));
	return sum==A;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&A,&B);
	if (abs(A-B)!=1) return puts("-1"),0;
	For(i,1,n) scanf("%s",mp[i]+1);
	For(i,1,n) For(j,1,m) if (mp[i][j]=='.') id[i][j]=++nd;
	For(i,1,nd) For(j,1,nd) d[i][j]=1<<29;
	For(i,1,n) For(j,1,m){
		if (id[i][j]&&id[i][j+1]){
			d[id[i][j]][id[i][j+1]]=1;
			d[id[i][j+1]][id[i][j]]=1;
		}
		if (id[i][j]&&id[i+1][j]){
			d[id[i][j]][id[i+1][j]]=1;
			d[id[i+1][j]][id[i][j]]=1;
		}
	}
	For(i,1,nd) d[i][i]=0;
	For(k,1,nd) For(i,1,nd) For(j,1,nd)
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	//cout<<d[1][3]<<endl;
	if (A<B) scanf("%d%d%d",&xa[B],&ya[B],&va[B]);
	else scanf("%d%d%d",&xb[A],&yb[A],&vb[A]);
	For(i,1,A) scanf("%d%d%d",&xa[i],&ya[i],&va[i]);
	For(i,1,B) scanf("%d%d%d",&xb[i],&yb[i],&vb[i]);
	A=max(A,B);
	if (!check(n*m*(1ll<<30))) return puts("-1"),0;
	//exit(0);
	ll l=0,r=n*m*(1ll<<30),ans=-233;
	while (l<=r){
		ll mid=(l+r)/2;
		if (check(mid))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
}