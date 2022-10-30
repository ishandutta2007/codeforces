#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 100005;

int n, q;
long long v[N], c[N], col[N];
bool vis[N];

long long getans(const long long a, const long long b) {
	long long ans = 0, max1 = 0, max2 = 0, maxc1 = 0, maxc2 = 0, tmp;
	memset(col, 0, sizeof(col));
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; ++i) {
		tmp = 0;
		if (c[i] != maxc1) {
			if (vis[c[i]]) {
				tmp = max(col[c[i]] + a * v[i], max1 + b * v[i]);
				col[c[i]] = max(col[c[i]], tmp);
			} else {
				vis[c[i]] = true;
				tmp = max1 + b * v[i];
				col[c[i]] = tmp;
			}
			if (tmp > max1) {
				max2 = max1;
				maxc2 = maxc1;
				max1 = tmp;
				maxc1 = c[i];
			} else if (tmp > max2) {
				max2 = tmp;
				maxc2 = c[i];
			}
		} else if (c[i] == maxc1) {
			if (vis[c[i]]) {
				tmp = max(col[c[i]] + a * v[i], max2 + b * v[i]);
				col[c[i]] = max(col[c[i]], tmp);
			} else {
				vis[c[i]] = true;
				tmp = max2 + b * v[i];
				col[c[i]] = tmp;
			}
			if (tmp > max1) max1 = tmp;
		}
		ans = max(ans, tmp);
		//printf("%d %I64d\n", i, tmp);
	}
	return ans;
}

int main() {
	long long a, b;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i) {
	  scanf("%I64d", &v[i]);
	}
	for (int i = 1; i <= n; ++i) {
	  scanf("%I64d", &c[i]);
	}
	for (int i = 1; i <= q; ++i) {
	  scanf("%I64d %I64d", &a, &b);
	  printf("%I64d\n", getans(a, b));
	}
	return 0;
}