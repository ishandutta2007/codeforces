#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[400005],st[25][400005],lg2[400005],f[200005],maxx[200005];
int GCD(int i,int j)
{
	int k=lg2[j-i+1];
	return __gcd(st[k][i],st[k][j-(1<<k)+1]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		st[0][i]=a[i];
	}
	for(int i=2;i<=n;i++)
		lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=lg2[n];i++)
		for(int j=1;j<=n;j++)
			st[i][j]=__gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(GCD(mid,i)<i-mid+1)l=mid+1;
			else r=mid-1;
		}
		if(GCD(l,i)==i-l+1)maxx[i]=l;
		maxx[i]=max(maxx[i],maxx[i-1]);
		if(maxx[i]==0)f[i]=0;
		else f[i]=f[maxx[i]-1]+1;
		printf("%d ",f[i]);
	}
	printf("\n");
	return 0;
}