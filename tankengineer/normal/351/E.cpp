#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2005;
int n, a[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		a[i] = abs(a[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int posi = 0, nega = 0;
		for (int j = 0; j < i; ++j) {
			if (a[j] < a[i]) {
				++nega;
			}
		}
		for (int j = i + 1; j < n; ++j) {
			if (a[j] < a[i]) {
				++posi;
			}
		}
		ans += min(posi, nega);
	}
	printf("%d\n", ans);
	return 0;
}