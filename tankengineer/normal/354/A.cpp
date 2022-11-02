#include<vector>
#include<cstdio>
#include<climits>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, l, r, ql, qr;
	scanf("%d%d%d%d%d", &n, &l, &r, &ql, &qr);
	vector<int> w, sum;	
	sum.push_back(0);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		w.push_back(a);
		sum.push_back(sum.back() + a);
	}
	int ans = INT_MAX;
	for (int i = 0; i <= n; ++i) {
		int tmp = 0;
		tmp = l * sum[i] + r * (sum[n] - sum[i]);
		int ll = i, rr = n - ll;
		if (ll >= rr) {
			int times = max(0, ll - rr - 1);
			tmp += times * ql;
		} else {
			int times = max(0, rr - ll - 1);
			tmp += times * qr;
		}
		ans = min(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}