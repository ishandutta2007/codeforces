#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int m, v;

int main() {
	scanf ("%d%d%d", &n, &m, &v); 
	if (m < n - 1 || m > n - 1 + (long long)(n - 2) * (n - 3) / 2) printf ("-1\n"); else {
		int w = v % n + 1;
		m -= n - 1;
		for (int i = 1; i <= n; i++)
			if (i != v) printf ("%d %d\n", v, i);
		for (int i = 1; i <= n && m; i++)
			for (int j = i + 1; j <= n && m; j++)
				if (i != v && i != w && j != v && j != w) {
					m--;
					printf ("%d %d\n", i, j);
				}
	}
	return 0;
}