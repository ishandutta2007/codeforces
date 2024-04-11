#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define PB push_back
typedef long long LL;
const int N = 2e5+5;

int n, x, y, t[N], h[N], in[N], out[N];
vector<int> g[N];
LL dp[N][2];
bool v[N]; 

void dfs(int x, int fa){
	v[x] = true;
	vector<LL> tmp(0);
	LL sum = 0;	
	for (auto u : g[x]) if (u!=fa) {
		dfs(u, x);
		tmp.PB(dp[u][0] - dp[u][1]);
		sum += dp[u][0];
	}
	
	int sz = tmp.size();
	sort(tmp.begin(), tmp.end());
	rep(k,0,sz){ //k down
		LL f1 = 1ll * min(in[x]+sz-k, out[x]+k+1) * t[x];
		LL f2 = 1ll * min(in[x]+sz-k+1, out[x]+k) * t[x];
		if (fa==0) f1 = f2 = 1ll * min(in[x]+sz-k, out[x]+k) * t[x];
		dp[x][0] = max(dp[x][0], f1 + sum);
		dp[x][1] = max(dp[x][1], f2 + sum);
		if (k<sz) sum -= tmp[k];
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",t+i);
	rep(i,1,n) scanf("%d",h+i);
	
	LL ans = 0;
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		ans += t[x] + t[y];
		if (h[x]>h[y]) swap(x,y);
		if (h[x]<h[y]) {
			out[x]++, in[y]++;
			if (in[x] && out[x]) in[x]--, out[x]--, ans -= t[x];
			if (in[y] && out[y]) in[y]--, out[y]--, ans -= t[y];
		} else
			g[x].PB(y), g[y].PB(x);
	}
	memset(v,0,sizeof v);
	rep(i,1,n) if(!v[i]) dfs(i, 0), ans -= dp[i][0];
	
	cout<<ans<<endl;
	return 0;
}