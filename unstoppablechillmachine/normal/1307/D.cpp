#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int INF = 1e9 + 10;
const int N = 2e5 + 10;
vector<int> g[N];
vector<int> get_dist(int start, int n) {
	vector<int> d(n + 1, INF);
	d[start] = 0;
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto u : g[v]) {
			if (d[u] == INF) {
				d[u] = d[v] + 1;
				q.push(u);
			}
		}
	}
	return d;
}

struct T {
	int mn1, mn2, id1, id2;
	T() : mn1(-INF), mn2(-INF), id1(0), id2(0) {};
};

T suf[N];

void update(int val, int v, int pos) {
	if (val > suf[pos].mn1) {
		suf[pos].mn2 = suf[pos].mn1;
		suf[pos].id2 = suf[pos].id1;
		suf[pos].mn1 = val;
		suf[pos].id1 = v;
	}
	else if (val > suf[pos].mn2) {
		suf[pos].mn2 = val;
		suf[pos].id2 = v;
	}
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);		
  int n, m, k;
  cin >> n >> m >> k;
  vector<bool> kek(n + 1);
  for (int i = 1; i <= k; i++) {
  	int x;
  	cin >> x;
  	kek[x] = true;
  }
  for (int i = 0; i < m; i++) {
  	int u, v;
  	cin >> u >> v;
  	g[u].pb(v);
  	g[v].pb(u);
  }
  vector<int> d1 = get_dist(1, n), 
  dn = get_dist(n, n);
  for (int i = 1; i <= n; i++) {
  	if (kek[i]) {
  		update(d1[i], i, dn[i]);
  		//cout << dn[i] << ' ' << d1[i] << '\n';
  	}
  }
  for (int i = n - 1; i >= 0; i--) {
  	update(suf[i + 1].mn1, suf[i + 1].id1, i);
  	update(suf[i + 1].mn2, suf[i + 1].id2, i);	
  }
  int l = 0, r = d1[n] + 1;
  while (r - l > 1) {
  	int mid = (l + r) / 2;
  	bool ok = false;
  	for (int i = 1; i <= n; i++) {
  		if (!kek[i]) {
  			continue;
  		}
  		int can = max(mid - d1[i] - 1, 0);
  		if (suf[can].id1 == i) {
  			if (dn[i] + suf[can].mn2 + 1 >= mid) {
  				ok = true;
  				break;
  			}
  		}
  		else {
  			if (dn[i] + suf[can].mn1 + 1 >= mid) {
  				ok = true;
  				break;
  			}
  		}
  	}
  	if (ok) {
  		l = mid;
  	}
  	else {
  		r = mid;
  	}
  }
  cout << l << '\n';
}