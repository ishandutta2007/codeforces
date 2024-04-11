#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int bear(int n) {
	while (n % 2 == 0) {
		n /= 2;
	}
	while (n % 3 == 0) {
		n /= 3;
	}
	return n;
}

int main() {
	int n, t;
	scanf("%d", &n);
	scanf("%d", &t);
	t = bear(t);
	for (int i = 1; i < n; ++i) {
		int t1;
		scanf("%d", &t1);
		if (bear(t1) != t) {
			printf("No\n");
			return 0;
		}
	}
	puts("YES");
	return 0;
}