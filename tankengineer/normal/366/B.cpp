#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100000;
int n, k, sum[N];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		sum[i % k] += a;
	}
	int mins = 0;
	for (int j = 1; j < k; ++j) {
		if (sum[j] < sum[mins]) {
			mins = j;
		}
	}
	printf("%d\n", mins + 1);
	return 0;
}