#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 150;

int n, k, s;

int w[N]; 

int dp[N * N / 4][N * (N - 1) / 2];

const int INF = 1000000000;

int getAns(const int &l, const int &r, const int &s) {
	if (l == k) {
		return 0;
	}
	if (r < k) {
		return getAns(l + 1, r, s) + w[l];
	}
	int id = (n - 1 - r) * k + l;
	if (dp[id][s] != -1) {
		return dp[id][s]; 
	}
	int &ret = dp[id][s];
	ret = INF;
	ret = min(ret, getAns(l + 1, r, s) + w[l]);
	ret = min(ret, getAns(l, r - 1, s));
	int cost = r - l;
	if (s >= cost) {
		ret = min(ret, getAns(l + 1, r - 1, s - cost) + w[r]);
	}
	//cout << l << ' ' << r << ' ' << s << ' ' << ret << endl;
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d%d%d", &n, &k, &s);
	for (int i = 0; i < n; ++i) {
		scanf("%d", w + i);
	}
	if (s >= n * (n - 1) / 2) {
		sort(w, w + n);
		int ans = 0;
		for (int i = 0; i < k; ++i) {
			ans += w[i];
		}
		printf("%d\n", ans);
		return 0;
	}
	printf("%d\n", getAns(0, n - 1, s));
	return 0;
}