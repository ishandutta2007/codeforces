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
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n;
LL a[MAXN];
int btcnt[62];
void work()
{
	cin>>n;
	for (int i=0;i<62;i++)
		btcnt[i]=0;
	for (int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		for (int j=0;j<60;j++)
			btcnt[j]+=((a[i]>>j)&1);
	}
	LL ans=0;
	for (int i=0;i<n;i++)
	{
		LL sum1=0,sum2=0;
		for (int j=0;j<60;j++)
		{
			if ((a[i]>>j)&1)
			{
				sum1+=(LL)n*((1ll<<j)%MOD)%MOD;
			}
			else
			{
				sum1+=(LL)btcnt[j]*((1ll<<j)%MOD)%MOD;
			}
		}
		for (int j=0;j<60;j++)
		{
			if ((a[i]>>j)&1)
			{
				//WRT(btcnt[j])
				sum2+=(LL)btcnt[j]*((1ll<<j)%MOD)%MOD;
			}
		}
		//cout<<sum1<<' '<<sum2<<endl;
		ans+=sum1%MOD*(sum2%MOD)%MOD;
	}
	cout<<ans%MOD<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
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