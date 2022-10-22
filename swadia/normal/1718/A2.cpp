#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))

#ifdef _DEBUG_
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define MRK() ;
#define WRT(x) ;
#endif

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-8

#define _ 0
using namespace std;

int n;
int a[MAXN];
int sum[MAXN];
int dp[MAXN];
void init()
{

}

void work()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		dp[i]=INF;
	map<int,int> mp;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	mp[0]=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==0)
			dp[i]=dp[i-1];
		dp[i]=min(dp[i],dp[i-1]+1);
		if (mp.find(sum[i])!=mp.end())
		{
			dp[i]=min(dp[i],dp[mp[sum[i]]]+(i-mp[sum[i]]-1));

		}
		//WRT(dp[i])
		mp[sum[i]]=i;
	}
	cout<<dp[n]<<endl;
}

int main()
{
	init();
	int casenum=1;
	scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}