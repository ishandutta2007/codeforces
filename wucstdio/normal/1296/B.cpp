#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int ans=0;
		while(n>=10)
		{
			ans+=n/10*10;
			n=n%10+n/10;
		}
		printf("%d\n",ans+n);
	}
	return 0;
}