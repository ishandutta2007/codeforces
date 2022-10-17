#include<stdio.h>
int n,T;
int main(){
	scanf("%d",&n);
	int V=1;
	while(V<n)
		V=V<<1|1;
	V=V<<1|1;
	printf("%d %d\n",2,3);
	printf("%d %d %d\n",V,n,0);
	printf("%d %d %d\n",V^n,V,n);
	return 0;
}