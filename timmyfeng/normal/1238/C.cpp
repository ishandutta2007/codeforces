#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int h, n;
		cin >> h >> n;
		vector<int> p(n);
		for (auto& i : p) {
			cin >> i;
		}
		p.push_back(0);
		
		int ans = 0;
		for (int i = 0; i + 1 < n; ++i ){
			p[i] = p[i + 1] + 1;
			if (p[i] - p[i + 2] > 2) {
				++ans;
			} else {
				++i;
			}
		}
		cout << ans << '\n';
	}
}