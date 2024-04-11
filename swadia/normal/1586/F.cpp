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

int n,m;
void init()
{

}

int ans[1010][1010];
void work()
{
	cin>>n>>m;
	int cnt=0;
	int M=1;
	while (1)
	{
		cnt++;
		M*=m;
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
				if (ans[i][j]==0 && i/M==j/M)
					ans[i][j]=cnt;
		if ((n-1)/M==0)
			break;
	}
	cout<<cnt<<endl;
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			cout<<ans[i][j]<<' ';

}

int main()
{
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