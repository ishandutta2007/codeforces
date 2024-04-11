#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t,n;
ll a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		bool flag=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			a[i]+=a[i-1];
			a[i]-=i-1;
			if(a[i]<0)flag=0;
		}
		if(flag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}