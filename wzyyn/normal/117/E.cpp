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
const int N=100005;
int n,Q,flg,top[N],dfn[N];
int sz[N],dep[N],fa[N];
int co[N],q[N],vis[N];
vector<int> e[N],E[N];
struct TREE{
	int s0[N*4],s1[N*4],rev[N*4]; 
	void build(int k,int l,int r){
		s0[k]=r-l+1; s1[k]=0;
		if (l==r) return;
		int mid=(l+r)/2;
		build(k*2,l,mid);
		build(k*2+1,mid+1,r);
	}
	void rever(int k){
		rev[k]^=1;
		swap(s0[k],s1[k]);
	}
	void pushdown(int k){
		if (!rev[k]) return;
		rever(k*2); rever(k*2+1);
		rev[k]=0;
	}
	void change(int k,int l,int r,int x,int y){
		if (x<=l&&r<=y)
			return rever(k);
		int mid=(l+r)/2;
		pushdown(k);
		if (x<=mid) change(k*2,l,mid,x,y);
		if (y>mid) change(k*2+1,mid+1,r,x,y);
		s0[k]=s0[k*2]+s0[k*2+1];
		s1[k]=s1[k*2]+s1[k*2+1];
	}
}T1,T2;
void change(int x,int y){
	for (;top[x]!=top[y];x=fa[top[x]]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		T1.change(1,1,n,dfn[top[x]],dfn[x]);
	}
	if (dep[x]>dep[y]) swap(x,y);
	if (x!=y) T1.change(1,1,n,dfn[x]+1,dfn[y]);
}
void dfs(int x){
	sz[x]=1;
	dep[x]=dep[fa[x]]+1;
	for (auto i:e[x]) if (i!=fa[x])
		if (!sz[i]){
			fa[i]=x;
			E[x].PB(i);
			dfs(i);
			sz[x]+=sz[i];
		}
		else if (dep[i]<dep[x]){
			//cout<<x<<' '<<i<<'
			for (int j=x;j!=i;j=fa[j]) q[++*q]=j;
			q[++*q]=i;
		}
}
void dfs2(int x){
	if (!top[x]) top[x]=x;
	dfn[x]=++*dfn;
	int hson=0;
	for (auto i:E[x])
		if (i!=fa[x]&&sz[i]>sz[hson])
			hson=i;
	if (hson){
		top[hson]=top[x];
		dfs2(hson);
	}
	for (auto i:E[x])
		if (i!=fa[x]&&i!=hson)
			dfs2(i);
}
void getco(int x,int fa,int c){
	co[x]=c;
	for (auto i:e[x])
		if (i!=fa&&!vis[i])
			getco(i,x,c);
}
void init(){
	scanf("%d%d",&n,&Q);
	For(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs(1); dfs2(1);
	For(i,1,*q) vis[q[i]]=1;
	For(i,1,*q) getco(q[i],0,i);
	//cerr<<233<<' '<<*q<<endl;
	//For(i,1,*q) cerr<<q[i]<<' '; cerr<<endl;
	//For(i,1,n) cerr<<co[i]<<' '; cerr<<endl;
	T1.build(1,1,n);
	T2.build(1,1,*q);
}
void solve(){
	int x,y;
	scanf("%d%d",&x,&y);
	if (co[x]==co[y]) change(x,y);
	else{
		change(x,q[co[x]]); x=co[x];
		change(y,q[co[y]]); y=co[y];
		//cout<<x<<' '<<y<<endl;
		if ((*q)%2==0&&(x+(*q)/2-1)%(*q)+1==y)
			if (q[x%(*q)+1]>q[(x+(*q)-2)%(*q)+1]) swap(x,y);
			else;
		else if ((y+(*q)-x)%(*q)>(*q)/2) swap(x,y);
		//cout<<x<<' '<<y<<endl;
		if (x<=y){
			T2.change(1,1,*q,x,y-1);
			change(q[x],q[y]);
		}
		else{
			flg^=1;
			T2.change(1,1,*q,x,*q);
			if (y!=1) T2.change(1,1,*q,1,y-1);
			change(q[x],q[*q]); change(q[1],q[y]);
		}
	}
	int ans=n-T1.s1[1]-flg;
	if (T2.s1[1]==*q) ans++;
	//printf("%d %d %d\n",ans,T1.s1[1],flg);
	cout<<ans<<endl;
}
int main(){
	//freopen("1.in","r",stdin);
	init();
	//cerr<<233<<endl;
	while (Q--) solve();
}