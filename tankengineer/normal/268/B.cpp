#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		ans += i * (n - i);
	}
	printf("%d\n", ans + n);
	return 0;
}