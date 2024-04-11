#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,t,ans,mint=1000000000;
int main()
{
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
	{
		int s,d;
		scanf("%d%d",&s,&d);
		if(s>=t)
		{
			if(s<mint)
			{
				mint=s;
				ans=i;
			}
			continue;
		}
		int x=(t-s-1)/d+1;
		s=s+d*x;
		if(s<mint)
		{
			mint=s;
			ans=i;
		}
	}
	printf("%d\n",ans);
	return 0;
}