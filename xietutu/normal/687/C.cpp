#include <bits/stdc++.h>
using namespace std;
bool f[505][505];
int n, K;
vector<int> ans;
int main() {
	scanf("%d%d", &n, &K);
	f[0][0] = true;
	for (int i = 1; i <= n; ++i) {
		int v;
		scanf("%d", &v);
		for (int j = K; j >= 0; --j)
			for (int k = K; k >= 0; --k) {
				if (v <= j) f[j][k] |= f[j - v][k];
				if (v <= k) f[j][k] |= f[j][k - v];
			}
	}
	for (int j = 0; j <= K; ++j)
		if (f[j][K - j]) ans.push_back(j);
	cout << ans.size() << endl;
	for (int& v : ans) printf("%d ", v);
}