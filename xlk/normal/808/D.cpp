#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000020];
long long s;
long long t;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		s += a[i];
	}
	if (s % 2 > 0) {
		printf("NO\n");
		return 0;
	}
	s /= 2;
	t = 0;
	set<long long> w;
	for (int i = 0; i < n; i++) {
		t += a[i];
		if (t == s) {
			printf("YES\n");
			return 0;
		}
		if (t > s) {
			if (w.find(t - s) != w.end()) {
				printf("YES\n");
				return 0;
			}
		}
		w.insert(a[i]);
	}
	w.clear();

	reverse(a, a + n);
	t = 0;
	for (int i = 0; i < n; i++) {
		t += a[i];
		if (t == s) {
			printf("YES\n");
			return 0;
		}
		if (t > s) {
			if (w.find(t - s) != w.end()) {
				printf("YES\n");
				return 0;
			}
		}
		w.insert(a[i]);
	}
	printf("NO\n");
	return 0;
}