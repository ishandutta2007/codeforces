#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int a1, a2, k1, k2, n;
	scanf("%d%d%d%d%d", &a1, &a2, &k1, &k2, &n);
	if( k1 > k2 ) swap(a1, a2), swap(k1, k2);
	int m = a1*(k1 - 1) + a2*(k2 - 1);
	if( n/k1 <= a1 ) printf("%d %d\n", max(0, n - m), n/k1);
	else printf("%d %d\n", max(0, n - m), a1 + (n - a1*k1)/k2);
}