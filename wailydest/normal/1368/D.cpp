#include <cstdio>
using namespace std;

const int LG = 20;
int a[LG];

int main() 
{
	int n;
	scanf("%d", &n);
	int v;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v);
		for (int j = 0; j < LG; ++j) if ((v >> j) & 1) ++a[j];
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		v = 0;
		for (int j = 0; j < LG; ++j) if (a[j]) {
			v += (1 << j);
			--a[j];
		}
		ans += (long long)v * v;
	}
	printf("%lld\n", ans);
	return 0;
}