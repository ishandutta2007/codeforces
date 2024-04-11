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

void init()
{

}

void work()
{
	int n,x;
	cin>>n;
	int odd=0;
	int even=0;
	while (n--)
	{
		cin>>x;
		if (x%2)
			odd++;
		else
			even++;
	}
	if (odd%4==0)
	{
		cout<<"Alice\n";
		return ;
	}
	if (odd%4==1)
	{
		if (even%2==0)
			cout<<"Bob\n";
		else
			cout<<"Alice\n";
		return ;
	}
	if (odd%4==2)
	{
		cout<<"Bob\n";
		return ;
	}
	if (odd%4==3)
	{
		cout<<"Alice\n";
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