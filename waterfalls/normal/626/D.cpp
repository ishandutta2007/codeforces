#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int n;
int a[2013];
int has[10013];

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) {
		has[a[j]-a[i]]+=1;
	}
	ld num = 0;
	ld cur = 0;
	for (int i=1;i<=10000;i++) {
		for (int j=1;j<=i-2;j++) {
			cur+=has[j]*has[i-1-j];
		}
		num+=has[i]*cur;
	}
	ld tot = n*(n-1)/2;
	num/=tot*tot*tot;
	printf("%1.12f\n",(double) num);

	return 0;
}