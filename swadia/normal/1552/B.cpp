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

int r[MAXN][5];
int n;
void init()
{

}

bool sup(int x,int y)
{
	int cnt=0; 
	for (int i=0;i<5;i++)
		if (r[x][i]<r[y][i])
			cnt++;
	return cnt>=3;
}
void work()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		scanf("%d%d%d%d%d",&r[i][0],&r[i][1],&r[i][2],&r[i][3],&r[i][4]);
	int ans=1;
	for (int i=2;i<=n;i++)
	{
		if (sup(i,ans))
			ans=i;
		else if (sup(ans,i))
			continue;
		else
		{
			cout<<-1<<endl;
			return;
		}
	}
	for (int i=1;i<=n;i++)
		if (ans!=i)
		{
			if (!sup(ans,i))
			{
				cout<<-1<<endl;
				return;
			}
			
		}
	cout<<ans<<endl; 
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
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