#include <cstdio>

using namespace std;

int main() {
	int n, m, d, l;
	scanf ("%d%d%d%d", &n, &d, &m, &l);
	for (int i = 0; i < n; i++) {
		long long x = (long long)i * m + l + 1;
		long long y = ((x + d - 1) / d) * d;
		if (i + 1 == n || y < (long long)(i + 1) * m) { printf ("%I64d\n", y); return 0; }
	}
	return 0;
}