#include <iostream>
#include <vector>
#define int long long

using namespace std;

signed main() {
	//freopen("Desktop/input.txt", "r", stdin);
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int cur = 0;
	pair <int, int> a[n];
	vector <int> poses[64];
	int s0 = 0;
	for (int i = 0; i < n; i++) {
		int val, mask;
		cin >> val >> mask;
		for (int j = 0; j < 62; j++) {
			if (mask & (1ll << j)) {
				poses[j].push_back(i);
				break;
			}
		}
		s0 += val;
		a[i] = {val, mask};
	}
	for (int i = 61; i >= 0; i--) {
		int s = 0;
		for (int elem : poses[i]) {
			int c = a[elem].second & cur;
			if (__builtin_popcountll(c) % 2 == 1) s -= a[elem].first;
			else s += a[elem].first;
		}
		if (s0 > 0 && s > 0) cur |= (1ll << i);
		if (s0 < 0 && s < 0) cur |= (1ll << i);
	}
	cout << cur << endl;
	return 0;
}