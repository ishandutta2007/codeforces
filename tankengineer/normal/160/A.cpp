#include<cstdio>
#include<algorithm>
using namespace std;

int n, a[105];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int sum = 0, sum1 = 0;
	for (int i = 1; i <= n; ++i) sum1 += a[i];
	for (int i = n; i >= 1; --i) {
		sum += a[i];
		if (sum > sum1 - sum) {
			printf("%d\n", n - i + 1);
			return 0;
		}
	}
	return 0;
}