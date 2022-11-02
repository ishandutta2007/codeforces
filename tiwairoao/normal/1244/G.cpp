#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1000000;
typedef long long ll;
int a[MAXN + 5];
ll n, k, s;
int main() {
	scanf("%lld%lld", &n, &k);
	if( n*(n + 1)/2 > k ) puts("-1");
	else {
		s = n*(n + 1)/2;
		for(int i=1;i<=n;i++) a[i] = i;
		for(int i=n,j=1;i>j;i--,j++) {
			if( s + i - j <= k )
				s += i - j, swap(a[i], a[j]);
			else {
				swap(a[i], a[i-(k-s)]);
				s = k;
				break;
			}
		}
		printf("%lld\n", s);
		for(int i=1;i<=n;i++)
			printf("%d ", i);
		puts("");
		for(int i=1;i<=n;i++)
			printf("%d ", a[i]);
	}
}