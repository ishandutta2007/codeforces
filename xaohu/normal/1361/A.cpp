#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
const int N = 500000;
int n, m, a[N], b[N], c[N], ord[N];
vector<int> e[N];
int main() {
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for (int i = 0; i < n; i++) 
		cin >> a[i], ord[i] = i;
	sort(ord, ord + n, [&](int x, int y) {
		return a[x] < a[y];
	});
	memset(c, -1, sizeof c);
	bool bad = 0;
	for (int i = 0; i < n; i++) {
		int u = ord[i];
		for (auto v : e[u])
			c[b[v]] = u;
		for (int j = 1; j < a[u]; j++)
			if (c[j] != u)
				bad = 1;
		if (c[a[u]] == u)
			bad = 1;
		b[u] = a[u];
	}
	if (bad)
		cout << "-1\n";
	else {
		for (int i = 0; i < n; i++)
			cout << ord[i] + 1 << " ";
		cout << endl;
	}
	return 0;
}