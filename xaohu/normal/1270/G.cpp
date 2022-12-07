#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

const int N = 1 << 20;

int T, n, a[N], vis[N];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> T;
	while (T--) {
		cin >> n;
		rep(i, 1, n + 1) 
			cin >> a[i], vis[i] = 0;
		int u = 1;
		for (; !vis[u]; u -= a[u]) 
			vis[u] = 1;
		vector<int> res;
		for (int v = u; res.empty() || v != u; v -= a[v])
			res.push_back(v);
		cout << sz(res) << "\n";
		for (auto e : res)
			cout << e << " ";
		cout << "\n";
	}
	return 0;
}