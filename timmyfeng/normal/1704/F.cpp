#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;

int grundy[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 2; i < N; ++i) {
		if (i >= 128) grundy[i] = grundy[i - 34];
		else {
			set<int> moves;
			for (int j = 0; j <= i - 2; ++j) {
				moves.insert(grundy[j] ^ grundy[i - 2 - j]);
			}
			while (moves.count(grundy[i])) ++grundy[i];
		}
	}

	int t; cin >> t;

	while (t--) {
		int n; cin >> n;
		string s; cin >> s;

		int sum = 0, nim_sum = 0;
		map<int, int> evens;
		for (int i = 0, j = 0; i < n; i = j) {
			j = i + 1;
			while (j < n && s[j] != s[j - 1]) ++j;
			if ((j - i) % 2)
				sum += (s[i] == 'R' ? 1 : -1);
			nim_sum ^= grundy[j - i];
		}

		if (sum < 0) {
			cout << "Bob\n";
		} else if (sum > 0) {
			cout << "Alice\n";
		} else {
			cout << (nim_sum ? "Alice" : "Bob") << "\n";
		}
	}
}