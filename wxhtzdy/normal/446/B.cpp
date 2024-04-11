#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, m, k, p, a[1005][1005];
LL row[1000005], col[1000005], cc[1000005];

int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &p);
	rep1(i, n) rep1(j, m) scanf("%d", &a[i][j]);
	rep1(i, k) cc[i] = cc[i - 1] + i * 2 - 1;
	multiset<LL> st;
	rep1(i, n) {
		LL sum = 0;
		rep1(j, m) sum += a[i][j];
		st.insert(sum);
	}
	rep1(i, k) {
		row[i] = row[i - 1];
		LL sum = *prev(st.end());
		row[i] += sum;
		st.erase(prev(st.end()));
		st.insert(sum - m * p);
	}
	st.clear();
	rep1(j, m) {
		LL sum = 0;
		rep1(i, n) sum += a[i][j];
		st.insert(sum);
	}
	rep1(i, k) {
		col[i] = col[i - 1];
		LL sum = *prev(st.end());
		col[i] += sum;
		st.erase(prev(st.end()));
		st.insert(sum - n * p);
	}
	LL ans = -1e18;
	rep(i, k + 1) ans = max(ans, row[i] + col[k - i] - (max(i, k - i) - min(i, k - i)) * 1LL * p * min(i, k - i) - cc[min(i, k - i)] * p);
	printf("%lld\n", ans);
	return 0;
}