#include"stdio.h"
int main()
{
	int n;
	scanf("%d",&n);
	int max[n+1];
	int child[n+1];
	max[1]=1;
	child[1]=0;
	for(int x=0;x<=n;x++)max[x]=0;
	for(int x=1;x<=n;x++)
	{
		for(int y=x+x;y<=n;y+=x)
		{
			if(max[y]<max[x]+1)
			{
				max[y]=max[x]+1;
				child[y]=x;
			}
		}
	}
	printf("%d",n);
	n=child[n];
	while(n)
	{
		printf(" %d",n);
		n=child[n];
	}
}