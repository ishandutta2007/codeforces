#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[10005];
bool flag[10005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!flag[i])
		{
			ans++;
			for(int j=i;j<=n;j++)
			  if(a[j]%a[i]==0)flag[j]=1;
		}
	}
	printf("%d\n",ans);
	return 0;
}