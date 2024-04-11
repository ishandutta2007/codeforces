#include <bits/stdc++.h>

int n,k;
int main() {
	scanf("%d%d",&n,&k);
	if((n-2)%k==0) printf("%d\n",(n-2+k)/k*2-1);
	else printf("%d\n",(n-2+k)/k*2);	
		
	for(int i=2;i<=2+k-1;i++) printf("%d %d\n",1,i);
	for(int i=2;i<=n-k;i++) printf("%d %d\n",i,i+k);
	return 0;
}