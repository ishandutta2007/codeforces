#include<stdio.h>
int n,z,a[120][120];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",a[i]+j);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i==n/2||j==n/2||i==j||i+j==n-1)
				z+=a[i][j];
	printf("%d",z);
	return 0;
}