#include <bits/stdc++.h>
using namespace std;

void solve() {
	string S; cin >> S;
	int N = (int) S.length();
	for (int i = 0; i < N - 1; i++) {
		if (S[i] == '1' && S[i + 1] == '1') {
			for (int j = i + 2; j < N - 1; j++) {
				if (S[j] == '0' && S[j + 1] == '0') {
					cout << "NO" << '\n';
					return;
				}
			}
			break;
		}
	}
	cout << "YES" << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--)
		solve();
	return 0;
}