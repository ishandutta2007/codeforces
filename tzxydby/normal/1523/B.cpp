#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&x);
		printf("%d\n",3*n);
		for(int i=1;i<=n;i+=2)
		{
			printf("1 %d %d\n",i,i+1);
			printf("2 %d %d\n",i,i+1);
			printf("2 %d %d\n",i,i+1);
			printf("1 %d %d\n",i,i+1);
			printf("2 %d %d\n",i,i+1);
			printf("2 %d %d\n",i,i+1);
		}
	}
	return 0;
}