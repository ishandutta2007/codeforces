#include <bits/stdc++.h>
using namespace std;

bool query(int a, int b) {
	cout << "? " << a << " " << b << endl;
	char res;
	cin >> res;
	assert(res != 'e');
	return res == 'x';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string status;
	cin >> status;
	while (status == "start") {
		long long bound = 2;
		while (bound <= 2e9 && query(bound, bound / 2)) {
			bound *= 2;
		}

		if (bound > 2e9) {
			cout << "! " << 1 << endl;
			cin >> status;
			continue;
		}

		int lb = bound / 2 + 1;
		int rb = bound;
		while (lb <= rb) {
			int mb = (lb + rb) / 2;
			if (query(mb, bound / 2)) {
				lb = mb + 1;
			} else {
				rb = mb - 1;
			}
		}

		cout << "! " << lb << endl;
		cin >> status;
	}
}