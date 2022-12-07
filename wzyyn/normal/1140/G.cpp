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
const int N=300005;
int n,Q;
ll ans[N*2];
bool vis[N*2];
struct edgeG{
	int to,next;
	ll w;
};
struct G{
	edgeG e[N*6];
	int head[N*2],tot;
	void add(int x,int y,ll v){
		e[++tot]=(edgeG){y,head[x],v};
		head[x]=tot;
		e[++tot]=(edgeG){x,head[y],v};
		head[y]=tot;
	}
	priority_queue<pll> Q;
	void SSSP(int S,ll *dis){
		for (;!Q.empty();Q.pop());
		dis[S]=0; Q.push(pll(0,S));
		while (!Q.empty()){
			pll tmp=Q.top(); Q.pop();
			if (-tmp.fi!=dis[tmp.se]) continue;
			for (int i=head[tmp.se];i;i=e[i].next)
				if (!vis[e[i].to]&&dis[e[i].to]>dis[tmp.se]+e[i].w){
					dis[e[i].to]=dis[tmp.se]+e[i].w;
					Q.push(pll(-dis[e[i].to],e[i].to));
				}
		}
	}
}G;
struct edgeT{
	int to,next;
};
struct query{
	int bx,by,x,y,id;
};
struct Tree{
	edgeT e[N*2];
	int head[N],tot;
	vector<query> vec[N]; 
	void add(int x,int y){
		e[++tot]=(edgeT){y,head[x]};
		head[x]=tot;
		e[++tot]=(edgeT){x,head[y]};
		head[y]=tot;
	}
	void addQ(int bx,int by,int x,int y,int id){
		vec[bx].PB((query){bx,by,x,y,id});
	}
	int sz[N],co[N];
	int mxv,mxrt;
	ll d0[N*2],d1[N*2];
	void dfs(int x,int fa,int n){
		sz[x]=1; int mx=0; co[x]=*co;
		d0[x*2]=d1[x*2]=d0[x*2-1]=d1[x*2-1]=1ll<<60;
		for (int i=head[x];i;i=e[i].next)
			if (e[i].to!=fa&&!vis[e[i].to*2]){
				dfs(e[i].to,x,n);
				sz[x]+=sz[e[i].to];
				mx=max(mx,sz[e[i].to]);
			}
		mx=max(mx,n-sz[x]);
		if (mx<mxv) mxv=mx,mxrt=x;
	}
	void getans(int x,int fa){
		For(i,0,vec[x].size()-1){
			query q=vec[x][i];
			if (co[q.bx]==co[q.by]){
				ans[q.id]=min(ans[q.id],d0[q.x]+d0[q.y]);
				ans[q.id]=min(ans[q.id],d1[q.x]+d1[q.y]);
			}
		}
		for (int i=head[x];i;i=e[i].next)
			if (e[i].to!=fa&&!vis[e[i].to*2])
				getans(e[i].to,x);
	}
	void solve(int x,int n){
		mxv=1<<30; ++*co;
		dfs(x,0,n); x=mxrt;
		G.SSSP(x*2,d0); G.SSSP(x*2-1,d1);
		vis[x*2]=vis[x*2-1]=1; getans(x,0);
		for (int i=head[x];i;i=e[i].next)
			if (!vis[e[i].to*2])
				solve(e[i].to,sz[x]>sz[e[i].to]?sz[e[i].to]:n-sz[x]); 
	} 
}T;
int main(){
	scanf("%d",&n);
	For(i,1,n){
		ll w;
		scanf("%lld",&w);
		G.add(i*2-1,i*2,w);
	}
	For(i,1,n-1){
		int x,y; ll w1,w2;
		scanf("%d%d%lld%lld",&x,&y,&w1,&w2);
		G.add(x*2-1,y*2-1,w1);
		G.add(x*2,y*2,w2);
		T.add(x,y);
	}
	scanf("%d",&Q);
	For(i,1,Q){
		int x,y;
		scanf("%d%d",&x,&y);
		int bex=(x+1)/2;
		int bey=(y+1)/2;
		T.addQ(bex,bey,x,y,i);
		ans[i]=1ll<<60;
	}
	T.solve(1,n);
	For(i,1,Q)
		printf("%lld\n",ans[i]);
}