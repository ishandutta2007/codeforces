#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n, x, y;
		cin >> n >> x >> y;
		vector<int> ans;
		for (int d = 1; d <= y - x; ++d) {
			if ((y - x) % d != 0) continue;
			vector<int> res;
			bool foundx = false;
			int cur = y;
			int need = n;
			while (cur >= 1 && need > 0) {
				res.push_back(cur);
				foundx |= cur == x;
				--need;
				cur -= d;
			}
			cur = y;
			while (need > 0) {
				cur += d;
				res.push_back(cur);
				--need;
			}
			sort(res.begin(), res.end());
			if (need == 0 && foundx) {
				if (ans.empty() || ans.back() > res.back()) {
					ans = res;
				}
			}
		}
		assert(!ans.empty());
		for (auto it : ans) cout << it << " ";
		cout << endl;
		
	}
	
	return 0;
}