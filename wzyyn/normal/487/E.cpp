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
const int N=200005;
int n,m,Q,nd,a[N];
vector<int> e[N],E[N]; 
int dfn[N],low[N],stk[N];
void Add(int x,int y){
	//printf("E %d %d\n",x,y);
	E[x].PB(y); E[y].PB(x);
}
void tarjan(int x,int fa){
	dfn[x]=low[x]=++*dfn;
	stk[++*stk]=x;
	for (auto i:e[x]) if (i!=fa)
		if (!dfn[i]){
			int p=*stk;
			tarjan(i,x);
			low[x]=min(low[x],low[i]);
			if (low[i]>=dfn[x]){
				Add(++nd,x);
				for (;*stk>p;--*stk)
					Add(nd,stk[*stk]);
			}
		}
		else low[x]=min(low[x],dfn[i]);
}

set<pii> S[N];
int sz[N],fa[N],dep[N];
int pos[N],top[N];
void dfs1(int x){
	sz[x]=1;
	for (auto i:E[x])
		if (i!=fa[x]){
			fa[i]=x;
			dep[i]=dep[x]+1;
			dfs1(i);
			sz[x]+=sz[i];
		}
}
void dfs2(int x,int tp){
	//cout<<x<<' '<<tp<<endl;
	dfn[x]=++*dfn;
	pos[*dfn]=x;
	top[x]=tp;
	int k=0;
	for (auto i:E[x])
		if (i!=fa[x]&&sz[i]>sz[k])
			k=i;
	if (k) dfs2(k,tp);
	for (auto i:E[x])
		if (i!=fa[x]&&i!=k)
			dfs2(i,i);
}


struct TREE{
	int t[N*4],nn;
	void build(int n){
		for (nn=1;nn<=n;nn<<=1);
		For(i,0,nn-1) t[i+nn]=1<<30;
		For(i,1,n) t[i+nn]=a[pos[i]];
		Rep(i,nn-1,1) t[i]=min(t[i<<1],t[i<<1|1]);
	}
	void change(int x,int v){
		x+=nn; t[x]=v;
		for (x>>=1;x;x>>=1) t[x]=min(t[x<<1],t[x<<1|1]);
	}
	int ask(int l,int r){
		int ans=1<<30;
		l+=nn-1; r+=nn+1;
		for (;l^r^1;l>>=1,r>>=1){
			if (!(l&1)) ans=min(ans,t[l^1]);
			if (r&1)	ans=min(ans,t[r^1]);
		}
		return ans;
	}
}TR;
void change(int x,int y){
	if (fa[x]>n) S[fa[x]].erase(pii(a[x],x));
	TR.change(dfn[x],a[x]=y);
	if (fa[x]>n) S[fa[x]].insert(pii(a[x],x));
	if (fa[x]>n) TR.change(dfn[fa[x]],a[fa[x]]=S[fa[x]].begin()->fi);
}
int ask(int x,int y){
	int ans=1<<30;
	for (;top[x]!=top[y];x=fa[top[x]]){
		//cout<<x<<' '<<y<<endl;
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		ans=min(ans,TR.ask(dfn[top[x]],dfn[x]));
	} 
	if (dep[x]<dep[y]) swap(x,y);
	ans=min(ans,TR.ask(dfn[y],dfn[x]));
	if (y>n) ans=min(ans,a[fa[y]]);
	return ans; 
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d%d",&n,&m,&Q); nd=n;
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	tarjan(1,0); ++nd;
	For(i,1,*stk) Add(nd,stk[i]);
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	//return 0;
	dfs1(1); dfs2(1,1);
	For(i,n+1,nd) S[i].insert(pii(1<<30,1<<30));
	For(i,n+1,nd) for (auto j:E[i])
		if (j!=fa[i]) S[i].insert(pii(a[j],j));
	For(i,n+1,nd) a[i]=S[i].begin()->fi;
	//cout<<a[n+1]<<' '<<S[n+1].begin()->fi<<endl;
	TR.build(nd);
	while (Q--){
		char s[5]; int x,y;
		scanf("%s%d%d",s,&x,&y);
		if (s[0]=='C') change(x,y);
		else printf("%d\n",ask(x,y));
	}
}