#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, c[3];
	memset(c, 0, sizeof(c));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int t1;
		scanf("%d", &t1);
		c[i % 3] += t1;
	}
	int ans = 0;
	for (int i = 0; i < 3; ++i) {
		if (c[i] > c[ans]) {
			ans = i;
		}
	}
	printf("%s\n", ans == 0 ? "chest" : (ans == 1 ? "biceps" : "back"));
	return 0;
}