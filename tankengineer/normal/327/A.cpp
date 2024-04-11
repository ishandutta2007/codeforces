#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n, a[105];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
	  for (int j = i; j <= n; ++j) {
	    int tmp = 0;
	    for (int k = 1; k <= n; ++k) {
	      if (k >= i && k <= j) tmp += 1 - a[k]; else tmp += a[k];
			}
			ans = max(ans, tmp);
		}
	}
	printf("%d\n", ans);
	return 0;
}