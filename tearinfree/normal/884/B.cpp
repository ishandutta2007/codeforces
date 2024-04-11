#include <bits/stdc++.h>

int main() {
	int n,l,sum=0,a;
	scanf("%d%d",&n,&l);
	for(int i=0;i<n;i++) {
		scanf("%d",&a);
		sum+=a;
	}
	sum+=n-1;
	if(sum==l) puts("YES");
	else puts("NO");
	return 0;
}