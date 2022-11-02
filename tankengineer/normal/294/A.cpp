#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100;
int a[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		--t1;
		if (t1 != n - 1) {
			a[t1 + 1] += a[t1] - t2;
		}
		if (t1 != 0) {
			a[t1 - 1] += t2 - 1;
		}
		a[t1] = 0;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d\n", a[i]);
	}
	return 0;
}