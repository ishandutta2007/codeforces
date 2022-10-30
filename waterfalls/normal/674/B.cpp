#include <bits/stdc++.h>
using namespace std;

int n,k,a,b,c,d;

int main() {
	scanf("%d%d%d%d%d%d",&n,&k,&a,&b,&c,&d);
	if (n==4 || k<n+1) return printf("-1\n"), 0;
	printf("%d %d ",a,c);
	for (int i=1;i<=n;i++) {
		if (i!=a && i!=b && i!=c && i!=d) printf("%d ",i);
	}
	printf("%d %d\n",d,b);
	printf("%d %d ",c,a);
	for (int i=1;i<=n;i++) {
		if (i!=a && i!=b && i!=c && i!=d) printf("%d ",i);
	}
	printf("%d %d\n",b,d);

	return 0;
}