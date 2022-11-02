#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 55;

int n;
long long p[N], a[6], cnt[6];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%I64d", &p[i]);
	for (int i = 1; i <= 5; ++i) scanf("%I64d", &a[i]);
	long long tot = 0;
	for (int i = 1; i <= n; ++i) {
	  tot += p[i];
	  for (int j = 5; j >= 1; --j) {
		  cnt[j] += tot / a[j];
		  tot %= a[j];
		}
	}
	for (int i = 1; i <= 4; ++i) printf("%I64d ", cnt[i]);
	printf("%I64d\n%I64d\n", cnt[5], tot);
	return 0;
}