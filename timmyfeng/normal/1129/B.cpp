#include <bits/stdc++.h>
using namespace std;

const int N = 2000;
const int A = 1e6;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;

	for (int cnt = 3; cnt <= N; ++cnt) {
		for (int last = cnt - k % cnt; last <= A; last += cnt) {
			int mid = (1LL * (cnt - 1) * last - k) / cnt;
			if (mid > 0 && mid < last) {
				cout << cnt << "\n";
				for (int i = 0; i < cnt - 2; ++i) {
					cout << 0 << " ";
				}
				cout << -mid << " " << last << "\n";
				exit(0);
			}
		}
	}
	cout << -1 << "\n";
}