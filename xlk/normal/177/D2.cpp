#include<stdio.h>
int n,m,c,t;
int a[100020];
int b[100020];
int main()
{
	scanf("%d %d %d",&n,&m,&c);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=0;i<m;i++)
		scanf("%d",b+i);
	for(int i=0;i<n;i++)
	{
		if(i<m)
			t+=b[i];
		if(i>n-m)
			t-=b[i-n+m-1];
		printf("%d ",(a[i]+t)%c);
	}
	return 0;
}