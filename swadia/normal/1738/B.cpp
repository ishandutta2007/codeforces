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

int n,k;
LL sum[MAXN];
LL a[MAXN];

void init()
{

}

void work()
{
	scanf("%d%d",&n,&k);
	for (int i=n-k+1;i<=n;i++)
		scanf("%lld",&sum[i]);
	if (k==n)
	{
		for (int i=1;i<=n;i++)
			a[i]=sum[i]-sum[i-1];
		for (int i=1;i<n;i++)
			if (a[i]>a[i+1])
			{
				cout<<"No\n";
				return ;
			}
		cout<<"Yes\n";
		return ;

	}
	if (k==1)
	{
		cout<<"Yes\n";
		return ;
	}
	for (int i=n-k+2;i<=n;i++)
		a[i]=sum[i]-sum[i-1];
	for (int i=n-k+2;i<n;i++)
		if (a[i]>a[i+1])
		{
			cout<<"No\n";
			return ;
		}
	if (sum[n-k+1]-a[n-k+2]*(n-k+1)>0)
		cout<<"No\n";
	else
		cout<<"Yes\n";
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