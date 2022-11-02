#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	bool first = true;
	for (int i = 20; i >= 0; --i) {
		if (n >> i & 1) {
			if (!first) {
				printf(" ");
			} else {
				first = false;
			}
			printf("%d", i + 1);
		}
	}
	printf("\n");
	return 0;
}