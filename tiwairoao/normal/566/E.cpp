#include <bitset>
#include <cstdio>
#include <algorithm>
using namespace std;

int tag[1005], n;
bitset<1005>a[1005], b[1005], c[1005], t, p;
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		int k, x; scanf("%d", &k);
		for(int j=1;j<=k;j++)
			scanf("%d", &x), b[i][x] = 1;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) {
			t = (b[i] & b[j]);
//			printf("%d %d : %d\n", i, j, t.count());
			if( t.count() == 2 ) {
				int x = t._Find_first(); t[x] = 0;
				int y = t._Find_first();
				a[x][y] = a[y][x] = 1;
			}
		}
	t = 0;
	for(int i=1;i<=n;i++)
		if( a[i].count() ) tag[i] = -1, t[i] = 1;
	for(int i=1;i<=n;i++) a[i][i] = 1;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if( a[i][j] ) printf("%d %d\n", i, j);
	if( t.count() == 0 ) {
		for(int i=2;i<=n;i++)
			printf("%d %d\n", 1, i);
	}
	else if( t.count() == 2 ) {
		for(int x=1;x<=n;x++) {
			for(int y=x+1;y<=n;y++) {
				if( a[x][y] ) {
					bool flag = false;
					for(int i=1;i<=n;i++)
						if( b[i].count() != n ) {
							for(int j=1;j<=n;j++)
								if( b[i][j] ) {
									if( tag[j] == 1 ) break;
									else if( tag[j] != -1 ) {
										printf("%d %d\n", flag ? y : x, j);
										tag[j] = 1;
									}
								}
							flag = true;
						}
				}
			}
		}
	}
	else {
		for(int i=1;i<=n;i++) {
			c[i] = (b[i] & t);
			bool flag = true;
			for(int j=1;j<=n;j++)
				if( b[i] == b[j] ) {
					if( j < i ) {
						flag = false;
						break;
					}
				}
				else if( (b[i] & b[j]) == b[j] ) {
					flag = false;
					break;
				}
			if( flag ) {
				for(int j=1;j<=n;j++)
					if( c[i] == a[j] ) {
						for(int k=1;k<=n;k++)
							if( b[i][k] && tag[k] == 0 )
								printf("%d %d\n", j, k), tag[k] = 1;
						break;
					}
			}
		}
	}
}