#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define gao(x) cerr << #x << " " << x << "\n"
#define pb push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ll long long
 
using namespace std;

const int N = 1 << 19;

int n, p, m, dp[N];
ll mask[N];

void solve() {
	cin >> n >> m >> p;
	rep(i, 1, n) {
		string s;
		cin >> s;
		per(j, 0, m - 1) 
			mask[i] = 2 * mask[i] + (s[j] == '1');
	}
	int best = -1;
	ll res = 0;
	rep(i, 1, 30) {
		int x = 1ll * rand() * rand() % n + 1;	
		memset(dp, 0, sizeof dp);
		rep(j, 1, n) {
			ll q = 0;
			per(k, 0, m - 1) {
				if (mask[x] >> k & 1) {
					q = 2 * q + (mask[j] >> k & 1);
				}
			}
			dp[q]++;		
		}
		rep(i, 0, __builtin_popcountll(mask[x]) - 1)
			rep(M, 0, (1 << (p + 1)) - 1)
				if (!(M >> i & 1))
					dp[M] += dp[M ^ (1 << i)];
		rep(M, 0, (1 << (p + 1)) - 1)
			if (dp[M] >= (n + 1) / 2) {
				//~ cout << M << " " << x << " " << dp[M] << " " << best << endl;
				int bits = __builtin_popcount(M);
				if (bits > best) {
					best = bits;
					int cnt = __builtin_popcountll(mask[x]) - 1;
					res = 0;
					per(k, 0, m - 1) {
						if (mask[x] >> k & 1) {
							res = 2 * res + (M >> cnt & 1);	
							cnt--;
						}
						else
							res = 2 * res;
					}
				}
			}
	}
	rep(i, 0, m - 1) {
		cout << res % 2;
		res /= 2;
	}
	cout << endl;
}

int main() {
	srand(233);
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T;
	//~ cin >> T;
	T = 1;
	while (T--)
		solve();
	return 0;
}