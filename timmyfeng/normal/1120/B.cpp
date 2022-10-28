#include <bits/stdc++.h>
using namespace std;

const int MXC = 1e5;

vector<pair<int, int>> ans;
string a, b;
long long c;
int n;

void print() {
	cout << c << "\n";
	for (auto [d, s] : ans) {
		cout << d + 1 << " " << s << "\n";
	}
	exit(0);
}

void play(int d, int s) {
	if (a[d + 1] + s > '9' || a[d + 1] + s < '0') {
		play(d + 1, -s);
	}

	if (int(ans.size()) == MXC) {
		print();
	}

	a[d] += s;
	a[d + 1] += s;
	ans.emplace_back(d, s);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b;

	vector<int> num(n);
	for (int i = 0; i < n; ++i) {
		num[i] = a[i];
	}

	for (int i = 0; i < n - 1; ++i) {
		int delta = b[i] - num[i];
		c += abs(delta);
		num[i] += delta;
		num[i + 1] += delta;
	}

	if (num[n - 1] != b[n - 1]) {
		cout << -1 << "\n";
		exit(0);
	}

	for (int i = 0; i < n - 1; ++i) {
		while (a[i] != b[i]) {
			play(i, a[i] < b[i] ? 1 : -1);
		}
	}

	print();
}