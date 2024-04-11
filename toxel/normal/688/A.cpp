#include<stdio.h>
#include<string.h>
int main()
{
	int n,d,i,j;
	char s[100][110],all[100],sum,max=0;
	memset(all,0,100*sizeof(int));
	scanf("%d%d",&n,&d);
	for (i=0;i<d;i++)
	{
		scanf("%s",s[i]);
		for (j=0;j<n;j++)
			if (s[i][j]=='0')
			{
				all[i]=1;
				break;
			}
	}
	for (i=0;i<d;i++)
	{
		if (all[i])
		{
			sum++;
			if (sum>max)
				max=sum;
		}
		else
			sum=0;
	}
	printf("%d",max);
	return 0;
}