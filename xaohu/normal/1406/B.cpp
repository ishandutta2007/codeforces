#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int q, n, a;
vector <int> g[2];
 
int main() {
	scanf ("%d", &q);
	while (q--) {
		for (int i = 0; i < 2; ++i) g[i].clear();
		scanf ("%d", &n);
		bool zero = false;
		ll ans = -1e18;
		for (int i = 0; i < n; ++i) {
			scanf ("%d", &a);
			if (a < 0) g[0].push_back(a);
			if (a == 0) zero = true;
			if (a > 0) g[1].push_back(a);
		}
		if (zero) ans = 0;
		for (int i = 0; i < 2; ++i) sort(g[i].begin(), g[i].end());
		vector <int> x;
		for (int i = 0; i < 2; ++i) 
			for (int j = 0; j < g[i].size(); ++j)
				if (min(j, (int)g[i].size() - j - 1) <= 5)
					x.push_back(g[i][j]);
		for (int A = 0; A < x.size(); ++A)
		for (int B = A + 1; B < x.size(); ++B)
		for (int C = B + 1; C < x.size(); ++C)
		for (int D = C + 1; D < x.size(); ++D)
		for (int E = D + 1; E < x.size(); ++E)
			ans = max(ans, 1LL * x[A] * x[B] * x[C] * x[D] * x[E]);
		printf ("%lld\n", ans);
	}
	
	return 0;
}