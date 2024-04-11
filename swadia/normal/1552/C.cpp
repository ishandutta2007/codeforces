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

int n,k;

void init()
{

}
typedef pair<int,int> pii;

void work()
{
	int x,y;
	cin>>n>>k;
	vector<int> v;
	vector<pii> t;
	v.resize(2*n+1); 
	for (int i=0;i<k;i++)
	{
		cin>>x>>y;
		if (x>y)
			swap(x,y);
		t.push_back({x,y});
		v[x]=v[y]=1;
	}
	int ans=0;
	for (int i=0;i<k;i++)
		for (int j=i+1;j<k;j++) 
		{
			auto p1=t[i];
			auto p2=t[j];
			if (p1>p2)
				swap(p1,p2);
			ans+=p1.second>p2.first && p1.second<p2.second;
		}
	for (auto p:t)
	{
		int cnt0=0,cnt1=0;
		x=p.first;
		y=p.second;
		for (int i=1;i<=2*n;i++)
		{
			if (v[i]==0 && (i<x || i>y))
				cnt0++;
			if (v[i]==0 && (i>x && i<y))
				cnt1++;
		}
		//cout<<p.first<<' '<<p.second<<' '<<cnt0<<' '<<cnt1<<endl;
		ans+=min(cnt0,cnt1);
	}
	cout<<(n-k)*(n-k-1)/2+ans<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
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