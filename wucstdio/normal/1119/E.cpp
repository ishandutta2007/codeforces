#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,a[300005];
ll ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int last=1;
	while(last<=n&&a[last]<2)last++;
	for(int i=1;i<=n;i++)
	{
		if(last==i)
		{
			last++;
			while(last<=n&&a[last]<2)last++;
		}
		ans+=a[i]/3;
		a[i]%=3;
		while(a[i])
		{
			a[i]--;
			if(last==n+1)continue;
			else
			{
				ans++,a[last]-=2;
				while(last<=n&&a[last]<2)last++;
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}