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


void init()
{

}

void work()
{
	int n,c;
	scanf("%d%d",&n,&c);
	vector<int> v(n);
	vector<int> buc(2*c+1);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&v[i]);
		buc[v[i]]=1;
	}
	for (int i=1;i<=2*c;i++)
		buc[i]=buc[i-1]+buc[i];
	for (int i=1;i<=c;i++)
		if (buc[i]-buc[i-1])
		{
			for (int j=i;j<=c;j+=i)
			{
				if (buc[j+i-1]-buc[j-1] && buc[j/i]-buc[j/i-1]==0)
				{
					//cout<<i<<' '<<j<<endl;
					printf("No\n");
					return ;
				}
			}
		}
	printf("Yes\n");
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