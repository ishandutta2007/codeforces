
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
#define MOD 99991  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n,m,x;
int sum[30][MAXN];

void init()
{
	for (int i=1;i<=200000;i++)
	{
		for (int j=0;j<20;j++)
		{
			if ((i>>j)%2==1)
				sum[j][i]++;
			sum[j][i]+=sum[j][i-1];
		}
	}
}

void work()
{
	int l,r;
	scanf("%d%d",&l,&r);
	int mx=0;
	for (int j=0;j<20;j++)
	{
		mx=max(mx,sum[j][r]-sum[j][l-1]);
	}
	printf("%d\n",r-l+1-mx);


}

signed main()
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