#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[200020], b[200020];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i].first);
		b[i].second = i;
	}
	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < n; i++) {
		b[i].first = b[i].second;
		b[i].second = a[n - 1 - i].first;
	}
	sort(b, b + n);
	for (int i = 0; i < n; i++) {
		printf("%d%c", b[i].second, i == n - 1 ? '\n' : ' ');
	}
	return 0;
}