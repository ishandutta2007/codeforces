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

int n;
void init()
{

}

void work()
{
	cin>>n;
	vector<int> v(n);
	for (int i=0;i<n;i++)
		scanf("%d",&v[i]);
	sort(v.begin(), v.end());
	for (auto p:v)
	{
		if (p!=1)
			continue;
		for (int i=1;i<n;i++)
			if (v[i]==v[i-1]+1)
			{
				cout<<"NO\n";
				return ;
			}
		break;
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