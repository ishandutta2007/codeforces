#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[1005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a[i]%=2;
		}
		bool flag=1;
		for(int i=1;i<n;i++)
			if(a[i]!=a[i+1])flag=0;
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}