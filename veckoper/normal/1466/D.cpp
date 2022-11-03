#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int Case, n, w[N], du[N];
signed main() {
	scanf("%lld", &Case);
	vector<int> ans;
	while (Case--) {
		scanf("%lld", &n);
		for (int i = 1; i <= n; ++i) du[i] = 0;
		ans.clear();
		int sm = 0;
		for (int i = 1; i <= n; ++i) scanf("%lld", w + i), sm += w[i];
		for (int i = 1, x, y; i < n; ++i) {
			scanf("%lld%lld", &x, &y);
			++du[x]; ++du[y];
		}
		for (int i = 1; i <= n; ++i) 
			while (--du[i]) ans.push_back(w[i]);
		sort(ans.begin(), ans.end(), greater<int>());
		printf("%lld ", sm);
		for (auto x: ans) printf("%lld ", sm += x);
		puts("");
	}
	return 0;
}