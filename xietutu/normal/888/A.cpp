#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, a[maxn];
int main() {
	scanf("%d", &n);	
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	int ret = 0;
	for (int i = 2; i < n; ++i) {
		if ( (a[i] < a[i - 1] && a[i] < a[i + 1]) || 
			(a[i] > a[i - 1] && a[i] > a[i + 1]))
		++ret;
	}
	printf("%d\n", ret);
}