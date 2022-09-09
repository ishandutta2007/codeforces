#include <stdio.h>
#include <algorithm>
using namespace std;
#define mp make_pair
int Read(){ char c;while((c=getchar())<'0' || c>'9');return c-'0';}
int min(int a, int b){ return a>b?b:a;}
pair<int,int> min(pair<int,int> a, pair<int,int> b){ return a>b?b:a;}
const int N=4050;
const int inf=1e9+7;
int a[N][N],dp[N][N];
int Get(int l, int r){ return (a[r][r]-a[r][l]-a[l][r]+a[l][l])/2;}
void Solve(int k, int l, int r, int L, int R)
{
	if(l>r) return;
	int mid=l+r>>1;
	pair<int,int> sol=mp(inf,inf);
	for(int i=L;i<=min(mid,R);i++)
	{
		sol=min(sol,mp(dp[k-1][i]+Get(i,mid),i));
	}
	dp[k][mid]=sol.first;
	Solve(k,l,mid-1,L,sol.second);
	Solve(k,mid+1,r,sol.second,R);
}
int main()
{
	int n,k,i,j;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) a[i][j]=Read()+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	for(i=1;i<=n;i++) dp[0][i]=inf;
	for(i=1;i<=k;i++) Solve(i,1,n,0,n);
	printf("%i\n",dp[k][n]);
	return 0;
}