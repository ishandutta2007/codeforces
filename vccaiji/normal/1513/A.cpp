#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int main()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&k);
		if(k>(n-1)/2) printf("-1");
		else
		{
			printf("1");
			for(int j=1;j<=k;j++)
			{
				printf(" %d %d",n-j+1,j+1);
			}
			for(int j=k+2;j<=n-k;j++) printf(" %d",j);
		}
		if(i<t) printf("\n");
	}
	return 0;
}