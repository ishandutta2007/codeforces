#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,h,a[1005],b[1005];
int main()
{
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)b[j]=a[j];
		sort(b+1,b+i+1);
		int tot=0;
		for(int j=i;j>=1;j-=2)tot+=b[j];
		if(tot>h)
		{
			printf("%d\n",i-1);
			return 0;
		}
	}
	printf("%d\n",n);
	return 0;
}