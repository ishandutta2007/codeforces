#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m - n % m; ++i) {
		if (i != 1) printf(" ");
		printf("%d", n / m);
	}
	for (int i = m - n % m + 1; i <= m; ++i) {
	  printf(" %d", n / m + 1);
	}
	printf("\n");
	return 0;
}