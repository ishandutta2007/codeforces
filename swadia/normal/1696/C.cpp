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

int n,m,k;
LL a[MAXN],b[MAXN];
typedef pair<LL,LL> pii;
void init()
{

}

vector<pii> fk(LL *a,int n)
{
	vector<pii> va;
	va.push_back({-1,0});
	for (int i=1;i<=n;i++)
	{
		LL p=a[i];
		LL cnt=1;
		while (p%k==0)
		{
			p/=k;
			cnt*=k;
		}
		if (va.back().first==p)
			va.back().second+=cnt;
		else
			va.push_back({p,cnt});
	}
	return va;

}

void work()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	for (int i=1;i<=m;i++)
		cin>>b[i];
	if (accumulate(a+1,a+1+n,0ll)!=accumulate(b+1,b+1+m,0ll))
	{
		cout<<"No\n";
		return ;
	}
	if (fk(a,n)==fk(b,m))
	{
		cout<<"Yes\n";
	}
	else
		cout<<"No\n";
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