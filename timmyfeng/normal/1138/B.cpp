#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string a, c;
	cin >> n >> a >> c;

	vector<int> clown, acrobat, both, none;
	for (int i = 0; i < n; ++i) {
		if (a[i] == '1' && c[i] == '1') {
			both.push_back(i);
		} else if (a[i] == '1') {
			clown.push_back(i);
		} else if (c[i] == '1') {
			acrobat.push_back(i);
		} else {
			none.push_back(i);
		}
	}

	for (int c1 = 0; c1 <= int(clown.size()); ++c1) {
		for (int a2 = 0; a2 <= int(acrobat.size()); ++a2) {
			int diff = abs(c1 - a2);
			int c2 = int(clown.size()) - c1;
			int a1 = int(acrobat.size()) - a2;

			if (diff % 2 == int(both.size()) % 2 && diff <= int(both.size())) {
				int b1 = (int(both.size()) - diff) / 2;
				int b2 = (int(both.size()) - diff) / 2;
				(c1 < a2 ? b1 : b2) += diff;

				if (a1 + b1 + c1 <= n / 2 && a2 + b2 + c2 <= n / 2) {
					for (int i = 0; i < a1; ++i) {
						cout << acrobat[i] + 1 << " ";
					}
					for (int i = 0; i < b1; ++i) {
						cout << both[i] + 1 << " ";
					}
					for (int i = 0; i < c1; ++i) {
						cout << clown[i] + 1 << " ";
					}
					for (int i = 0; i + a1 + b1 + c1 < n / 2; ++i) {
						cout << none[i] + 1 << " ";
					}
					cout << "\n";
					exit(0);
				}
			}
		}
	}
	cout << -1 << "\n";
}