#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int N = 2e5+5;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, x, y, a[2];
vector<int> g[N];

void dfs(int x, int fa, int grp){
	a[grp]++;
	for(auto u:g[x]) if(u!=fa)
		dfs(u, x, 1-grp);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	scanf("%d",&n);
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		g[x].PB(y), g[y].PB(x);
	}
	
	dfs(1,0,0);
	cout<<min(a[0],a[1])-1<<endl;
	return 0;
}