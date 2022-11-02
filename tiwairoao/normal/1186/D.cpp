#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
double a[MAXN + 5];
int b[MAXN + 5];
long long sum;
int main() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%lf", &a[i]);
	for(int i=1;i<=n;i++) {
		b[i] = int(a[i]);
		sum += b[i];
	}
	for(int i=1;i<=n;i++)
		if( ceil(a[i]) != floor(a[i]) ) {
			if( sum > 0 && a[i] < 0 )
				b[i]--, sum--;
			else if( sum < 0 && a[i] > 0 )
				b[i]++, sum++;
		}
	for(int i=1;i<=n;i++)
		printf("%d\n", b[i]);
}