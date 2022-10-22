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
#define EPS 1e-8

#define _ 0
using namespace std;

LL fac[MAXN];
LL invfac[MAXN];

LL mpow(LL x,LL n)
{
	LL ans=1;
	while (n)
	{
		if (n&1)
			ans=ans*x%MOD;
		x=x*x%MOD;
		n>>=1;
	}
	return ans;
}

LL inv(LL x)
{
	return mpow(x,MOD-2);
}

LL C(int n,int x)
{
	return fac[n]*invfac[x]%MOD*invfac[n-x]%MOD;
}

void init()
{
	fac[0]=invfac[0]=1;
	for (int i=1;i<MAXN;i++)
	{
		fac[i]=fac[i-1]*i%MOD;
		invfac[i]=inv(fac[i]);
	}
}

int n;
int a[MAXN];
vector<int> v[MAXN];
void work()
{
	cin>>n;
	LL ans=0;
	for (int i=0;i<=n;i++)
	{
		cin>>a[i];
		if (a[i])
			ans+=C(i+a[i],i+1);
	}
	cout<<ans%MOD<<endl;
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