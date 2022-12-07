#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define gao(x) cerr << #x << " = " << x << "\n"
#define pb push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ll long long
 
using namespace std;

const int N = 1 << 20;

int k, q, id[N], dp[N], pos[N];
char s[N];

void modify(int u) {
	while (u >= 1) {
		if (s[id[u]] == '?')
			dp[u] = dp[2 * u] + dp[2 * u + 1];
		else if (s[id[u]] == '0')
			dp[u] = dp[2 * u];
		else
			dp[u] = dp[2 * u + 1];
		u /= 2;
	}
}	

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	fill(dp, dp + N, 1);
	cin >> k;
	rep(i, 1, (1 << k) - 1) cin >> s[i], id[i] = (1 << k) - i;
	rep(j, 0, k - 1)
		reverse(id + (1 << j), id + (1 << (j + 1)));
	rep(j, 1, (1 << k) - 1)
		pos[id[j]] = j;
	per(i, 1, (1 << k) - 1)
		modify(i);
	cin >> q;
	while (q--) {
		int p; char c;
		cin >> p >> c;
		s[p] = c;
		modify(pos[p]);
		cout << dp[1] << "\n";
	}
	return 0;
}