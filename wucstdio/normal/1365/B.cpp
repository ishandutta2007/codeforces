#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[505],b[505],f[2];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		f[0]=f[1]=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]),f[b[i]]=1;
		if(f[0]&&f[1])
		{
			printf("Yes\n");
			continue;
		}
		bool flag=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i-1]>a[i])
			{
				flag=0;
				break;
			}
		}
		if(flag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}