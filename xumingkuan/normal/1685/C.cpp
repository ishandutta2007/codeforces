#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>
using namespace std;
const int MAXN = 202020;
int n;
char s[MAXN];
int a[MAXN];
int sum[MAXN], pn, pos[MAXN];
bool isneg[MAXN];
int d[MAXN];
int mxd[MAXN];
void solve() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	n *= 2;
	a[0] = 0;
	pn = 0;
	bool neg = false;
	sum[0] = 0;
	pos[0] = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = a[i - 1] + (s[i] == '(' ? 1 : -1);
		if (a[i] < 0)
			neg = true;
		if (i == n || (i < n && s[i] == '(' && s[i + 1] == ')')) {
			pn++;
			sum[pn] = a[i];
			pos[pn] = i;
			isneg[pn] = neg;
			//printf("%d: pos %d, neg=%d\n", pn, i, neg);
			neg = false;
		}
	}
	d[0] = 0;
	for (int i = 1; i <= pn; i++) {
		d[i] = min(d[i - 1], 0) + (sum[i] - sum[i - 1]);
	}
	mxd[pn] = d[pn];
	for (int i = pn - 1; i >= 1; i--)
		mxd[i] = max(d[i], mxd[i + 1]);
	vector<pair<int, int>> ans;
	int mxsum = 0, mxsumpos = 0;
	for (int i = 1; i <= pn; i++) {
		if (isneg[i]) {
			int j = i;
			while (j < pn && mxd[j + 1] + mxsum >= 0) {
				j++;
			}
			ans.push_back(make_pair(mxsumpos + 1, pos[j]));
			i = j;
			int cur_sum = mxsum;
			reverse(s + mxsumpos + 1, s + pos[j] + 1);
			for (int k = mxsumpos + 1; k <= pos[j]; k++) {
				cur_sum += (s[k] == '(' ? 1 : -1);
				if (cur_sum > mxsum)
					mxsum = cur_sum, mxsumpos = k;
			}
		} else {
			if (sum[i] > mxsum) {
				mxsum = sum[i], mxsumpos = pos[i];
			}
		}
	}
	printf("%d\n", (int)ans.size());
	for (auto &i : ans)
		printf("%d %d\n", i.first, i.second);
}
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		solve();
	}
	return 0;
}