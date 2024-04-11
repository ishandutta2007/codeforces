#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	if (n <= 2) {
		printf("-1\n");
	} else {
		printf("3 2 1");
		for (int i = 3; i < n; ++i) {
			printf(" 2");
		}
		printf("\n");
	}
	return 0;
}