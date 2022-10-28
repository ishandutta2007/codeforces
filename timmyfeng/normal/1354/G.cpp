#include <bits/stdc++.h> 
using namespace std;

const int MAG = 30;

mt19937 rng((uint64_t)new char);

string ask(int len, int a, int b) {
	cout << "? " << len << ' ' << len << endl;
	for (int i = 0; i < len; ++i) {
		cout << a + i << ' ';
	}
	cout << endl;
	for (int i = 0; i < len; ++i) {
		cout << b + i << ' ';
	}
	cout << endl;
	string res;
	cin >> res;
	return res;
}

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> perm(n);
	iota(perm.begin(), perm.end(), 1);
	shuffle(perm.begin(), perm.end(), rng);
	int mx = perm[0];
	for (int i = 1; i <= MAG && i < n; ++i) {
		if (ask(1, mx, perm[i]) == "SECOND") {
			mx = perm[i];
		}
	}

	if (mx != 1) {
		if (ask(1, 1, mx) != "EQUAL") {
			cout << "! " << 1 << endl;
			return;
		}
	}

	int lb = 2, rb = 2;
	for (int len = 1; len * 2 <= n; len *= 2, lb = len + 1, rb = len * 2) {
		if (ask(len, 1, lb) == "FIRST")
			break;
	}

	rb = min(n, rb);
	while (lb < rb) {
		int mb = (lb + rb) / 2;
		int len = mb - lb + 1;
		if (ask(len, 1, lb) == "FIRST") {
			rb = mb;
		} else {
			lb = mb + 1;
		}
	}
	cout << "! " << lb << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}