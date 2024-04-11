#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int n,a[2005],ans=2147483647;
map<int,int>c;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int now=n;
	while(now>=1)
	{
		if(c[a[now]]>=1)break;
		c[a[now]]++;
		now--;
	}
	for(int i=1;i<=n;i++)
	{
		ans=min(ans,now-i+1);
		c[a[i]]++;
		while(c[a[i]]>=2&&now<=n)
		{
			now++;
			c[a[now]]--;
		}
		if(c[a[i]]>=2)break;
	}
	printf("%d\n",ans);
	return 0;
}