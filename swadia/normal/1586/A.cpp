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

#define MAXN 101000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n;
int a[MAXN];

int notprime[MAXN];
void init()
{
	for (int i=2;i<MAXN;i++)
		for (int j=i*2;j<MAXN;j+=i)
			notprime[j]=1;
}

void work()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	int sum=0;
	for (int i=1;i<=n;i++)
		sum+=a[i];
	if (notprime[sum])
	{
		cout<<n<<endl;
		for (int i=1;i<=n;i++)
			cout<<i<<' ';
		cout<<endl;
		return ;
	}
	for (int i=1;i<=n;i++)
		if (notprime[sum-a[i]])
		{
			cout<<n-1<<endl;
			for (int j=1;j<=n;j++)
				if (i!=j)
					cout<<j<<' ';
			cout<<endl;
			return ;
		}
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