#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5005;
int n;

int c[N], ans[N], cnt[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", c + i);
	}
	for (int i = 0; i < n; ++i) {
		memset(cnt, 0, sizeof(cnt));
		int maxs = 0, maxc = n + 1;
		for (int j = i; j < n; ++j) {
			cnt[c[j]]++;
			if (cnt[c[j]] > maxs || (cnt[c[j]] == maxs && c[j] < maxc)) {
				maxs = cnt[c[j]];
				maxc = c[j];
			}
			++ans[maxc];
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d%c", ans[i], i == n ? '\n' : ' ');
	}
	return 0;
}