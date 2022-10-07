#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[200005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int now=1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		while(now<=n&&a[now]<i)now++;
		if(now>n)break;
		now++;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}