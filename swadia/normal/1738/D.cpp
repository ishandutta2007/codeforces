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

int a[MAXN],b[MAXN];
int n,k;
int cnt[MAXN];
int hasend[MAXN];
vector<int> v[MAXN];
void init()
{

}

void output(int x)
{
	for (auto p:v[x])
		if (!hasend[p])
			cout<<p<<' ';
	for (auto p:v[x])
		if (hasend[p])
			cout<<p<<' ';
	for (auto p:v[x])
		if (!hasend[p])
			output(p);
	for (auto p:v[x])
		if (hasend[p])
			output(p);
}

void work()
{
	cin>>n;
	for (int i=0;i<=n+2;i++)
	{
		v[i].clear();
		cnt[i]=0;
		hasend[i]=0;
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		v[b[i]%(n+1)].push_back(i);
		hasend[b[i]]=1;
		cnt[b[i]]++;
	}
	//for (int i=1;i<=n;i++)
	//	cout<<i<<' '<<hasend[i]<<endl;
	int sum=cnt[n+1];
	for (k=n;k>=0;k--)
	{
		//cout<<k<<' '<<sum<<endl;
		if (sum==k)
			break;
		sum+=cnt[k];
	}
	cout<<k<<endl;
	output(0);
	cout<<endl;
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