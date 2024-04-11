#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const LL INF = 1e17;
const int N = 300010;

vector<int> g[N];
int n,x,nleaf=0,a[N],stay[N];

void dfs(int u){
	int sum=0,mi=3e7;
	for(auto x:g[u]){
		if(!stay[x])dfs(x);
		sum+=stay[x];
		mi=min(mi,stay[x]);
	}
	if(!sum){
		++nleaf;
		stay[u]=1;return;
	}
	stay[u] = (a[u]==0?sum:mi);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",a+i);
	rep(i,1,n-1){
		scanf("%d",&x);
		g[x].PB(i+1);
	}
	memset(stay,0,sizeof stay);
	dfs(1);
	cout<<nleaf-stay[1]+1<<endl;
	return 0;
}