#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2000005;

int n, t;
long long sum[MaxN];
int nums[MaxN];

int main() {
	scanf("%d", &n);
	t = 0;
	for (int i = 1; i <= n; ++ i) {
		long long ns; scanf("%lld", &ns);
		int nn = 1;
		while (t && ns * nums[t] <= sum[t] * nn) {
			// merge
			ns += sum[t];
			nn += nums[t];
			-- t;
		}
		nums[++ t] = nn;
		sum[t] = ns;
	}
	
//	for (int i = 1; i <= t; ++ i) printf("%lld %d\n", sum[i], nums[i]); 
	
	for (int i = 1; i <= t; ++ i) {
		double val = (double)sum[i] / nums[i];
		for (int j = 1; j <= nums[i]; ++ j) printf("%.10lf\n", val);
	}
	return 0;
}