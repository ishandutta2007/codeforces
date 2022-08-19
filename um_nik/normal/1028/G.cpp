#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

ll query(vector<ll> q) {
	printf("%d\n", (int)q.size());
	for (ll x : q)
		printf("%lld ", x);
	printf("\n");
	fflush(stdout);
	ll res;
	scanf("%lld", &res);
	if (res == -2) throw;
	if (res == -1) exit(0);
	return res;
}

const int K = 6;
const int N = (int)1e4;
ll dp[K][N + 3];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int k = 1; k < K; k++) {
//		cerr << k << endl;
		for (ll p = 1; p <= N; p++) {
			if (k == K - 1 && p == 2) break;
			ll cur = p;
			//ll lst = p;
			for (int it = 0; it < p; it++) {
				cur += dp[k - 1][min((ll)N, cur)];
				//lst = cur;
				cur++;
			}
			cur += dp[k - 1][min((ll)N, cur)];
			dp[k][p] = cur - p;
		}
//		cout << dp[k][N] << endl;
	}
//	cout << dp[5][1] << endl;

//	return 0;

	ll L = 1;
	ll R = 10004205361450474LL;
	for (int k = 5; k > 0; k--) {
		vector<ll> qq;
		ll cur = L;
		//ll lst = p;
		for (int it = 0; it < min((ll)N, L); it++) {
			cur += dp[k - 1][min((ll)N, cur)];
			qq.push_back(cur);
			//lst = cur;
			cur++;
		}
		cur += dp[k - 1][min((ll)N, cur)];
		ll res = query(qq);
		if (res == 0) {
			R = qq[0] - 1;
		} else if (res == (int)qq.size()) {
			L = qq.back() + 1;
		} else {
			L = qq[res - 1] + 1;
			R = qq[res] - 1;
		}
	}
	throw;

	return 0;
}