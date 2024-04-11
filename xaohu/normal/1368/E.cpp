#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

const int N = 1 << 18;

int T, n, m, c[N];
vector<int> e[N];

void solve() {
	cin >> n >> m;
	rep(i, 1, n + 1)
		e[i].clear(), c[i] = 0;
	while (m--) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
	}
	vector<int> res;
	rep(i, 1, n + 1) {
		if (c[i] < 2)
			for (auto j : e[i])
				c[j] = max(c[j], c[i] + 1);
		else
			res.push_back(i);
	}
	cout << sz(res) << endl;
	for (auto e : res)
		cout << e << " ";
	cout << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0); 
	cin >> T;
	while (T--) 
		solve();
	return 0;
}