#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	int ans = n - 1 - max(a, n - 1 - b) + 1;
	ans = max(ans, 0);
	printf("%d\n", ans);
	return 0;
}