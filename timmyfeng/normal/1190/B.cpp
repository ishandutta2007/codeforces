#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	sort(a.begin(), a.end());

	int same = 0;
	bool ok = true;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] == a[i + 1]) {
			ok &= a[i] && (!i || a[i - 1] + 1 < a[i]);
			++same;
		}
	}
	ok &= same <= 1;

	int block = 0;
	long long cnt = 0;
	for (auto& i : a) {
		cnt += i - block;
		++block;
	}
	ok &= cnt % 2;

	cout << (ok ? "sjfnb" : "cslnb") << "\n";
}