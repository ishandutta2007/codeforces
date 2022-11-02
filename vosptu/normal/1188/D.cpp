#include <bits/stdc++.h>
using namespace std;

#define mp make_pair


const long long N = 100010;
const long long INF = 1e18;

long long n;
long long a[N];
long long dp[61][N];
vector <pair<long long, long long>> stuff[61];

long long bs(vector <pair<long long,long long>>& V, long long x) {
	long long l = 0, r = V.size();
	while (l < r - 1) {
		long long m = (l + r) / 2;
		if (x >= V[m].first)
			l = m;
		else
			r = m;
	}
	return l;
}

void upd(long long B, long long x, long long v) {
	long long id = bs(stuff[B], x);
	dp[B][id] = min(dp[B][id], v);
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	cin >> n;
	for (long long i = 1; i <= n; i++)
		cin >> a[i];


	for (long long B = 0; B <= 60; B++) {
		stuff[B].push_back(mp(0, 0));
		for (long long i = 1; i <= n; i++)
			stuff[B].push_back(mp(a[i] & ((1LL << B) - 1), i));
		sort(stuff[B].begin(), stuff[B].end());
	}


	for (long long B = 1; B <= 60; B++) {
		for (long long i = 0; i <= n; i++)
			dp[B][i] = INF;

		long long curBit[2];
		curBit[0] = 0;
		curBit[1] = 0;
		for (long long i = 1; i <= n; i++)
			if (a[i] & (1LL << (B - 1)))
				curBit[1]++;
			else
				curBit[0]++;

		for (long long i = n; i >= 0; i--) {

			if (i == n || stuff[B - 1][i].first != stuff[B - 1][i + 1].first) {
				upd(B, stuff[B - 1][i].first, dp[B - 1][i] + curBit[1]);
				upd(B, (1LL << (B - 1)) + stuff[B - 1][i].first, dp[B - 1][i] + curBit[0]);
			}

			long long id = stuff[B - 1][i].second;
			if (a[id] & (1LL << (B - 1))) {
				curBit[1]--;
				curBit[0]++;
			}else {
				curBit[1]++;
				curBit[0]--;
			}
		}
	}

	cout << dp[60][n] << endl;
}