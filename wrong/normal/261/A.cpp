#include <cstdio>
#include <algorithm>

using namespace std;

int m, q[100050], n, a[100050];

int main()
{
	scanf("%d", &m);

	for (int i = 0; i < m; ++i) {
		scanf("%d", &q[i]);
	}

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	sort(q, q+m);
	sort(a, a+n);

	int res = 0, pos = n-1;
	while (pos >= 0) {
		for (int i = 0; i < q[0] && pos >= 0; ++i) {
			res += a[pos--];
		}
		pos -= 2;
	}

	printf("%d\n", res);

	return 0;
}