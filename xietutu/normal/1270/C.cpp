#include <bits/stdc++.h>
using namespace std;

int main() {
	int CASE; scanf("%d", &CASE);
	for (int Case = 1; Case <= CASE; ++ Case) {
		int n; scanf("%d", &n);
		long long sum = 0, xsum = 0;
		for (int i = 1; i <= n; ++ i) {
			int x; scanf("%d", &x);
			sum += x;
			xsum ^= x;
		}
		sum += xsum;
		printf("2\n%lld %lld\n", xsum, sum);
	}
	return 0;
}