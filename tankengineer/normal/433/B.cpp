#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;

int n;

int a[N], b[N];

long long suma[N], sumb[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		b[i] = a[i];
	}
	sort(b, b + n);
	suma[0] = 0;
	sumb[0] = 0;
	for (int i = 0; i < n; ++i) {
		suma[i + 1] = suma[i] + a[i];
		sumb[i + 1] = sumb[i] + b[i];
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		--l, --r;
		long long ans;
		if (t == 1) {
			ans = suma[r + 1] - suma[l];
		} else {
			ans = sumb[r + 1] - sumb[l];
		}
		printf("%I64d\n", ans);
	}	
	return 0;
}