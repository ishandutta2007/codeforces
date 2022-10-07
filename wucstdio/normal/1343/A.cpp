#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=4;i<=n+1;i*=2)
		{
			if(n%(i-1)==0)
			{
				printf("%d\n",n/(i-1));
				break;
			}
		}
	}
	return 0;
}