#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[200013];

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	for (int i=0;i<m;i++) {
		int b;
		scanf("%d",&b);
		printf("%d ",upper_bound(a,a+n,b)-a);
	}
	printf("\n");

	return 0;
}