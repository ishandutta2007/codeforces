#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[100005],mx[2];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		bool flag=1;
		mx[0]=mx[1]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<mx[a[i]&1])flag=0;
			mx[a[i]&1]=max(mx[a[i]&1],a[i]);
		}
		if(flag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}