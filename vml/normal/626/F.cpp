#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <memory.h>
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define ui unsigned int
#define ld double

using namespace std;

const int maxn = (int)2e5 + 10;

int mod = (int)1e9 + 7;
ll ans = 0;

ll dp[2][201][100 * 500 + 1000];
int poss[2][201][100 * 500 + 1000];
int v[201];
queue <pair <pii, int> > q;
int n, k;

void change(int pos, int it, int cnt, int sum, ll x) {
	if (pos < 0) {
		if (cnt == 0 && sum <= k) {
			ans += x;
		}
		return;
	}

	if (cnt < 0 || sum < 0 || x == 0) {
		return;
	}

	if (poss[it][cnt][sum] != pos) {
		poss[it][cnt][sum] = pos;
		dp[it][cnt][sum] = 0;
		q.push(mp(mp(cnt, sum), n - pos - 1));
	}

	dp[it][cnt][sum] += x;
}

ll sums[maxn];

ll go_sum(int l, int r) {
	if (l == 0) {
		return sums[r];
	}

	return sums[r] - sums[l - 1];
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		//v[i] = rand() % 500 + 1;
	}

	ll now = 0;

	sort(v, v + n);

	for (int i = 0; i < n; i++) {
		now += v[i];
		sums[i] = now;
	}

	int it = 1;

	dp[0][0][0] = 1;

	q.push(mp(mp(0, 0), 0));

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 201; j++) {
			for (int t = 0; t < 51000; t++) {
				poss[i][j][t] = 100000;
			}
		}
	}

	while (!q.empty()) {
		int pos = n - q.front().second - 1;
		int it = q.front().second & 1;
		int cnt = q.front().first.first;
		int sum = q.front().first.second;
		q.pop();

		if (cnt > pos + 1 || (cnt != 0 && sum - go_sum(pos - cnt + 1, pos) > k)) {
			continue;
		}

		dp[it][cnt][sum] %= mod;

		change(pos - 1, it ^ 1, cnt, sum, (cnt + 1) * dp[it][cnt][sum]);
		change(pos - 1, it ^ 1, cnt - 1, sum - v[pos], cnt * dp[it][cnt][sum]);
		change(pos - 1, it ^ 1, cnt + 1, sum + v[pos], dp[it][cnt][sum]);
	}

	cout << ans % mod << endl;

	return 0;
}