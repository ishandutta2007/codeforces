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
vector<vector<int> > c;
map<int,LL> mp;
map<int,int> cnt;
void init()
{

}

void work()
{
	cin>>n>>m;
	c.resize(n);
	for (auto &p:c)
	{
		p.resize(m);
		for (int &q:p)
			scanf("%d",&q);
	}
	LL ans=0;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			int col=c[i][j];
			ans+=1ll*i*cnt[col]-mp[col];
			mp[col]+=i;
			cnt[col]++;
			//WRT(ans)
		}
	}
	mp.clear();
	cnt.clear();
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			int col=c[j][i];
			ans+=1ll*i*cnt[col]-mp[col];
			mp[col]+=i;
			cnt[col]++;
		}
	}
	cout<<ans<<endl;

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