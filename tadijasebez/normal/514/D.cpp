#include <stdio.h>
const int N=100050;
int Table[5][N][20],logs[N],A[5][N];
void Preprocess()
{
	int k=0,i;
	for(i=0;i<N;i++)
	{
		if(i==1<<(k+1)) k++;
		logs[i]=k;
	}
}
int max(int a, int b){ return a>b?a:b;}
void BuildSparseTable(int n, int m)
{
	Preprocess();
	int k,i,j;
	for(k=0;k<m;k++)
	{
		for(i=1;i<=n;i++) Table[k][i][0]=A[k][i];
		for(j=1;j<20;j++)
		{
			for(i=1;i<=n-(1<<j)+1;i++)
			{
				Table[k][i][j]=max(Table[k][i][j-1],Table[k][i+(1<<(j-1))][j-1]);
			}
		}
	}
}
int Query(int t, int l, int r)
{
	int k=logs[r-l+1];
	return max(Table[t][l][k],Table[t][r-(1<<k)+1][k]);
}
int n,m,k;
int sol[5],tmp[5],sum;
bool Check(int l)
{
	int i,j;
	for(i=1;i<=n-l+1;i++)
	{
		sum=0;
		for(j=0;j<m;j++)
		{
			tmp[j]=Query(j,i,i+l-1);
			sum+=tmp[j];
		}
		if(sum<=k)
		{
			for(j=0;j<m;j++) sol[j]=tmp[j];
			return true;
		}
	}
	return false;
}
int main()
{
	int i,j;
	scanf("%i %i %i",&n,&m,&k);
	for(i=1;i<=n;i++) for(j=0;j<m;j++) scanf("%i",&A[j][i]);
	BuildSparseTable(n,m);
	int top=n,bot=1,mid;
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(Check(mid)) bot=mid+1;
		else top=mid-1;
	}
	for(j=0;j<m;j++) printf("%i ",sol[j]);
	printf("\n");
	return 0;
}