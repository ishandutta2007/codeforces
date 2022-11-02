#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 200000;
int a[MAXN + 5], n, q;
int mx[MAXN + 5], cnt[MAXN + 5];
int main() {
	scanf("%d%d", &n, &q);
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++, mx[a[i]] = i;
	}
	int ans = 0, pos = 1;
	while( pos <= n ) {
		int res = cnt[a[pos]], lim = mx[a[pos]], tmp = pos;
		while( pos <= lim ) {
			res = max(res, cnt[a[pos]]);
			lim = max(lim, mx[a[pos]]);
			pos++;
		}
		ans += (lim - tmp + 1) - res;
	}
	printf("%d\n", ans);
}