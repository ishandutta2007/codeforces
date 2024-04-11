#include <bits/stdc++.h>
using namespace std;
#define ldb long double
vector<int> sol;
const int N=1000050;
const int L=20;
const int inf=1e9+7;
int a[N],b[N],mx[N][L],mn[N][L],logs[N];
void BuildSparseTables(int n)
{
	int i,j;
	for(i=2;i<=n;i++) logs[i]=logs[i>>1]+1;
	for(i=1;i<=n;i++) mx[i][0]=a[i],mn[i][0]=b[i];
	for(j=1;j<L;j++)
	{
		for(i=1;i<=n-(1<<j)+1;i++)
		{
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<j-1)][j-1]);
			mn[i][j]=min(mn[i][j-1],mn[i+(1<<j-1)][j-1]);
		}
	}
}
int Max(int l, int r)
{
	if(l>r) return 0;
	int k=logs[r-l+1];
	return max(mx[l][k],mx[r-(1<<k)+1][k]);
}
int Min(int l, int r)
{
	int k=logs[r-l+1];
	return min(mn[l][k],mn[r-(1<<k)+1][k]);
}
ldb F[N];
double binom(int n, int k)
{
	//printf("(%i nad %i) ",n,k);
	if(k>n) return 0;
	return F[n]/F[k]/F[n-k];
}
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),a[i]*=100;
	for(i=1;i<=n;i++) scanf("%i",&b[i]);b[n+1]=0;
	BuildSparseTables(n+1);
	for(i=1;i<=n;i++)
	{
		int top=n,bot=i,mid,ans=n+1;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(Max(i,mid)>Min(i,mid)) ans=mid,top=mid-1;
			else bot=mid+1;
		}
		sol.push_back(max(Min(i,ans),Max(i,ans-1)));
	}
	sort(sol.begin(),sol.end());
	ldb sum=0;
	//F[0]=1;
	//for(i=1;i<=n;i++) F[i]=F[i-1]*i;
	F[1]=(ldb)k/n;
	for(i=2;i<=n-k+1;i++) F[i]=F[i-1]*(n-i-k+2)/(n-i+1);
	for(i=0;i<sol.size();i++)
	{
		if(F[i+1]>1e-22) sum+=F[i+1]*sol[i];
		//printf("%i ",sol[i]);
		//cout << F[i+1] << " ";
	}
	//printf("%llf\n",sum/binom(n,k));
	cout << fixed << setprecision(10) << sum << "\n";
	return 0;
}