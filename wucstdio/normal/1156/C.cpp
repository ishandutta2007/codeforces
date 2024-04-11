#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,z,a[200005],ans;
int main()
{
	scanf("%d%d",&n,&z);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int now=n/2+1;
	for(int i=1;i<=n/2;i++)
	{
		while(now<=n&&a[now]-a[i]<z)now++;
		if(now>n)break;
		ans++,now++;
	}
	printf("%d\n",ans);
	return 0;
}