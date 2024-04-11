#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int len = 0;
	int cur = 0;
	vector<int> segments;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (a != cur) {
			segments.push_back(len);
			len = 0;
			cur = a;
		}
		++len;
	}
	segments.push_back(len);

	int ans = 0;
	for (int i = 0; i < int(segments.size()) - 1; ++i) {
		ans = max(ans, min(segments[i], segments[i + 1]));
	}
	cout << ans * 2 << "\n";
}