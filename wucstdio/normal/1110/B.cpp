#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,k,a[100005];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)
	  a[i]=a[i]-a[i-1]-1;
	a[1]=2147483647;
	int ans=n;
	sort(a+1,a+n+1);
	n--;
	for(int i=1;i<=n-k+1;i++)
	  ans+=a[i];
	printf("%d\n",ans);
	return 0;
}