#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[200005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			a[i]+=i;
			a[i]%=n;
			if(a[i]<0)a[i]+=n;
		}
		sort(a,a+n);
		bool flag=1;
		for(int i=1;i<n;i++)
		{
			if(a[i]==a[i-1])
			{
				flag=0;
				break;
			}
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}