#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005;
int n, a[N][N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int tmp = 0;
		for (int j = 0; j < n; ++j) {
			tmp ^= a[i][j] & a[j][i];
		}
		sum ^= tmp;
	}
	int tag = n & 1;
	int q = 0;
	scanf("%d", &q);
	while (q--) {
		int op;
		scanf("%d", &op);
		if (op == 3) {
			printf("%d", sum);
		} else if (op == 1) {
			int i;
			scanf("%d", &i);
			sum ^= 1;
			--i;
		} else {
			int j;
			scanf("%d", &j);
			sum ^= 1;
			--j;
		}
	}
	printf("\n");
	return 0;
}