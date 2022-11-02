#include <iostream>
#include <vector>

using namespace std;

int main() {
	// freopen("input.txt", "r", stdin);
	int w, l;
	cin >> w >> l;
	vector<int> maxCnt(w);
	for (int i = 1; i < w; i++) {
		cin >> maxCnt[i];
	}
	vector<int> cnt(w);
	cnt[0] = 1e9;
	int j = 0;
	for (int i = 1; i < w; i++) {
		while (i - j > l) {
			++j;
		}
		while ((j < i) && (cnt[i] < maxCnt[i])) {
			// cerr << cnt[i] << " " << j << " " << maxCnt[i] << endl;
			if (cnt[i] + cnt[j] <= maxCnt[i]) {
				cnt[i] += cnt[j];
				cnt[j] = 0;
				++j;
			} else {
				int maxAdd = min(cnt[j], maxCnt[i] - cnt[i]);
				cnt[j] -= maxAdd;
				cnt[i] += maxAdd;
			}
		}
	}
	int res = 0;
	for (int i = w - l; i < w; i++) {
		res += cnt[i];
	}
	cout << res << endl;
}