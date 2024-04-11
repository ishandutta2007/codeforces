#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,k;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		if(n%2==k%2)
		{
			if(k>n)printf("NO\n");
			else
			{
				printf("YES\n");
				for(int i=1;i<k;i++)printf("1 ");
				printf("%d\n",n-k+1);
			}
		}
		else if(n%2==0)
		{
			if(2*k>n)printf("NO\n");
			else
			{
				printf("YES\n");
				for(int i=1;i<k;i++)printf("2 ");
				printf("%d\n",n-2*k+2);
			}
		}
		else printf("NO\n");
	}
	return 0;
}