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
#define EPS 1e-5

#define _ 0
using namespace std;
#define int LL
int x[MAXN],y[MAXN],w[MAXN];
LL dp[MAXN];
int n;
 
void init()
{

}

void work()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&x[i],&y[i],&w[i]);
	}
	for (int i=1;i<=n;i++)
	{
		int id=lower_bound(x+1,x+n+1,y[i])-x;
		dp[i]=(dp[i-1]+(x[i]-x[i-1])+dp[i-1]-dp[id-1]-(y[i]-x[id-1])+(x[i]-x[i-1]))%MOD;
		WRT(dp[i])
	}
	LL ans=0;
	for (int i=1;i<=n;i++)
	{
		int id=lower_bound(x+1,x+n+1,y[i])-x;
		ans+=x[i]-x[i-1];
		if (w[i]==1)
			ans+=dp[i-1]-(dp[id-1]+(y[i]-x[id-1]))+x[i]-x[i-1];
	}
	cout<<((ans+1)%MOD+MOD)%MOD;
}

signed main()
{
	#ifdef _DEBUG_
	//freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}