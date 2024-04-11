#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
int a[N],logs[N],Table[2][N][20];
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
int nxt(int i, int j){ return i+(1<<(j-1));}
void BuildSparseTable(int n)
{
	Preprocess();
	int i,j;
	for(i=1;i<=n;i++) Table[0][i][0]=a[i];
	for(i=1;i<=n;i++) Table[1][i][0]=a[i];
	for(j=1;j<20;j++)
	{
		for(i=1;i<=n-(1<<j)+1;i++)
		{
			Table[0][i][j]=min(Table[0][i][j-1],Table[0][nxt(i,j)][j-1]);
			Table[1][i][j]=max(Table[1][i][j-1],Table[1][nxt(i,j)][j-1]);
		}
	}
}
int Query(int l, int r)
{
	int k=logs[r-l+1];
	return max(Table[1][l][k],Table[1][r-(1<<k)+1][k])-min(Table[0][l][k],Table[0][r-(1<<k)+1][k]);
}
vector< pair<int,int> > sol;
int res;
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	BuildSparseTable(n);
	int top,bot,mid,ans;
	for(i=1;i<=n;i++)
	{
		top=n,bot=i,ans=i;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(Query(i,mid)<=k) ans=mid,bot=mid+1;
			else top=mid-1;
		}
		if(ans-i+1>res) res=ans-i+1,sol.clear();
		if(ans-i+1==res) sol.push_back(make_pair(i,ans));
	}
	printf("%i %i\n",res,sol.size());
	for(i=0;i<sol.size();i++) printf("%i %i\n",sol[i].first,sol[i].second);
	return 0;
}