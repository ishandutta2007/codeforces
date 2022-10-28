#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> time_in(n + 1, -1);
	vector<int> b(n + 1);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (a) {
			time_in[a] = 0;
		}
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		time_in[b[i]] = i;
	}

	int ptr = n;
	while (ptr - 1 && b[ptr - 1] && b[ptr - 1] == b[ptr] - 1) {
		--ptr;
	}
	if (b[ptr] == 1) {
		int cur = b[n] + 1;
		int t = 0;
		while (cur <= n && time_in[cur] <= t) {
			++cur;
			++t;
		}
		if (cur > n) {
			cout << t << "\n";
			return 0;
		}
	}

	int t = 0;
	int cur = 1;
	while (cur <= n) {
		if (time_in[cur] <= t) {
			++cur;
		}
		++t;
	}
	cout << t << "\n";
}