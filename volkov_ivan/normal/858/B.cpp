#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
	int l = -1, r = 102, n, m, f, k, l1, r1, ans;
	bool flag, found = 0;
	cin >> n >> m;
	vector <pair <int, int> > mem;
	for (int i = 0; i < m; i++) {
		cin >> k >> f;
		mem.push_back(make_pair(k, f));
	}
	for (int num = 1; num < 102; num++) {
		flag = 1;
		for (int j = 0; j < m; j++) {
			if ((mem[j].second - 1) * num < mem[j].first && mem[j].second * num >= mem[j].first) {} else {
				flag = 0;
				break;
			}
		}
		if (flag) {
			if (!found) {
				found = 1;
				//cout << num << endl;
				ans = ceil(double(n) / num);
			} else {
				if (ans != ceil(double(n) / num)) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}
	if (!found) {
		cout << "-1" << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}