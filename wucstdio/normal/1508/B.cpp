#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,b[100005];
ll k;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%lld",&k);
		k--;
		if(k>>min(61,n-1))
		{
			printf("-1\n");
			continue;
		}
		for(int i=2;i<=n;i++)
		{
			if(n-i>60)b[i]=0;
			else if((1ll<<(n-i))&k)b[i]=1;
			else b[i]=0;
		}
		int now=1;
		for(int i=2;i<=n;i++)
		{
			if(b[i])continue;
			if(b[i]==0)
			{
				for(int j=i-1;j>=now;j--)
				  printf("%d ",j);
				now=i;
			}
		}
		for(int j=n;j>=now;j--)printf("%d ",j);
		printf("\n");
	}
	return 0;
}