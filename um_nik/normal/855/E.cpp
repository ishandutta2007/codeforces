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

const int B = 12;
const int L = 70;

ll dp[B][L][B];
int a[L];
int z[B];

ll solve(int b, ll R) {
	for (int i = 0; i < b; i++)
		z[i] = 0;
	int sum = 0;
	int m = 0;
	while(R > 0) {
		a[m++] = R % b;
		R /= b;
	}
	ll ans = 0;
	for (int len = 1; len < m; len++)
		ans += (b - 1) * dp[b][len - 1][1];
	int st = 1;
	while(m--) {
		for (int x = st; x < a[m]; x++) {
			int nsum = sum;
			if (z[x] == 0)
				nsum++;
			else
				nsum--;
			ans += dp[b][m][nsum];
		}
		if (z[a[m]] == 0)
			sum++;
		else
			sum--;
		z[a[m]] ^= 1;
		st = 0;
	}
	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int b = 2; b < B; b++) {
		dp[b][0][0] = 1;
		for (int i = 0; i < L - 1; i++)
			for (int j = 0; j <= b; j++) {
				if (j > 0)
					dp[b][i + 1][j - 1] += dp[b][i][j] * (b - j + 1);
				if (j < b)
					dp[b][i + 1][j + 1] += dp[b][i][j] * (j + 1);
			}
	}

	int q;
	scanf("%d", &q);
	while(q--) {
		int b;
		ll l, r;
		scanf("%d%lld%lld", &b, &l, &r);
		printf("%lld\n", solve(b, r + 1) - solve(b, l));
	}

	return 0;
}