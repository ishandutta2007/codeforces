#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e5;
int n;
ll ans;
vector<int> fs[mxN+1];
bool vis[mxN+1];

ll dfs(int u) {
	ll r=0;
	vis[u]=1;
	for(int f : fs[u]) {
		if(!vis[f])
			r+=dfs(f);
		r+=u/f*2;
	}
	for(int j=u; (j+=u)<=n; ) {
		if(!vis[j])
			r+=dfs(j);
		r+=j/u*2;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=2; i<=n; ++i)
		for(int j=i; (j+=i)<=n; )
			fs[j].push_back(i);
	for(int i=2; i<=n; ++i)
		if(!vis[i])
			ans=max(dfs(i), ans);
	cout << ans;
}