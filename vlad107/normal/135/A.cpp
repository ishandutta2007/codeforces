#include <stdio.h>
#include <algorithm>

int n,a[500500];

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	if ((n==1)&&(a[0]==1)){
		printf("2\n");
		return 0;
	}
	std::sort(a,a+n);
	printf("1");                                                         
	for (int i=1;i<n;i++){
		if ((i==n-1)&&(a[i-1]==1)&&(a[i]==1)){
			printf(" 2");
			continue;
		}
		printf(" %d",a[i-1]);
	}
	printf("\n");
}