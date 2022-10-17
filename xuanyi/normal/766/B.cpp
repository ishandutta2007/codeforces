#include <cstdio>
#include <algorithm>
#define MAXN 100005

int n, A[MAXN] ;

int main() {
	scanf("%d", &n) ;
	for (int i = 1 ; i <= n ; i++) scanf("%d", A+i) ;
	std :: sort(A+1, A+1+n) ;
	for (int i = n ; i > 2 ; i--)
		if (A[i-1] + A[i-2] > A[i]) {
			printf("YES\n") ;
			return 0 ;
		}
	printf("NO\n") ;
	return 0 ;
}