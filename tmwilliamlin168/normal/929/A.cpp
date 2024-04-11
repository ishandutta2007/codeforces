/// In The Name Of God

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define f first
#define s second

#define pb push_back
#define pp pop_back
#define mp make_pair

#define sz(x) (int)x.size()
#define sqr(x) ((x) * 1ll * (x))
#define all(x) x.begin(), x.end()

#define Kazakhstan ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define nl '\n'
#define ioi exit(0);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = (int)5e5 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;

const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

using namespace std;

int n, k;
int a[N];
ll dp[N];
int main() {
	#ifdef IOI2018
		freopen ("in.txt", "r", stdin);
	#endif
	Kazakhstan
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = inf;
	}
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = i - 1; j >= 1; j--) {
			if (a[i] - a[j] <= k) dp[i] = min(dp[i], dp[j] + 1);
		}
	}
	if (dp[n] >= inf) dp[n] = -1;
	cout << dp[n];
	ioi
}