#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define PB push_back
#define MP make_pair
typedef long long LL;
const LL MOD = 998244353;
const int N = 150010;

vector<int> g[N];
int n,fa[N],h[N];

int find(int x){return x==fa[x]?x:find(fa[x]);}
void dfs(int x){
	printf("%d ",x);
	for(auto u:g[x]){
		dfs(u);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	rep(i,1,n) fa[i] = i, h[i] = 1;
	rep(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		x = find(x); y = find(y);
		if(h[y]>h[x]){
			fa[x] = y;
			g[y].push_back(x);
		}
		else{
			fa[y] = x;
			g[x].push_back(y);
			if(h[x]==h[y])++h[x];
		}
	}
	rep(i,1,n)if(fa[i]==i)dfs(i);
	printf("\n");
	return 0;
}