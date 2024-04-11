#include <stdio.h>

int n, l;

int ori[50], arr[101];
int tmp[50];

int main()
{
	scanf("%d %d",&n,&l);
	for(int i=0;i<n;i++) {
		scanf("%d",ori+i);
	}
	for(int i=0;i<n;i++) {
		scanf("%d",arr+i);
		arr[n+i]=arr[i];
	}

	for(int k=0;k<n;k++) {
		bool flag=true;;
		for(int j=0;j<n-1;j++) {
			int diff=0;
			if(k+j==n-1) {
				diff=l-arr[k+j]+arr[k+j+1];
			}
			else 
				diff=arr[k+j+1]-arr[k+j];
			if(ori[j+1]-ori[j] != diff) {
				flag=false;
				break;
			}
		}
		if(flag) {
			printf("YES\n");
			return 0;
		}
	}

	printf("NO\n");

	return 0;
}