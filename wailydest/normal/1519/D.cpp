#include <cstdio>
#include <algorithm>

const int N = 5000;
int n, a[N], b[N];

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	long long ov = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", b + i);
		ov += (long long)a[i] * b[i];
	}
	long long ans = ov;
	for (int i = 0; i < n; ++i) {
		long long cur = ov;
		for (int j = 0; i - j >= 0 && i + j < n; ++j) {
			cur -= (long long)a[i - j] * b[i - j] + (long long)a[i + j] * b[i + j];
			cur += (long long)a[i - j] * b[i + j] + a[i + j] * (long long)b[i - j];
			ans = std::max(ans, cur);
		}
	}
	for (int i = 0; i < n; ++i) {
		long long cur = ov;
		for (int j = 0; i - j >= 0 && i + j + 1 < n; ++j) {
			cur -= (long long)a[i - j] * b[i - j] + (long long)a[i + j + 1] * b[i + j + 1];
			cur += (long long)a[i - j] * b[i + j + 1] + (long long)a[i + j + 1] * b[i - j];
			ans = std::max(ans, cur);
		}
	}
	printf("%lld\n", ans);
	return 0;
}