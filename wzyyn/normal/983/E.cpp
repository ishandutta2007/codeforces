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
const int M=15000005;
int ls[M],rs[M];
int n,fa[N][20],Fa[N][20];
int dep[N],dfn[N],ed[N];
int rt[N],nd,m,Q;
vector<int> e[N];
vector<int> vec[N];
pii t[N];
void insert(int &k,int l,int r,int p){
	if (!k) k=++nd;
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) insert(ls[k],l,mid,p);
	else insert(rs[k],mid+1,r,p);
}
int merge(int x,int y){
	if (!x||!y) return x+y;
	int k=++nd;
	ls[k]=merge(ls[x],ls[y]);
	rs[k]=merge(rs[x],rs[y]);
	return k;
}
int ask(int k,int l,int r,int x,int y){
	if (!k) return 0;
	if (x<=l&&r<=y) return 1;
	int mid=(l+r)/2,ans=0;
	if (x<=mid) ans|=ask(ls[k],l,mid,x,y);
	if (y>mid) ans|=ask(rs[k],mid+1,r,x,y);
	return ans;
}
void dfs(int x){
	dfn[x]=++*dfn;
	for (auto i:e[x]) dfs(i);
	ed[x]=*dfn;
	//cout<<x<<' '<<dfn[x]<<' '<<ed[x]<<endl;
}
void dfs2(int x){
	for (auto i:vec[x]) insert(rt[x],1,n,dfn[i]);
	for (auto i:e[x]){
		dfs2(i);
		t[x]=min(t[x],t[i]);
		rt[x]=merge(rt[x],rt[i]);
	}
	if (t[x].fi>=dep[x]) Fa[x][0]=x;
	else Fa[x][0]=t[x].se;
	//cout<<x<<' '<<Fa[x][0]<<endl;
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	For(i,0,18) if (tmp&(1<<i)) x=fa[x][i];
	Rep(i,18,0) if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
int main(){//	freopen("1.in","r",stdin);
	//freopen("2.out","w",stdout); 
	scanf("%d",&n); dep[1]=1;
	For(i,1,n) t[i]=pii(1<<30,1<<30);
	For(i,2,n){
		scanf("%d",&fa[i][0]);
		dep[i]=dep[fa[i][0]]+1;
		e[fa[i][0]].PB(i);
	}
	dfs(1);
	For(i,1,18) For(j,1,n)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	scanf("%d",&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		int L=LCA(x,y);
		t[x]=min(t[x],pii(dep[L],L));
		t[y]=min(t[y],pii(dep[L],L));
		vec[x].PB(y); vec[y].PB(x);
	}
	dfs2(1);
	For(i,1,18) For(j,1,n)
		Fa[j][i]=Fa[Fa[j][i-1]][i-1];
	scanf("%d",&Q);
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		int L=LCA(x,y);
		//cout<<L<<' '<<Fa[x][18]<<' '<<Fa[y][18]<<endl;
		if (dep[Fa[x][18]]>dep[L]||
			dep[Fa[y][18]]>dep[L])
				puts("-1");
		else{
			int ans=0;
			Rep(i,17,0)
				if (dep[Fa[x][i]]>dep[L])
					x=Fa[x][i],ans+=1<<i;
			Rep(i,17,0)
				if (dep[Fa[y][i]]>dep[L])
					y=Fa[y][i],ans+=1<<i;
			//cout<<x<<' '<<y<<' '<<ans<<endl;
			if (x==L||y==L) ans++;
			else if (ask(rt[x],1,n,dfn[y],ed[y])) ans++;
			else ans+=2;
			printf("%d\n",ans);
		}
	}
}