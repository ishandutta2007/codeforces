#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		set<int> s;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			if (a % 2 == 0) {
				s.insert(a);
			}
		}

		int ans = 0;
		while (!s.empty()) {
			int u = *s.rbegin();
			s.erase(--s.end());
			++ans;
			if (u % 4 == 0) {
				s.insert(u / 2);	
			}
		}
		cout << ans << "\n";
	}
}