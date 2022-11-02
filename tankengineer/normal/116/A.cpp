#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int n, maxs = 0, t1, t2, now = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &t1, &t2);
		now -= t1;
		now += t2;
		maxs = max(maxs, now);
	}
	printf("%d\n", maxs);
	return 0;
}