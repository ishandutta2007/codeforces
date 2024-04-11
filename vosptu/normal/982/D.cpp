#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define N 110000

int a[N], to[N], ss[N], sum[N], fa[N];
int all, ansx, ansk, n;

bool cmp(int x, int y) {
	return a[x] < a[y];
}

int gf(int x) {
	if (fa[x] != x)
		return gf(fa[x]);
	return fa[x];
}

void merge(int x, int y) {
	x = gf(x);
	y = gf(y);
	if (!y)
		return ;
	ss[sum[x]] -= 1;
	ss[sum[y]] -= 1;
	sum[x] += sum[y];
	fa[y] = x;
	ss[sum[x]] += 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		to[i] = i;
	sort(to + 1, to + n + 1, cmp);
	ansx = 0;
	ansk = 0;
	for (int i = 1; i <= n; i++) {
		sum[to[i]] = 1;
		all += 1;
		ss[1] += 1;
		fa[to[i]] = to[i];
		merge(to[i], to[i] - 1);
		merge(to[i], to[i] + 1);
		if ((i == n || a[to[i] + 1] != a[to[i]]) && all == ss[sum[gf(to[i])]] * sum[gf(to[i])]) {
			int x = ss[sum[gf(to[i])]], k = a[to[i]] + 1;
			if (x > ansx)
				ansx = x, ansk = k;
		}
	}
	printf("%d\n", ansk);
}