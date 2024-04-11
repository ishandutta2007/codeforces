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

#define MAXN 201000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-8

#define _ 0
using namespace std;
#define int LL
LL a[MAXN];
vector<int> factor;
int n,q;
typedef pair<LL,LL> pll;
int pri[MAXN];
vector<pll> mp[MAXN];

void init()
{
	for (int i=2;i<MAXN;i++)
		pri[i]=1;
	for (int i=2;i<MAXN;i++)
		if (pri[i])
		{
			mp[i].resize(MAXN/i);
			for (int j=2*i;j<MAXN;j+=i)
				pri[j]=0;
		}
}
set<pll,greater<pll> > st;
void work()
{
	st.clear();
	factor.clear();
	cin>>n>>q;
	for (int i=2;i<=n;i++)
		if (n%i==0 && pri[i])
			factor.push_back(i);
	for (int i=0;i<n;i++)
		cin>>a[i];
	for (auto p:factor)
	{
		//WRT(p)
		int f=n/p;
		for (int i=0;i<f;i++)
		{
			LL ans=0;
			for (int j=i;j<n;j+=f)
			{
				ans+=a[j];
			}
			//WRT(ans)
			st.insert({ans*f,(p<<32)+i});
			mp[p][i]={ans*f,(p<<32)+i};
		}
	}
	cout<<st.begin()->first<<'\n';
	while (q--)
	{
		int x,y;
		cin>>x>>y;
		x--;
		for (auto p:factor)
		{
			int f=n/p;
			int i=x%f;
			st.erase(mp[p][i]);
			auto tmp=mp[p][i];
			tmp.first+=(y-a[x])*f;
			//WRT(y)
			//WRT(a[x])
			//WRT(f)
			//WRT(tmp.first)
			mp[p][i]=tmp;
			st.insert(tmp);
		}
		a[x]=y;
		cout<<st.begin()->first<<'\n';
	}
}

signed main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	init();
	int casenum=1;
	cin>>casenum;
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}