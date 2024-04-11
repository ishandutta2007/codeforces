#include<cstdio>
using namespace std;

int main() {
	int n, a[105], b[105];
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d %d", &a[i], &b[i]);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[i] == b[j]) ++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}