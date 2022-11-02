#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;

int n, k;

int a[N];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	int ans = a[n - 1];
	if (k < n) {
		int two = n - k;
		for (int i = 0; i < two; ++i) {
			ans = max(ans, a[two * 2 - i - 1] + a[i]);
		}	
	}
	printf("%d\n", ans);
	return 0;
}