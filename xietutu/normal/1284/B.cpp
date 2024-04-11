#include <bits/stdc++.h>
using namespace std;

int n, c, cnt;
int mmin[100005], mmax[100005];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		int x; scanf("%d", &x);
		bool flag = false; int Min = 2000000, Max = -1;
		for (int j = 1; j <= x; ++ j) {
			int y; scanf("%d", &y);
			if (y > Min) flag = true;
			Min = min(y, Min);
			Max = max(y, Max);
		}
		if (flag) ++ c;
		else {
			++ cnt;
			mmin[cnt] = Min;
			mmax[cnt] = Max;
		}
	}
	sort(mmin + 1, mmin + 1 + cnt);
	sort(mmax + 1, mmax + 1 + cnt);
	
	long long Ans = 1ll * c * c + 2ll * c * cnt;
	
	int t = 1;
	for (int i = 1; i <= cnt; ++ i) {
		while (t <= cnt && mmax[t] <= mmin[i]) ++ t;
		Ans += cnt - t + 1;
	}
	
	printf("%lld\n", Ans);
	return 0;
}