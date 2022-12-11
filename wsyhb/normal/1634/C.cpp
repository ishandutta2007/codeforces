#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if(n*k%2==1)
		{
			if(k==1)
			{
				puts("YES");
				for(int i=1;i<=n;++i)
					printf("%d\n",i);
			}
			else
				puts("NO");
		}
		else
		{
			if(n%2==0)
			{
				puts("YES");
				for(int i=1,sum=0;i<=n;i+=2,sum+=2*k)
				{
					for(int j=1;j<=2*k-1;j+=2)
						printf("%d%c",sum+j,j<2*k-1?' ':'\n');
					for(int j=2;j<=2*k;j+=2)
						printf("%d%c",sum+j,j<2*k?' ':'\n');
				}
			}
			else
				puts("NO");
		}
	}
	return 0;
}