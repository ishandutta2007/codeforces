#include <cstdio>
#include <algorithm>

const int N = 50;
int t, n, a[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		printf("%d\n", *std::max_element(a, a + n) - *std::min_element(a, a + n));
	}
	return 0;
}