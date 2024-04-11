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
const int N=505;
int n,rt1,rt2,sum=0;
int a[N],l1[N],l2[N];
int head[N*2],tot=1,S,T;
ll dis[N*2],ans;
int q[N*N*2],vis[N*2];
int from[N*2],Q,id[N*2];
struct edge{
	int from,to,next,f,v;
}e[N*15];
struct TREE{
	int fa[N];
	vector<int> e[N];
	void dfs(int x){
		for (auto i:e[x])
			if (i!=fa[x]){
				fa[i]=x;
				dfs(i);
			}
	}
	void init(int rt){
		For(i,1,n-1){
			int x,y;
			scanf("%d%d",&x,&y);
			e[x].PB(y); e[y].PB(x);
		}
		dfs(rt);
	}
}T1,T2;
void add(int x,int y,int f,int v){
	//cout<<x<<' '<<y<<' '<<f<<' '<<v<<endl;
	e[++tot]=(edge){x,y,head[x],f,v};
	head[x]=tot;
	e[++tot]=(edge){y,x,head[y],0,-v};
	head[y]=tot;
}
bool bfs(){
	For(i,1,T) dis[i]=-(1<<30),vis[i]=0;
	int h=0,t=1;
	q[1]=S; dis[S]=0;
	while (h!=t){
		int x=q[++h]; vis[x]=0;
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]<dis[x]+e[i].v&&e[i].f){
				dis[e[i].to]=dis[x]+e[i].v;
				from[e[i].to]=i;
				if (!vis[e[i].to]){
					q[++t]=e[i].to;
					vis[e[i].to]=1;
				}
			}
	}
	return dis[T]>-(1<<29);
}
void del(){
	ans+=dis[T];
	for (int i=from[T];i;i=from[e[i].from])
		e[i].f--,e[i^1].f++;
}
int main(){
	scanf("%d%d%d",&n,&rt1,&rt2);
	For(i,1,n) scanf("%d",&a[i]);
	T1.init(rt1); T2.init(rt2);
	For(i,1,n) l1[i]=l2[i]=n+1;
	scanf("%d",&Q);
	For(i,1,Q){
		int x,y;
		scanf("%d%d",&x,&y);
		l1[x]=min(l1[x],y);
	}
	scanf("%d",&Q);
	For(i,1,Q){
		int x,y;
		scanf("%d%d",&x,&y);
		l2[x]=min(l2[x],y);
	}
	S=n*2+1; T=S+1;
	For(i,1,n) add(i==rt1?S:T1.fa[i],i,l1[i],(l1[i]==n+1?0:1<<30)),id[i]=tot;
	For(i,1,n) add(i,i+n,1,a[i]);
	For(i,1,n) add(i+n,i==rt2?T:T2.fa[i]+n,l2[i],(l2[i]==n+1?0:1<<30)),id[i+n]=tot;
	for (;bfs();del());
	For(i,1,n){
		if (l1[i]!=n+1) ans-=l1[i]*(1ll<<30);
		///cout<<i<<' '<<l1[i]<<' '<<e[id[i]^1].f<<endl;
		if (l1[i]!=n+1&&e[id[i]^1].f) return puts("-1"),0;
	}
	For(i,1,n){
		if (l2[i]!=n+1) ans-=l2[i]*(1ll<<30);
		///cout<<i<<' '<<l2[i]<<' '<<e[id[i+n]^1].f<<endl;
		if (l2[i]!=n+1&&e[id[i+n]^1].f) return puts("-1"),0;
	}
	printf("%lld\n",ans);
}