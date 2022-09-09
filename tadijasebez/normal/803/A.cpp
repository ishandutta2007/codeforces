//Maximal Binary Matrix
#include <stdio.h>
int matrix[100][100];
int main()
{
	int n,k,i,j,count=0;
	scanf("%i%i",&n,&k);
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(count==k) break;
			if(i==j)
			{
				matrix[i][j]=1;
				count++;
			}
			else
			{
				if(k-count>1)
				{
					matrix[i][j]=1;
					matrix[j][i]=1;
					count+=2;
				}
			}
		}
	}
	if(count==k)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%i ",matrix[i][j]);
			}
			printf("\n");
		}
	}
	else printf("-1");
	return 0;
}