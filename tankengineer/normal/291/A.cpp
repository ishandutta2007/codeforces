#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000;
int a[N];
bool vis[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	int ans = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; ++i) {
		if (vis[i] || a[i] == 0) {
			continue;
		}
		int cnt = 0;
		for (int j = i; j < n; ++j) {
			if (a[j] == a[i]) {
				vis[j] = true;
				++cnt;
			}
		}
		if (cnt == 2) {
			++ans;
		} else if (cnt > 2) {
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}