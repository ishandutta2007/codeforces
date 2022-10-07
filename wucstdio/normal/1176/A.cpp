#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int q;
ll n;
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%I64d",&n);
		int ans=0;
		while(n!=1)
		{
			if(n%2==0)n/=2,ans++;
			else if(n%3==0)n=n*2/3,ans++;
			else if(n%5==0)n=n*4/5,ans++;
			else
			{
				ans=-1;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}