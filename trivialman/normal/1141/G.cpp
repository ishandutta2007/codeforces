#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 200010;

vector<int> g[N];
map<pair<int, int>, int> id;
int n, k, x, y, num, dgr[N], ans[N];
bool v[N];

void dfs(int u, int firm){
	v[u] = true;
	int y = 1;
	if(g[u].size()>num){
		for(auto x:g[u])if(!v[x]){
			int x1 = u, x2 = x;
			if(x1>x2)swap(x1,x2);
			ans[id[MP(x1,x2)]] = 1;
			dfs(x,1);
		}
	}else{
		for(auto x:g[u])if(!v[x]){
			if(y==firm)++y;
			int x1 = u, x2 = x;
			if(x1>x2)swap(x1,x2);
			ans[id[MP(x1,x2)]] = y;
			dfs(x,y);
			++y;
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE 
	freopen("test.in","r",stdin);
	#endif
	scanf("%d%d",&n,&k);
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		if(x>y)swap(x,y);
		id[MP(x,y)]=i;
		g[x].PB(y),g[y].PB(x);
	}
	rep(i,1,n) dgr[i] = g[i].size();
	sort(dgr+1,dgr+n+1);
	num = dgr[n-k];
	dfs(1,0);
	printf("%d\n", num);
	rep(i,1,n-1) printf("%d ", ans[i]);
}