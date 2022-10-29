#include <bits/stdc++.h>
using namespace std;

const int MaxN = 200005;

int n, Anst;
int a[MaxN], sum[55], b[55];

int main() {
	b[0] = 1;
	for (int i = 1; i <= 30; ++ i) b[i] = b[i - 1] * 2;
//	printf("%d\n", b[30]);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		for (int j = 0; j <= 30; ++ j) {
			if (a[i] & b[j]) ++ sum[j];
		}
	}
	int Ans = -1; Anst = -1;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 0; j <= 30; ++ j) {
			if (a[i] & b[j]) -- sum[j];
		}
		int tmp = 0;
		for (int j = 0; j <= 30; ++ j) {
			if ((a[i] & b[j]) && (sum[j] == 0)) tmp += b[j];
		}
		if (tmp > Ans) {
			Ans = tmp;
			Anst = i;
		}
		for (int j = 0; j <= 30; ++ j) {
			if (a[i] & b[j]) ++ sum[j];
		}
	}
	printf("%d", a[Anst]);
	for (int i = 1; i <= n; ++ i) {
		if (i != Anst) printf(" %d", a[i]);
	}
	printf("\n");
	return 0;
}