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
LL n;

void init()
{

}
int mxk=0;
void work()
{
	cin>>n;
	for (LL k=2;k*(k+1)/2<=n;k*=2)
	{
		LL sum=k*(k+1)/2;
		if (n>=sum && (n-sum)%k==0)
		{
			cout<<k<<'\n';
			return ;
		}
	}
	LL k=n/(n&-n);
	if (k>1 && k<=2e9 && n>=k*(k+1)/2 && (n-k*(k+1)/2)%k==0)
	{
		cout<<k<<'\n';
		return ;
	}
	for (LL k=2;k<=1000;k++)
	{
		LL sum=0;
		sum=k*(k+1)/2;
		if (n>=sum && (n-sum)%k==0)
		{
			cout<<k<<'\n';
			return ;
		}
	}
	cout<<-1<<'\n';
}

int main()
{
	init();
	int casenum=1;
	scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		#endif
		//n=1000000000000000000+testcase+65536/2-10;
		work();
	}
	return ~~(0^_^0);
}