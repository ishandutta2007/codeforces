#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int c[5] = {1, 1, 2, 7, 4};

int main() {
	int ans = 100;
	for (int i = 0; i < 5; ++i) {
		int a;
		scanf("%d", &a);
		a /= c[i];
		ans = min (ans, a);
	}
	printf("%d\n", ans);
	return 0;
}