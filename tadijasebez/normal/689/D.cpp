#include <stdio.h>
const int N=200050;
int a[N],b[N],logs[N],Table[2][N][20];
void Preprocess()
{
	int k=1,i;
	for(i=0;i<N;i++)
	{
		if(i==1<<k) k++;
		logs[i]=k-1;
	}
}
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
void BuildSparseTable(int n)
{
	Preprocess();
	int i,j;
	for(i=1;i<=n;i++) Table[0][i][0]=a[i];
	for(i=1;i<=n;i++) Table[1][i][0]=b[i];
	for(j=1;j<20;j++)
	{
		for(i=1;i<=n-(1<<j)+1;i++)
		{
			Table[0][i][j]=max(Table[0][i][j-1],Table[0][i+(1<<(j-1))][j-1]);
			Table[1][i][j]=min(Table[1][i][j-1],Table[1][i+(1<<(j-1))][j-1]);
		}
	}
}
#define ll long long
ll Query(int l, int r)
{
	int k=logs[r-l+1];
	return 1ll*max(Table[0][l][k],Table[0][r-(1<<k)+1][k])-min(Table[1][l][k],Table[1][r-(1<<k)+1][k]);
}
ll sol;
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++) scanf("%i",&b[i]);
	BuildSparseTable(n);
	for(i=1;i<=n;i++)
	{
		int ans1=n+1,ans2=n+1,top=n,bot=i,mid;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(Query(i,mid)<0) bot=mid+1;
			else ans1=mid,top=mid-1;
		}
		top=n;bot=i;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(Query(i,mid)<=0) bot=mid+1;
			else ans2=mid,top=mid-1;
		}
		sol+=ans2-ans1;
	}
	printf("%lld\n",sol);
	return 0;
}