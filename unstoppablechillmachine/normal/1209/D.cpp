#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second
  
const int N = 1e5 + 10;
vector<pair<int, int>> g[N];
bool was[N], used[N];

void dfs(int v) {
	//cout << "DFS: " << v << '\n';
	was[v] = true;
	for (auto u : g[v]) {
		if (!was[u.F] && !used[u.S]) {
			used[u.S] = true;
			dfs(u.F);
		}
	}
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> k >> n;
  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; i++) {
  	cin >> arr[i].F >> arr[i].S;
  	g[arr[i].F].pb({arr[i].S, i});
  	g[arr[i].S].pb({arr[i].F, i});
  }
  for (int i = 0; i < n; i++) {
  	if (!used[i] && (!was[arr[i].F] || !was[arr[i].S])) {
  		//cout << "NEW COMP:" << i << '\n';
  		used[i] = true;
  		was[arr[i].S] = true;
  		dfs(arr[i].F);
  		dfs(arr[i].S);
  	}
  }
  int ans = n;
  for (int i = 0; i < n; i++) {
  	if (used[i]) {
  		ans--;
  	}
  }
  cout << ans << '\n';
}