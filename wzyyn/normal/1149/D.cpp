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
const int N=77,M=405;
struct edge{
	int to,next,v;
}e[M];
int head[N],tot,cnt;
int n,m,a,b;
int fa[N],sz[N],co[N];
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
struct node{
	int x,S,v;
	bool operator <(const node &a)const{
		return !(v<a.v);
	}
};
priority_queue<node> Q;
int dis[300000][N];
int vis[300000][N];
int ans[N];
int main(){
	scanf("%d%d%d%d",&n,&m,&a,&b);
	For(i,1,n) fa[i]=i,sz[i]=1;
	For(i,1,m){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
		if (v==a){
			x=get(x); y=get(y);
			if (y!=x) fa[x]=y,sz[y]+=sz[x];
		}
	}
	For(i,1,n)
		if (fa[i]==i&&sz[i]>=4)
			co[i]=++cnt;
	For(i,1,n) co[i]=co[get(i)];
	memset(dis,60,sizeof(dis));
	memset(ans,60,sizeof(ans));
	int rest=n;
	dis[0][1]=0;
	Q.push((node){1,0,dis[0][1]});
	while (!Q.empty()){
		int x=Q.top().x,S=Q.top().S;
		Q.pop();
		if (vis[S][x]) continue;
		vis[S][x]=1;
		if (ans[x]>1e9){
			ans[x]=dis[S][x];
			if (!(--rest)) break;
		}
		for (int i=head[x];i;i=e[i].next){
			int nx=e[i].to,nS=S|(co[x]&&co[nx]!=co[x]?1<<(co[x]-1):0);
			if (co[nx]&&(S&(1<<(co[nx]-1)))) continue;
			if (e[i].v==b&&fa[nx]==fa[x]) continue;
			if (dis[nS][nx]>dis[S][x]+e[i].v){
				dis[nS][nx]=dis[S][x]+e[i].v;
				Q.push((node){nx,nS,dis[nS][nx]});
			}
		}
	}
	For(i,1,n)
		printf("%d ",ans[i]);
}