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

LL a[MAXN];
int n;

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

void init()
{
	fac[0]=1;
	invfac[0]=1;
	for (int i=1;i<MAXN;i++)
	{
		fac[i]=fac[i-1]*i%MOD;
		invfac[i]=inv(fac[i]);
	}

}

LL C(int n,int m)
{
	return fac[n]*invfac[m]%MOD*invfac[n-m]%MOD;
}

LL f(int n,int m)
{
	return C(n+m,min(n,m));
}

void work()
{
	cin>>n;
	LL ans=1;
	LL tot=0;
	map<LL,int> mp;
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		tot+=a[i];
	}
	if (tot==0)
	{
		cout<<mpow(2,n-1)<<'\n';
		return ;
	}
	LL sum=0;
	int cnt=0;
	vector<LL> half;
	for (int i=1;i<=n;i++)
	{
		if (sum*2<tot)
			half.push_back(sum);
		if (a[i])
		{
			mp[sum]=cnt;
			cnt=1;
			sum+=a[i];
		}
		else
		{
			cnt++;
		}
	}
	mp[sum]=cnt-1;
	half.resize(unique(half.begin(), half.end())-half.begin());
	for (auto p:half)
	{
		if (mp.find(tot-p)==mp.end())
			continue;
		ans=ans*f(mp[p],mp[tot-p])%MOD;
	}
		if (tot%2==0)
		{
			ans=ans*mpow(2,mp[tot/2])%MOD;

		}
	cout<<ans<<'\n';
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