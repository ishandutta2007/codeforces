#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie();

	int n;
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		s.insert(a);
	}

	int ans = 0;
	while (!s.empty()) {
		int a = *s.begin();
		for (int j = a; j <= 100; j += a) {
			s.erase(j);
		}
		++ans;
	}
	cout << ans << "\n";
}