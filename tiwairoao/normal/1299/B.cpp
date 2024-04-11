#include <cstdio>

const int MAXN = 100000;

int x[MAXN + 5], y[MAXN + 5], n;

int main() {
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d%d", &x[i], &y[i]);
	if( n % 2 == 1 ) puts("NO");
	else {
		int p = 0, q = n/2;
		int X = x[0] + x[n/2], Y = y[0] + y[n/2];
		while( p < n/2 ) {
			if( x[p] + x[q] != X || y[p] + y[q] != Y ) {
				puts("NO");
				return 0;
			}
			p++, q++;
		}
		puts("YES");
	}
}