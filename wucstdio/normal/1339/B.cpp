#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		if(n&1)printf("%d ",a[n/2+1]);
		for(int i=n/2;i>=1;i--)printf("%d %d ",a[i],a[n-i+1]);
		printf("\n");
	}
	return 0;
}