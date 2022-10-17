#include <cstdio>
#include <algorithm>

const int N = 200000;
int t, n, a[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		std::sort(a, a + n);
		for (int i = n + 1 >> 1; i < n; ++i) printf("%d %d\n", a[i], a[0]);
	}
	return 0;
}