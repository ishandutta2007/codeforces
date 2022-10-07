#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[500005],last[500005],en[500005];
int maxx[26][500005],lg2[500005];
int ask(int l,int r)
{
	if(l>r)return 0;
	int d=lg2[r-l+1];
	return max(maxx[d][l],maxx[d][r-(1<<d)+1]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i+n]=a[i];
		a[i+2*n]=a[i];
		a[i+3*n]=a[i];
		a[i+4*n]=a[i];
	}
	for(int i=2;i<=5*n;i++)lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=5*n;i++)maxx[0][i]=a[i];
	for(int i=1;i<=lg2[5*n];i++)
	  for(int j=1;j<=5*n;j++)
		maxx[i][j]=max(maxx[i-1][j],maxx[i-1][j+(1<<(i-1))]);
	memset(en,0x3f,sizeof(en));
	for(int i=1;i<=5*n;i++)
	{
		int l=1,r=i-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(ask(mid,i-1)>a[i]*2)l=mid+1;
			else r=mid-1;
		}
		last[i]=r;
		en[r]=min(en[r],i);
	}
	for(int i=5*n;i>=1;i--)en[i]=min(en[i],en[i+1]);
	for(int i=1;i<=n;i++)
	{
		if(en[i]>1000000000)printf("-1 ");
		else printf("%d ",en[i]-i);
	}
	printf("\n");
	return 0;
}