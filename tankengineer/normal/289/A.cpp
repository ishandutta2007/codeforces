#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, k, len = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		len += (r - l + 1) % k;
	}
	len = len % k;
	printf("%d\n", len ? k - len : len);
	return 0;
}