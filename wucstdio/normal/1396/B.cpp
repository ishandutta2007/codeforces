#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[1005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int sum=0;
		for(int i=1;i<n;i++)sum+=a[i];
		a[n]=min(a[n],sum+1);
		sum+=a[n];
		if(sum&1)printf("T\n");
		else printf("HL\n");
	}
	return 0;
}