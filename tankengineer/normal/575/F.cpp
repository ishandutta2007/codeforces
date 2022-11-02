#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

#define foreach(e,x) for(__typeof((x).begin()) e=(x).begin(); e!=(x).end(); ++e)

const int N = 5000 + 10;
const long long INF = 1000000000000000LL;

int n, sx;
int p[N + N];
int l[N], r[N];
long long f[2][N + N];

void solve()
{
	cin >> n >> sx;
	int tot = 0;
	p[tot ++] = sx;
	for(int i = 0; i < n; ++ i) {
		scanf("%d%d", l + i, r + i);
		p[tot ++] = l[i];
		p[tot ++] = r[i];
	}
	sort(p, p + tot);
	tot = unique(p, p + tot) - p;
	for(int i = 0; i < tot; ++ i) {
		f[0][i] = INF;
		if (p[i] == sx) f[0][i] = 0;
	}
	for(int i = 0; i < n; ++ i) {
		int nxt = (i + 1) & 1;
		int cur = i & 1;
		for(int j = 0; j < tot; ++ j) {
			f[nxt][j] = INF;
		}
		{
			long long prev = INF;
			for(int j = 0; j < tot; ++ j) {
				prev = min(prev, f[cur][j] - p[j]);
				f[nxt][j] = min(f[nxt][j], prev + p[j]);
			}
		}
		{
			long long prev = INF;
			for(int j = tot - 1; j >= 0; -- j) {
				prev = min(prev, f[cur][j] + p[j]);
				f[nxt][j] = min(f[nxt][j], prev - p[j]);
			}
		}
		for(int j = 0; j < tot; ++ j) {
			if (p[j] < l[i]) {
				f[nxt][j] += l[i] - p[j];
			} else if (p[j] > r[i]) {
				f[nxt][j] += p[j] - r[i];
			}
		}
	}
	long long ret = INF;
	for(int i = 0; i < tot; ++ i) {
		ret = min(ret, f[n & 1][i]);
	}
	cout << ret << endl;
}

int main()
{
	solve();
	return 0;
}