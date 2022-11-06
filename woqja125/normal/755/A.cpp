#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=1; i<=2000; i++){
		int x = n*i+1, j;
		for(j=2; j*j<=x; j++) if(x%j == 0) break;
		if(j*j <= x){
			printf("%d", i);
			return 0;
		}
	}
	return 0;
}