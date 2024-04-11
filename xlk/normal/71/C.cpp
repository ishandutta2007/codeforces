#include<stdio.h>
int n,a[100020],z;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n/3;i++)
		if(n%i==0)
		{
			for(int j=0;j<i;j++)
			{
				z=1;
				for(int k=j;k<n;k+=i)
					z&=a[k];
				if(z)
				{
					puts("YES");
					return 0;
				}
			}
		}
	puts("NO");
	return 0;
}