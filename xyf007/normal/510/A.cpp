#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		if(i&1)
		{
			for(int i=1;i<=m;i++)
			{
				printf("#");
			}
			printf("\n");
		}
		if(!(i%2)&&(i%4))
		{
			for(int i=1;i<m;i++)
			{
				printf(".");
			}
			printf("#\n");
		}
		if(!(i%4))
		{
			printf("#");
			for(int i=1;i<m;i++)
			{
				printf(".");
			}
			printf("\n");
		}
	}
	return 0;
}