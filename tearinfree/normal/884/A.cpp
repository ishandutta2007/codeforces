#include <bits/stdc++.h>

int main() {
	int n,t,sum=0,a;
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a);
		sum+=86400-a;
		if(sum>=t) {
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}