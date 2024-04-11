#include <bits/stdc++.h>

using namespace std;

int n;
int a[110];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int sum1 = a[1], sum2 = 0;
	vector <int> V;
	V.push_back(1);
	for (int i = 2; i <= n; i++) {
		if (a[1] >= a[i] * 2) {
			sum1 += a[i];
			V.push_back(i);
		} else
			sum2 += a[i];
	}
	if (sum1 > sum2) {
		printf("%lu\n", V.size());
		for (auto x: V)
			printf("%d ", x);
		printf("\n");
	}else {
		printf("0\n");
	}
}