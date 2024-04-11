#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	vector<int> cnt(200 * 1000 + 1);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++cnt[x];
		if (cnt[x] > 2) {
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl << count(cnt.begin(), cnt.end(), 2) << endl;
	for (int i = 0; i <= 200 * 1000; ++i) {
		if (cnt[i] == 2) {
			cout << i << " ";
			--cnt[i];
		}
	}
	cout << endl << count(cnt.begin(), cnt.end(), 1) << endl;
	for (int i = 200 * 1000; i >= 0; --i) {
		if (cnt[i] == 1) {
			cout << i << " ";
			--cnt[i];
		}
	}
	cout << endl;
	
	assert(count(cnt.begin(), cnt.end(), 0) == 200 * 1000 + 1);
	
	return 0;
}