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
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		bool flag=0;
		for(int i=2;i<=n;i++)
		{
			if(abs(a[i]-a[i-1])>1)
			{
				printf("YES\n%d %d\n",i-1,i);
				flag=1;
				break;
			}
		}
		if(!flag)printf("NO\n");
	}
	return 0;
}