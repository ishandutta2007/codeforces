#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

int main() {
	int n, a[105], b[105];
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		b[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d%c", b[i], i == n ? '\n' : ' ');
	}
	return 0;
}