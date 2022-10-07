#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n,a[100005],b[100005];
int main()
{
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%I64d",&b[i]);
	for(int i=n;i>=2;i--)a[i]-=a[i-1],b[i]-=b[i-1];
	sort(a+2,a+n+1);
	sort(b+2,b+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=b[i])
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}