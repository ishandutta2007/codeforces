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
const int N=150005;
vector<int> e[N],v[N];
int n,m,l,rt;
int vis[N],sz[N],co[N];
int q[N],dfn[N],ed[N];
int fa[N][20],dep[N];
int X[N],Y[N],Del[N];
ll ans;
void dfs1(int x){
	q[++*q]=x;
	dfn[x]=++*dfn;
	for (auto i:e[x])
		if (!vis[i]&&i!=fa[x][0]){
			fa[i][0]=x;
			dep[i]=dep[x]+1;
			dfs1(i);
		}
	ed[x]=*dfn;
}
void color(int x,int c){
	co[x]=c;
	for (auto i:e[x])
		if (!vis[i]&&i!=fa[x][0])
			color(i,c);
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	Rep(i,17,0)
		if (tmp&(1<<i))
			x=fa[x][i];
	Rep(i,17,0)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
int jump(int x,int d){
	Rep(i,17,0)
		if (d&(1<<i))
			x=fa[x][i];
	return x;
}
namespace count1{
	int S[N];
	void update1(int x){
		for (auto i:v[x]) if (!Del[i])
			if (co[X[i]]==co[Y[i]]){
				int L=LCA(X[i],Y[i]);
				assert(dep[L]);
				if (dep[x]-dep[L]>=l){
					//cout<<"find "<<x<<' '<<i<<' '<<L<<endl;
					++S[jump(x,dep[x]-dep[L]-l)];
				}
			}
		for (auto i:e[x])
			if (i!=fa[x][0]&&!vis[i])
				update1(i);
	}
	void update2(int x,int sum){
		sum+=S[x];
		//cout<<x<<' '<<sum<<endl;
		for (auto i:v[x]) if (!Del[i])
			if (co[X[i]]!=co[Y[i]])
				ans+=2*sum;
		for (auto i:e[x])
			if (i!=fa[x][0]&&!vis[i])
				update2(i,sum);
	}
	void count(int x){
		For(i,1,*q) S[q[i]]=0;
		update1(x);
		update2(x,0);
	}
}
namespace count2{
	const int M=10000005;
	int t[M],ls[M],rs[M];
	int nd,rt[N],id[N];
	set<int> S[N];
	void insert(int &k,int l,int r,int p,int v){
		if (!k) k=++nd;
		t[k]+=v;
		if (l==r) return;
		int mid=(l+r)/2;
		if (p<=mid) insert(ls[k],l,mid,p,v);
		else insert(rs[k],mid+1,r,p,v);
	}
	int ask(int k,int l,int r,int x,int y){
		if (!k||(l==x&&r==y)) return t[k];
		int mid=(l+r)/2;
		if (y<=mid) return ask(ls[k],l,mid,x,y);
		if (x>mid) return ask(rs[k],mid+1,r,x,y);
		return ask(ls[k],l,mid,x,mid)+ask(rs[k],mid+1,r,mid+1,y);
	}
	void insert_ele0(int id,int p,int v){
		int opp=(co[X[v]]==co[p]?Y[v]:X[v]);
		//cout<<"insert "<<id<<' '<<p<<' '<<v<<' '<<opp<<' '<<ans<<endl;
		if (dep[p]>=l){
			ans+=2*t[rt[id]];
			//cout<<"opp "<<opp<<endl;
			if (dep[opp]){
				opp=jump(opp,dep[opp]-1);
				ans-=ask(rt[id],1,*dfn,dfn[opp],ed[opp]);
			}
		}
		else{
			if (dep[p]+dep[opp]>=l){
				opp=jump(opp,dep[p]+dep[opp]-l);
				//cout<<"opp2 "<<opp<<endl;
				ans+=ask(rt[id],1,*dfn,dfn[opp],ed[opp]);
			}
		}
	}
	int merge(int x,int y){
		if (!x||!y) return x+y;
		t[x]+=t[y];
		ls[x]=merge(ls[x],ls[y]);
		rs[x]=merge(rs[x],rs[y]);
		return x;
	}
	void insert_ele1(int id,int p,int v){
		S[id].insert(v);
		int opp=(co[X[v]]==co[p]?Y[v]:X[v]);
		insert(rt[id],1,*dfn,dfn[opp],1);
	}
	void merge(int p,int &x,int &y){
		if (S[x].size()<S[y].size()) swap(x,y);
		for (auto i:S[y]) insert_ele0(x,p,i),S[x].insert(i);
		rt[x]=merge(rt[x],rt[y]);
	}
	void update1(int x){
		id[x]=x; rt[x]=0; S[x].clear();
		for (auto i:v[x])
			if (!Del[i]&&co[X[i]]!=co[Y[i]]){
				insert_ele0(id[x],x,i);
				insert_ele1(id[x],x,i);
			}
		for (auto i:e[x])
			if (i!=fa[x][0]&&!vis[i])
				update1(i),merge(x,id[x],id[i]);
	}
	void update2(int x){
		for (auto i:v[x])
			if (!Del[i]&&co[X[i]]!=co[Y[i]])
				Del[i]=1;
		for (auto i:e[x])
			if (i!=fa[x][0]&&!vis[i])
				update2(i);
	}
	void count(int x){
		for (;nd;ls[nd]=rs[nd]=t[nd]=0,nd--);
		for (auto i:e[x]) if (!vis[i]) update1(i);
		update2(x);
	}
}
void solver(int x){
	//cout<<"solver "<<x<<endl;
	*dfn=*q=fa[x][0]=dep[x]=0;
	dfs1(x); co[x]=x;
	//cout<<"solver "<<x<<endl;
	for (auto i:e[x])
		if (!vis[i]) color(i,i);
	//For(i,1,n) cout<<co[i]<<' '; cout<<endl;
	For(i,1,17) For(j,1,*q)
		fa[q[j]][i]=fa[fa[q[j]][i-1]][i-1];
	//cout<<ans<<endl;
	count1::count(x);
	//cout<<ans<<endl;
	count2::count(x);
}
void dfs(int x,int fa,int n){
	sz[x]=1; int mx=0;
	for (auto i:e[x])
		if (i!=fa&&!vis[i]){
			dfs(i,x,n);
			sz[x]+=sz[i];
			mx=max(mx,sz[i]);
		}
	if (sz[x]*2>n&&mx*2<=n) rt=x;
}
void divide(int x,int n){
	if (n==1) return;
	dfs(x,0,n);
	assert(sz[x]==n);
	//cout<<x<<' '<<n<<' '<<rt<<' '<<ans<<endl;
	vis[x=rt]=1;
	solver(x);
	for (auto i:e[x]) if (!vis[i])
		divide(i,sz[x]>sz[i]?sz[i]:n-sz[x]);
}
int main(){
	#ifdef zyy
		freopen("1.in","r",stdin);
	#endif
	scanf("%d%d%d",&n,&m,&l);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	For(i,1,m){
		scanf("%d%d",&X[i],&Y[i]);
		v[X[i]].PB(i);
		v[Y[i]].PB(i);
	}
	divide(1,n);
	printf("%lld\n",ans/2);
}