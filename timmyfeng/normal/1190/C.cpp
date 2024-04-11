#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	string s;
	cin >> n >> k >> s;

	vector<vector<int>> pre(2, vector<int>(n + 2, -1));
	for (int i = 1; i <= n; ++i) {
		int c = s[i - 1] - '0';
		pre[c][i] = i;
		pre[c ^ 1][i] = pre[c ^ 1][i - 1];
	}

	vector<vector<int>> nxt(2, vector<int>(n + 2, -1));
	for (int i = n; i; --i) {
		int c = s[i - 1] - '0';
		nxt[c][i] = i;
		nxt[c ^ 1][i] = nxt[c ^ 1][i + 1];
	}

	bool ok = true;
	for (int i = 1; i + k - 1 <= n; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (pre[j][i - 1] == -1 && nxt[j][i + k] == -1) {
				cout << "tokitsukaze\n";
				return 0;
			}

			int cnt = 0;
			if (pre[j][i - 1] != -1) {
				if (pre[j][i - 1] >= nxt[j][1] + k) {
					ok = false;
				}
				++cnt;
			}
			if (nxt[j][i + k] != -1) {
				if (pre[j][n] >= nxt[j][i + k] + k) {
					ok = false;
				}
				++cnt;
			}
			if (cnt > 1) {
				ok = false;
			}
		}
	}
	cout << (ok ? "quailty" : "once again") << "\n";
}