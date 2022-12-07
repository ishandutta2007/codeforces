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

const int N=200005;
int n,Q;
int fa[N],sz[N],dep[N];
int dfn[N],ed[N],pos[N],top[N];
vector<int> e[N];

void dfs1(int x){
	sz[x]=1;
	for (auto i:e[x])
		if (i!=fa[x]){
			fa[i]=x;
			dep[i]=dep[x]+1;
			dfs1(i);
			sz[x]+=sz[i];
		}
}
void dfs2(int x,int tp){
	dfn[x]=++*dfn;
	pos[*dfn]=x;
	top[x]=tp;
	int k=0;
	for (auto i:e[x])
		if (i!=fa[x]&&sz[i]>sz[k])
			k=i;
	if (k) dfs2(k,tp);
	for (auto i:e[x])
		if (i!=fa[x]&&i!=k)
			dfs2(i,i);
	ed[x]=*dfn;
}
int LCA(int x,int y){
	for (;top[x]!=top[y];x=fa[top[x]])	
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
	return dep[x]<dep[y]?x:y;
}
int kthfa(int x,int k){
	for (;;)
		if (dep[x]-dep[top[x]]>=k)
			return pos[dfn[x]-k];
		else{
			k-=dep[x]-dep[top[x]]+1;
			x=fa[top[x]];
		}
}
struct Tarr{
	int a[N];
	void add(int x,int v){
		for (;x<=n;x+=x&(-x)) a[x]+=v;
	}
	int ask(int x){
		int s=0;
		for (;x;x-=x&(-x)) s+=a[x];
		return s;
	}
}T1,T2;
struct DFtree{
	vector<int> v1[N];
	vector<int> v2[N];
	int dis[20][N],dep[N];
	int fa[N],sz[N],vis[N],rt;
	
	void dfs(int x,int fa,int n){
		sz[x]=1;
		int mx=0;
		for (auto i:e[x])
			if (i!=fa&&!vis[i]){
				dfs(i,x,n);
				sz[x]+=sz[i];
				mx=max(mx,sz[i]);
			}
		if (sz[x]*2>=n&&mx*2<n) rt=x;
	}
	void dfs2(int x,int fa,int *d){
		d[x]=d[fa]+1;
		for (auto i:e[x])
			if (i!=fa&&!vis[i]) dfs2(i,x,d);
	}
	int solve(int x,int n,int d){
		//cout<<x<<' '<<n<<' '<<d<<endl;
		dfs(x,0,n);
		vis[x=rt]=1; dep[x]=d;
		v1[x].resize(n+2);
		for (auto i:e[x]) if (!vis[i]) dfs2(i,x,dis[d]);
		for (auto i:e[x]) if (!vis[i]){
			int v=(sz[i]<sz[x]?sz[i]:n-sz[x]);
			int p=solve(i,v,d+1);
			v2[p].resize(v+2);
			fa[p]=x;
		}
		return x;
	}
	void init(){
		fa[solve(1,n,1)]=0;
	}
	void chg(vector<int> &x,int y,int v){
		int n=x.size();
		for (++y;y<n;y+=y&(-y)) x[y]+=v;
	}
	int query(vector<int> &x,int y){
		int n=x.size(),s=0;
		y=min(n-1,max(0,y+1));
		for (;y;y-=y&(-y)) s+=x[y];
		return s;
	}
	void add(int x,int v){
		chg(v1[x],0,v);
		for (int p=x;fa[x];){
			int y=fa[x],d=dep[y];
			chg(v1[y],dis[d][p],v);
			chg(v2[x],dis[d][p],v);
			x=y;
		}
	}
	int ask(int x,int v){
		int ans=query(v1[x],v);
		for (int p=x;fa[x];){
			int y=fa[x],d=dep[y];
			ans+=query(v1[y],v-dis[d][p]);
			ans-=query(v2[x],v-dis[d][p]);
			x=y;
		}
		return ans;
	}
}T3;
int sum[N];
set<pii> S;
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs1(1);
	dfs2(1,1);
	T3.init();
	int rem=0;
	while (Q--){
		int op,x,y;
		scanf("%d",&op);
		if (op!=3){
			scanf("%d%d",&x,&y);
			int L=LCA(x,y),v=(op==1?1:-1);
			//cout<<x<<' '<<y<<' '<<L<<endl;
			T1.add(dfn[x],v);
			T1.add(dfn[y],v);
			T1.add(dfn[L],-v);
			T2.add(dfn[L],v);
			T3.add(L,v);
			if (sum[L]) S.erase(pii(dep[L],L));
			sum[L]+=v; rem+=v;
			if (sum[L]) S.insert(pii(dep[L],L));
		}
		else{
			assert(rem);
			scanf("%d",&x);
			int p=S.rbegin()->se;
			int p2=kthfa(p,min(x,dep[p]));
			int p3=kthfa(p2,min(x,dep[p2]));
			//cout<<p<<' '<<p2<<' '<<rem<<' '<<T1.ask(ed[p2])-T1.ask(dfn[p2]-1)<<' '<<T2.ask(ed[p2])-T2.ask(dfn[p2]-1)<<' '<<T3.ask(p,x)<<endl;
			if ((T1.ask(ed[p3])-T1.ask(dfn[p3]-1))!=rem) puts("No");
			else if (T2.ask(ed[p3])-T2.ask(dfn[p3]-1)!=T3.ask(p2,x)) puts("No");
			else puts("Yes");
		}
	}
	
}