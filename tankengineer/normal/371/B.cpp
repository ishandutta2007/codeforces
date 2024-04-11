#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int check(int a) {
	int ret = 0;
	while (a % 2 == 0) {
		++ret;
		a /= 2;
	}
	while (a % 3 == 0) {
		++ret;
		a /= 3;
	}
	while (a % 5 == 0) {
		++ret;
		a /= 5;
	}
	if (a != 1) {
		ret = -1000000000;
	}
	return ret;
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int d = __gcd(a, b);
	int ans = check(a / d) + check(b / d);
	if (ans < 0) {
		ans = -1;
	}
	printf("%d\n", ans);
	return 0;
}