#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[300005],ans=1000000000;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans=min(ans,min(i==1?ans:a[i]/(i-1),i==n?ans:a[i]/(n-i)));
	}
	printf("%d\n",ans);
	return 0;
}