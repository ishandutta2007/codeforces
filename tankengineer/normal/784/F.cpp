#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int T = 1000000;

int main() {
	int n, a[11];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < T; ++i) {
		for (int j = 0; j < 1000; ++j) {
			a[10] = a[10] * 17 + 231;
		}
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}