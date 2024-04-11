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

const int INF = 1e9 + 10;

bool prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

bool solve(int n) {
	int cur = 2, cur2 = n, add = 0;
  while (!prime(cur2)) {
  	cur2++;
  	add++;
  	if (add > n - 2) {
  		return false;
  	}
  }
  return true;	
}

signed main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<pair<int, int>> edge;
  for (int i = 1; i < n; i++) {
  	edge.pb({i, i + 1});
  }
  edge.pb({1, n});
  int cur = n, f = 1;
  while (!prime(cur)) {
  	cur++;
  	edge.pb({f, f + 2});
  	if (f & 1) f++;
  	else f += 3;
  }
  cout << SZ(edge) << '\n';
  for (auto it : edge) {
  	cout << it.F << ' ' << it.S << '\n';
  }
}