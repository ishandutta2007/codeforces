#include<cstdio>
#include<cmath>
const int MAXN = 4000000;
int tag[MAXN + 5], n;
int main() {
	scanf("%d", &n);
	int a = 1, b = 2, c = 4, d = 5;
	while( d <= MAXN ) {
		tag[a] = tag[b] = tag[c] = tag[d] = 1;
		int tmp = d;
		b = 2*tmp, a = b - 1, c = 2*b, d = c + 1;
	}
	printf("%d\n", tag[n]);
}