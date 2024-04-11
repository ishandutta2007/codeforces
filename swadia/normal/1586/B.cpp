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

int buc[MAXN];
int n,m;

void init()
{

}

void work()
{
	int y,z,x;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		buc[i]=0;
	for (int i=0;i<m;i++)
	{
		scanf("%d%d%d",&y,&x,&z);
		buc[x]++;
	}
	for (int i=1;i<=n;i++)
	{
		if (buc[i])
			continue;
		for (int j=1;j<=n;j++)
			if (i!=j)
			{
				printf("%d %d\n",i,j);
			}
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