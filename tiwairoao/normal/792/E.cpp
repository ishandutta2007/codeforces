#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 500;
const int SQ = 32000;
const ll INF = (1LL<<60);
ll ans = INF; int a[MAXN + 5], n;
void check1(int x) {
	ll res = 0;
	for(int i=1;i<=n;i++) {
		int k = (a[i] + x) / (x + 1);
		if( 1LL*k*x <= a[i] ) res += k;
		else return ;
	}
	ans = min(ans, res);
}
/*
 x  x + 1
 i  k  xk <= a[i] <= k(x + 1)
 k,  k  k(x + 1) >= a[i],  a[i] >= xk 
*/
void check2(int x) {
	int k = a[1] / x;
	if( k ) check1(k);
	if( k - 1 > 0 && 1LL*x*k == a[1] ) check1(k - 1);
}
/*
 a1  x 
 k  k + 1 xk <= a1 <= x(k + 1)
 xk <= a1  k x(k + 1) > a1
 x(k-1) <= a1 <= xk xk = a1  
*/
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i]);
	for(int i=1;i<=SQ;i++)
		check1(i), check2(i);
	printf("%lld\n", ans);
}