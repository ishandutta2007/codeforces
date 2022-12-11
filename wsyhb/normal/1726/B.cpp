#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		if(m<n)
			puts("NO");
		else
		{
			if(n&1)
			{
				puts("YES");
				for(int i=1;i<=n-1;++i)
					printf("1 ");
				printf("%d\n",m-n+1);
			}
			else if(m%2==0)
			{
				puts("YES");
				for(int i=1;i<=n-2;++i)
					printf("1 ");
				printf("%d %d\n",(m-n+2)/2,(m-n+2)/2);
			}
			else if(n==2)
				puts("NO");
			else if(m==n+1)
				puts("NO");
			else
				puts("NO");
		}
	}
	return 0;
}