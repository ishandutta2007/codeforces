#include<cstdio>
#include<cmath>
const int MAXN = 20000;
int a[MAXN + 5], n;
int main() {
	scanf("%d", &n);
	int p = 0;
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i]);
		if( a[i] & 1 ) {
			if( p & 1 ) printf("%d\n", int(floor(1.0*a[i]/2)));
			else printf("%d\n", int(ceil(1.0*a[i]/2)));
			p ^= 1;
		}
		else printf("%d\n", a[i] / 2);
	}
}