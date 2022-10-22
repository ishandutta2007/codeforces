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

vector<int> d[2];
int n;
int a[MAXN],b[MAXN];
void init()
{

}

void work()
{
	d[0].clear();
	d[1].clear();
	cin>>n;
	LL tot=0;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		tot+=b[i];
	}

	for (int i=1;i<=n;i++)
		d[a[i]].push_back(b[i]);
	sort(d[0].begin(), d[0].end(), greater<int>());
	sort(d[1].begin(), d[1].end(), greater<int>());
	LL ans1=0;
	LL ans2=0;
	for (int i=0;i<d[0].size() && i<d[1].size();i++)
		ans1+=d[0][i];
	for (int i=0;i<d[1].size() && i+1<d[0].size();i++)
		ans1+=d[1][i];
	for (int i=0;i<d[0].size() && i+1<d[1].size();i++)
		ans2+=d[0][i];
	for (int i=0;i<d[1].size() && i<d[0].size();i++)
		ans2+=d[1][i];
	cout<<tot+max(ans1,ans2)<<'\n';
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