#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int now=2;
	for(int i=1;i<=n;i++)
	{
		while(a[now]<=a[i]&&now<=n)now++;
		if(now>n)break;
		ans++,now++;
	}
	printf("%d\n",ans);
	return 0;
}