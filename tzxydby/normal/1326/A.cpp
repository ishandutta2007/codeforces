#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			puts("-1");
		}
		else
		{
			printf("2");
			for(int i=2;i<=n;i++)
				printf("3");
			puts("");
		}
	}
	return 0;
}