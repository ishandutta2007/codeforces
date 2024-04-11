#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

const int MAXM = 100000;

long double fct[MAXM + 5];
void init() {
	for(int i=1;i<=MAXM;i++)
		fct[i] = fct[i-1] + log10(i);
}
long double comb(int n, int m) {
	return fct[n] - fct[m] - fct[n-m];
}

int main() {
	init();
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	long double ans = 0;
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=n;j++) {
			int t = (i + j)*n - i*j;
			if( k < t ) continue;
			long double d = comb(m-t, k-t) - comb(m, k) + comb(n, i) + comb(n, j);
			ans += pow(10, d);
			if( d > 99 ) {
				printf("1e99");
				return 0;
			}
		}
	}
	if( log10(ans) > 99 ) printf("1e99");
	else cout << fixed << setprecision(9) << ans;
}