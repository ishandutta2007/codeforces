#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005],num[200005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++)
	    num[a[i]+a[j]]++;
	int ans=0;
	for(int i=1;i<=200000;i++)
	  ans=max(ans,num[i]);
	printf("%d\n",ans);
	return 0;
}