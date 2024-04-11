#include<stdio.h>
int a[100020];
int b[100020];
int c[100020];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i),i[a][c]++;
	for(int i=1;i<100000;i++)
		if(c[i+1]>c[i])
			return puts("-1"),0;
	printf("%d\n",c[1]);
	for(int i=0;i<n;i++)
		printf("%d ",++i[a][b]);
	return 0;
}