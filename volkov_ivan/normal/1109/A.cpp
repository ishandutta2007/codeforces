#include <iostream>

using namespace std;

const int MAX_V = 1 << 21;
pair <int, int> cnt[MAX_V];


int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < MAX_V; i++) {
		cnt[i] = make_pair(0, 0);
	}
	int x = 0;
	cnt[0].first = 1;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		x ^= t;
		if (i % 2 == 0) cnt[x].second++;
		else cnt[x].first++;
	}
	long long ans = 0;
	for (int i = 0; i < MAX_V; i++) {
		long long a = cnt[i].first, b = cnt[i].second;
		ans += a * ((a - 1)) / 2;
		ans += b * ((b - 1)) / 2;
	}
	cout << ans << endl;
	return 0;
}