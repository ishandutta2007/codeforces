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

template <class DataType> 
class PrefixSum
{
public:
	vector<DataType> v;
	
	PrefixSum(int n)
	{
		v.resize(n+2);
	}
	
	DataType &operator[](int n) 
	{
		return v[n];
	}
	
	DataType query(int x1,int x2)
	{
		if (x1>x2)
			return 0;
		if (x1<=0)
			x1=1;
		if (x2>=v.size())
			x2=v.size()-1;
		return v[x2]-v[x1-1];
	}
	
	void work()
	{
		for (int i=1;i<v.size();i++)
			v[i]+=v[i-1];
	}
}; 

vector<int> g[MAXN];
int n,x,y;
int a[MAXN];
void work()
{
	vector<int> v;
	cin>>n;
	LL ans=0;
	for (int i=1;i<=n;i++)
	{
		g[i].clear();
		scanf("%d",&a[i]);
		ans+=a[i];
	}
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<g[i].size();j++)
		{
			v.push_back(a[i]);
			//WRT(a[i])
		}
	sort(v.begin(),v.end(),greater<int>());
	for (int i=1;i<n;i++)
	{
		printf("%lld ",ans);
		if (i==n-1)
			break;
		ans+=v[i-1];
	}
	putchar('\n');
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
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