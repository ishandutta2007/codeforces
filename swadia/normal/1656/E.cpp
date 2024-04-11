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

vector<int> g[MAXN];
int n,x,y;
int a[MAXN];
int b[MAXN];
void dfs(int pos,int pa,int col)
{
	a[pos]=b[pos]=col;
	//cout<<pos<<' '<<col<<endl;
	if (pos==1)
		a[pos]=b[pos]=0;
	for (auto p:g[pos])
		if (p!=pa)
		{
			dfs(p,pos,-col);
			b[pos]-=a[p];
		}
}

void init()
{

}

void work()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		g[i].clear();
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0,1);
	//b[1]=2;
	for (int i=1;i<=n;i++)
		cout<<b[i]<<' ';
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