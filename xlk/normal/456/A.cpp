#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> a[100020];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++) {
		if (a[i].second > a[i + 1].second) {
			printf("Happy Alex\n");
			return 0;
		}
	}
	printf("Poor Alex\n");
	return 0;
}