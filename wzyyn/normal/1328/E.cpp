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
int n,Q,fa[N];
int dep[N],dfn[N],ed[N];
vector<int> e[N];
void dfs(int x){
	dfn[x]=++*dfn;
	for (auto i:e[x])
		if (i!=fa[x]){
			fa[i]=x;
			dep[i]=dep[x]+1;
			dfs(i);
		}
	ed[x]=*dfn;
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs(1);
	while (Q--){
		int k,l=-1e9,r=1e9;
		scanf("%d",&k);
		For(i,1,k){
			int x;
			scanf("%d",&x);
			if (x!=1) x=fa[x];
			l=max(l,dfn[x]);
			r=min(r,ed[x]);
		}
		puts(l>r?"NO":"YES");
	}
}