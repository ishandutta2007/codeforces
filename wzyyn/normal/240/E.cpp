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
int n,m,q[N];
int x[N],y[N],v[N];
int dfn[N],low[N];
int stk[N],vis[N];
int be[N],in[N];
vector<int> e[N];
vector<pii> E[N];
void tarjan(int x){
	dfn[x]=low[x]=++*dfn;
	stk[++*stk]=x; vis[x]=1;
	for (auto i:e[x])
		if (!dfn[i]){
			tarjan(i);
			low[x]=min(low[x],low[i]);
		}
		else if (vis[i])
			low[x]=min(low[x],dfn[i]);
	if (dfn[x]==low[x]){
		++*be;
		int y=1919810;
		for (;y!=x;){
			y=stk[(*stk)--];
			vis[y]=0;
			be[y]=*be;
		}
	}
}
void dfs(int x){
	vis[x]=1;
	for (auto i:E[x])
		if (!vis[i.fi]){
			if (i.se) q[++*q]=i.se;
			dfs(i.fi);
		}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	For(i,1,m) scanf("%d%d%d",&x[i],&y[i],&v[i]);
	For(i,1,m) if (!v[i]) e[x[i]].PB(y[i]);
	For(i,1,n) if (!dfn[i]) tarjan(i);
	For(i,1,m)
		if (!v[i]&&be[x[i]]!=be[y[i]])
			//cout<<x[i]<<' '<<y[i]<<endl;
			E[be[x[i]]].PB(pii(be[y[i]],0)),in[be[y[i]]]=1;
	For(i,1,m)
		if (v[i]&&be[x[i]]!=be[y[i]]&&!in[be[y[i]]])
			E[be[x[i]]].PB(pii(be[y[i]],i));
	dfs(be[1]);
	For(i,1,n)
		if (!vis[be[i]])
			return puts("-1"),0;
	printf("%d\n",*q);
	For(i,1,*q) printf("%d ",q[i]);
}