#include<cstdio>
#include<algorithm>
using namespace std;
const int TABLE[] = {0, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}
int main() {
	int q; scanf("%d", &q);
	for(int i=1;i<=q;i++) {
		int x, y = 0; scanf("%d", &x);
		int tmp = x;
		for(int j=0;x;j++) {
			if( (1<<j) & x )
				x ^= (1<<j);
			else y ^= (1<<j);
		}
		if( y == 0 ) {
			int ans = 0;
			for(int j=0;j<=25;j++)
				if( !((1<<j) & tmp) ) {
					printf("%d\n", TABLE[j-1]);
					break;
				}
		}
		else printf("%d\n", tmp^y);
	}
}