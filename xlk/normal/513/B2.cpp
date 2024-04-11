#include <stdio.h>
#include <iostream>
using namespace std;
int n, a[100], l, r, c;
long long m;
int main() {
	cin >> n >> m;
	m--;
	l = 0;
	r = n - 1;
	c = 0;
	for (int i = n - 2; i >= 0; i--) {
		if (m >> i & 1) {
			a[r--] = c++;
		} else {
			a[l++] = c++;
		}
	}
	a[l] = c++;
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i] + 1);
	}
	return 0;
}