#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[200013];
int b[200013];

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		b[i] = (a[i]==a[i-1]) ? b[i-1] : i-1;
	}
	for (int i=0;i<m;i++) {
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		if (a[r]==x && b[r]<l) printf("-1\n");
		else printf("%d\n",a[r]==x ? b[r] : r);
	}

	return 0;
}