#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

inline int abs(int a) {
	return a < 0 ? -a : a;
}

int solve(int a, vector<int> &v) {
	int i = lower_bound(v.begin(), v.end(), a) - v.begin();
	if (i == (int)v.size()) {
		return a - v[i - 1];
	} else if (i == 0) {
		return v[0] - a;
	} else {
		return min(v[i] - a, a - v[i - 1]);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		vector<int> a(n), b(n), sa, sb;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		sa = a;
		sort(sa.begin(), sa.end());
		for (int i = 0; i < n; ++i) {
			scanf("%d", &b[i]);
		}
		sb = b;
		sort(sb.begin(), sb.end());
		long long 
			costhh = abs(a[0] - b[0]),
			costht = abs(a[0] - b[n - 1]),
			costth = abs(a[n - 1] - b[0]),
			costtt = abs(a[n - 1] - b[n - 1]),
			costha = solve(a[0], sb),
			costta = solve(a[n - 1], sb),
			costhb = solve(b[0], sa),
			costtb = solve(b[n - 1], sa);
		long long ans = 
		    min(costha + costta + costhb + costtb,
			min(costhh + costta + costtb,
			min(costht + costta + costhb,
			min(costth + costha + costtb,
			min(costtt + costha + costhb,
			min(costhh + costtt, costht + costth))))));
		printf("%d\n", (int)ans);
	}
	return 0;
}