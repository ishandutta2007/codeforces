#include <stdio.h>
#include <math.h>
int main()
{
	long int n,count=1;
	scanf("%ld\n",&n);
	char a[n],b[2];
	int flag[2];
	flag[0]=0;
	flag[1]=0;
	scanf("%s",a);
	for (int i = 0; i < n; ++i)
	{	if (flag[0]==0)
			{
				if (a[i]=='R')
				{	flag[0]=1;
					b[0]='R';
					continue;
				}
				if (a[i]=='L')
				{	flag[0]=1;
					b[0]='L';
					continue;
				}
			}

		if (flag[1]==0)
		{	
			if (a[i]=='U')
			{	flag[1]=1;
				b[1]='U';
				continue;
			}
			if (a[i]=='D')
			{	flag[1]=1;
				b[1]='D';
				continue;
			}
		}
		
		if ((a[i]!=b[0])&&(a[i]!=b[1]))
		{
			count++;
			if (a[i]=='R')
				{
					b[0]='R';
					flag[1]=0;
					continue;
				}
				if (a[i]=='L')
				{
					b[0]='L';
					flag[1]=0;
					continue;
				}
				if (a[i]=='U')
			{
				b[1]='U';
				flag[0]=0;
				continue;
			}
			if (a[i]=='D')
			{
				b[1]='D';
				flag[0]=0;
				continue;
			}

			
		}
		
	}
	
	printf("%ld\n",count );
	return 0;
}