#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int>
typedef long long ll;	
using namespace std;

const int N = 222000;
int n, q, vis[20];
ll s[N], Rank = 1, fac[20];

ll solve() {
	int l, r;
	cin >> l >> r;
	int len = min(n, 15);
	memset(vis, 0, sizeof vis);

	ll k = Rank;
	int rest = n - len;
	rep(i, 1, len + 1) {
		rep(j, 1, len + 1) {
			if (vis[j]) 
				continue;
			if (k > fac[len - i]) {
				k -= fac[len - i];
			}
			else {
				s[i + rest] = s[i + rest - 1] + rest + j;
				vis[j] = 1;
				break;
			}
		}
	}
	return s[r] - s[l - 1];
}

int main() { 
	fac[0] = 1;
	rep(i, 1, 20)
		fac[i] = fac[i - 1] * i;
	cin >> n >> q;
	rep(i, 1, n + 1)
		s[i] = s[i - 1] + i;
	while (q--) {
		int t;
		cin >> t;
		if (t == 2) {
			int x;
			cin >> x;
			Rank += x;
		}
		else 
			cout << solve() << "\n";
	}
	return 0;
}