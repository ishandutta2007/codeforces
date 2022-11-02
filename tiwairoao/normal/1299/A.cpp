#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000;

int a[MAXN + 5], b[MAXN + 5], n;

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i]);
	for(int i=30;i>=0;i--) {
		int cnt = 0;
		for(int j=1;j<=n;j++) {
			if( (a[j] >> i) & 1 )
				cnt++;
		}
		if( cnt == 1 ) {
			for(int j=1;j<=n;j++) {
				if( (a[j] >> i) & 1 )
					b[j] |= (1LL<<i);
			}
		}
	}
	int p = 1;
	for(int i=1;i<=n;i++)
		if( b[p] < b[i] ) p = i;
		
	printf("%d ", a[p]);
	for(int i=1;i<=n;i++)
		if( i != p ) printf("%d ", a[i]);
}