#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

double dp[100100] = {};
int main () {
	int n= read();
	int i, j;
	double ans = 0;
	for (i = 1; i <= n; i++) ans += 1.0 / double(i);
	printf("%.6lf\n", ans);
	return 0;
}