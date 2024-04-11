#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> v[n];
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v[--x].push_back(i);
		}

		vector<int> p;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < min(int(v[i].size()), k); j++)
				p.push_back(v[i][j]);

		vector<int> ans(n, 0);
		for (int i = 0; i < k * (p.size() / k); i++)
			ans[p[i]] = i % k + 1;

		for (int i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}