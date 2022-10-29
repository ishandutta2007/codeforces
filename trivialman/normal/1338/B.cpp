#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int N = 1e5+5;
mt19937 rng(time(0));

int n, x, y, high, num, low;
bool f1 =  false, f2 = false;
bool v[N];
vector<int> g[N];

void dfs(int x, int d, int &num){
	v[x] = true;
	if(g[x].size()==1){
		if (d%2) f1 = true;
		else f2 = true;
	}
	int cnt = 0;
	for(auto u:g[x]) if(!v[u]) {
		if(g[u].size()==1) cnt++;
		dfs(u, d+1, num);
	}
	num -= max(cnt-1, 0);
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
	int root = 1;
	while(g[root].size()==1) root++;
	
	memset(v,0,sizeof v);
	num = n-1;
	dfs(root, 0, num);
	
	low = f1&&f2 ? 3 : 1;
	printf("%d %d\n",low , num);
	return 0;
}