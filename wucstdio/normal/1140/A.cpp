#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[10005];
int main()
{
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]=max(a[i],a[i-1]);
		if(a[i]==i)ans++;
	}
	printf("%d\n",ans);
	return 0;
}