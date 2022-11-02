#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	int n, k, l, c, d, p, nl, np, ans;
	scanf("%d%d%d%d%d%d%d%d", &n, &k, &l, &c, &d, &p, &nl, &np);
	ans = min(k * l / nl, min(c * d, p / np)) / n;
	printf("%d\n", ans);
	return 0;
}