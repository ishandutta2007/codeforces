#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n;
ll a[505],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	n=max(n,3);
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++)
	    for(int k=j+1;k<=n;k++)
	      ans=max(ans,a[i]|a[j]|a[k]);
	printf("%lld\n",ans);
	return 0;
}