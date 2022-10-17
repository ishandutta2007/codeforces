#include <cstdio>
#include <functional>
#include <algorithm>
using namespace std;

const int N = 200000;
int a[N], b[N];

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		sort(a, a + n, greater<int>());
		for (int i = 0; i < k; ++i) scanf("%d", b + i);
		sort(b, b + k);
		long long s = 0;
		for (int i = 0; i < k; ++i) s += a[i];
		for (int i = 0, j = k; i < k; ++i) {
			if (b[i] == 1) {
				s += a[i];
				continue;
			}
			j += b[i] - 1;
			s += a[j - 1];
		}
		printf("%lld\n", s);
	}
	return 0;
}