#include <bits/stdc++.h>
using namespace std;

struct state {
	int pos, pre, suf;
	bool exists;
} automaton[11][11][11][10];

int dp[2][11][11][11];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int pos = 0; pos < 11; ++pos) {
		for (int pre = 0; pre < 11; ++pre) {
			for (int suf = 0; suf < 11; ++suf) {
				for (int digit = 0; digit < pos; ++digit) {
					state nxt;
					nxt.exists = true;
					nxt.pre = pre * pos - pre * (pre + 1) / 2 + digit;
					nxt.suf = suf * pos + suf * (suf + 1) / 2 + pos - 1 - digit ;
					nxt.pos = pos + suf + nxt.pre + 1;
					nxt.pre = (nxt.pre % 11 + 11) % 11;
					nxt.suf = (nxt.suf % 11 + 11) % 11;
					nxt.pos = (nxt.pos % 11 + 11) % 11;
					automaton[pos][pre][suf][digit] = nxt;
				}
			}
		}
	}

	string s;
	cin >> s;
	int n = s.size();

	long long ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		int digit = s[i] - '0';
		int ii = i % 2;

		for (int pos = 0; pos < 11; ++pos) {
			for (int pre = 0; pre < 11; ++pre) {
				for (int suf = 0; suf < 11; ++suf) {
					state nxt = automaton[pos][pre][suf][digit];
					if (nxt.exists) {
						dp[ii][pos][pre][suf] = 1 + dp[!ii][nxt.pos][nxt.pre][nxt.suf];
					} else {
						dp[ii][pos][pre][suf] = 0;
					}
				}
			}
		}

		if (digit) {
			ans += 1 + dp[!ii][digit][digit - 1][9 - digit];
		}
	}

	cout << ans << "\n";
}