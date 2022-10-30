#include<cstdio>
#include<iostream>
using namespace std;

int hash[24][60];

int main() {
	int n, tx, ty, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &tx, &ty);
		ans = max(ans, ++hash[tx][ty]);
	}
	printf("%d\n", ans);
}