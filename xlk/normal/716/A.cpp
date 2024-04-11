#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, a[100020], t, z;
int main() {
	scanf("%d%d", &n, &t);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (i >= 1 && a[i] - a[i - 1] > t) {
			z = 1;
		} else {
			z++;
		}
	}
	printf("%d\n", z);
	return 0;
}