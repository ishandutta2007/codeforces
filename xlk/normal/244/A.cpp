#include<stdio.h>
int n,k,a[40],v[1000];
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<k;i++)
		scanf("%d",a+i),v[a[i]]=1;
	for(int i=0;i<k;i++)
	{
		int t=n-1;
		for(int i=1;t&&i<=n*k;i++)
			if(!v[i])
				printf("%d ",i),v[i]=1,t--;
		printf("%d\n",a[i]);
	}
}