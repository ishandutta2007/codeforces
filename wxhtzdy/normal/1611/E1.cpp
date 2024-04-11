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
int n,k,x[N],is[N],mn[N];
bool ans;
vector<int> e[N];
void dfs(int x,int fa,int d){
	mn[x]=(is[x]?0:1e9);
	for (int i:e[x])
		if (i!=fa){
			dfs(i,x,d+1);
			mn[x]=min(mn[x],mn[i]+1);
		}
}
void dfs2(int x,int fa,int d){
	if (d>=mn[x]) return;
	if (x!=1&&e[x].size()==1) ans=1;
	for (int i:e[x])
		if (i!=fa){
			dfs2(i,x,d+1);
		}
}
void solve(){
	scanf("%d%d",&n,&k);
	For(i,1,n) e[i].clear(),is[i]=0;
	For(i,1,k) scanf("%d",x+i),is[x[i]]=1;
	For(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].PB(v); e[v].PB(u);
	}
	dfs(1,0,0);
	ans=0; dfs2(1,0,0);
	puts(ans?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}