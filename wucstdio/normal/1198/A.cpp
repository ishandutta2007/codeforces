#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,m,a[400005],b[400005];
int main()
{
	scanf("%d%d",&n,&m);
	m=m*8/n;
	m=min(m,30);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(i!=1&&a[i]==a[i-1])b[i]=b[i-1];
		else b[i]=b[i-1]+1;
	}
	for(int i=1;i<=n;i++)a[i]=b[i];
	if((1<<m)>=a[n]-a[1]+1)
	{
		printf("0\n");
		return 0;
	}
	int r=1,ans=n;
	for(int l=1;l<=n;l++)
	{
		while(r<=n&&a[r]-a[l]+1<=1<<m)r++;
		ans=min(ans,l+n-r);
	}
	printf("%d\n",ans);
	return 0;
}