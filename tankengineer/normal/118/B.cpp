#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
void print(const int i) {
	int space = (n - i) * 2;
	for (int j = 0; j < space; ++j) {
		printf(" ");
	}
	for (int j = 0; j <= i; ++j) {
		printf("%d", j);
		if (j != i) printf(" ");
	}
	for (int j = i - 1; j >= 0; --j) {
		printf(" %d", j);
	}
	printf("\n");
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i) {
		print(i);
	}
	for (int i = n - 1; i >= 0; --i) {
		print(i);
	}
	return 0;
}