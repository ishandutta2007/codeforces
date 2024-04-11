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

typedef pair<LL,LL> pll;
LL fib[MAXN];
int n;
pll c[MAXN];
void init()
{
	fib[1]=fib[2]=1;
	for (int i=3;i<=100;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		//WRT(fib[i])
	}
}

//1 1 2 3 5 8
void work()
{
	LL sum=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>c[i].first;
		c[i].second=i;
		sum+=c[i].first;
	}
	int r=0;
	for (int i=1;;i++)
	{
		sum-=fib[i];
		//WRT(sum)
		if (sum<0)
		{
			WRT(sum)
			cout<<"NO\n";
			return ;
		}
		if (sum==0)
		{
			r=i;
			break;
		}
	}
	int lst=-1;
	while (r)
	{
		sort(c+1,c+n+1,greater<pll>());
		//for (int i=1;i<=n;i++)
		//	cout<<c[i].first<<' ';
		//cout<<endl;
		bool ok=false;
		for (int i=1;i<=n;i++)
		{
			if (c[i].second!=lst && c[i].first>=fib[r])
			{
				ok=true;
				lst=c[i].second;
				c[i].first-=fib[r];
				break;
			}
		}
		if (!ok)
		{
			cout<<"NO\n";
			return ;
		}
		r--;
	}
	cout<<"YES\n";
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