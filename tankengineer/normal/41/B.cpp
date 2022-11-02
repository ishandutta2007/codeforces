#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2000;
int n, b, a[N];

int main() {
	scanf("%d%d", &n, &b);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	int ans = b;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			int tmp = b % a[i] + b / a[i] * a[j];
			ans = max(ans, tmp);
		}
	}
	printf("%d\n", ans);
	return 0;
}