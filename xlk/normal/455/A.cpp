#include <stdio.h>
#include <iostream>
using namespace std;
long long f[100020];
int a[100020], n, x;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		a[x] += 1;
	}
	for (int i = 1; i <= 100000; i++) {
		f[i] = max(f[i - 1], f[i - 2] + (long long)i * a[i]);
	}
	cout << f[100000] << endl;
	return 0;
}