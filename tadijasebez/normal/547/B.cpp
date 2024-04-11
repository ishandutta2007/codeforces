#include <stdio.h>
const int N=200050;
int logs[N];
void Preprocess()
{
	int k=0,i;
	for(i=1;i<N;i++)
	{
		if(i==(1<<(k+1))) k++;
		logs[i]=k;
	}
}
int Table[N][20];
int A[N];
void BuildSparseTable(int n)
{
	int i,j;
	for(i=1;i<=n;i++) Table[i][0]=i;
	for(j=1;j<20;j++)
	{
		for(i=1;i<=n-(1<<j)+1;i++)
		{
			if(A[Table[i][j-1]]<A[Table[i+(1<<(j-1))][j-1]])
				Table[i][j]=Table[i][j-1];
			else Table[i][j]=Table[i+(1<<(j-1))][j-1];
		}
	}
}
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int RMQ(int u, int v)
{
	int k=logs[v-u+1];
	return min(A[Table[u][k]],A[Table[v-(1<<k)+1][k]]);
}
int sol[N];
int BinarySearch(int x, int n)
{
	int sol1=0,sol2=0,top,bot,mid;
	bot=x;
	top=n;
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(RMQ(x,mid)==A[x]) sol1=mid,bot=mid+1;
		else top=mid-1;
	}
	bot=1;
	top=x;
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(RMQ(mid,x)==A[x]) sol2=mid,top=mid-1;
		else bot=mid+1;
	}
	return sol1-sol2+1;
}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&A[i]);
	Preprocess();
	BuildSparseTable(n);
	for(i=1;i<=n;i++)
	{
		int tmp=BinarySearch(i,n);
		sol[tmp]=max(sol[tmp],A[i]);
	}
	for(i=n;i;i--) sol[i-1]=max(sol[i-1],sol[i]);
	for(i=1;i<=n;i++) printf("%i ",sol[i]);
	printf("\n");
	return 0;
}