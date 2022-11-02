#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 55;

int n, a[N][N], ans[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int a;
			scanf("%d", &a);
			ans[i] = max(ans[i], a);
			ans[j] = max(ans[j], a);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (ans[i] == n - 1) {
			++ans[i];
			break;
		}
	}
	for (int i = 0; i <n ; ++i) {
		printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}