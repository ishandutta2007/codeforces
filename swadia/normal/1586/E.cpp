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

typedef pair<int,int> pii;
int n,m;
int degq[MAXN];
vector<int> g[MAXN];
int ans=0;
void init()
{

}
int visit[MAXN];
int depth[MAXN];
int pa[MAXN];
void dfs(int pos,int f)
{
	
	depth[pos]=depth[f]+1;
	pa[pos]=f;
	for (auto p:g[pos])
		if (p!=f && depth[p]==0)
			dfs(p,pos);
}

int xx[MAXN],yy[MAXN];
void work()
{
	cin>>n>>m;
	int x,y;
	for (int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int q;
	cin>>q;
	for (int i=0;i<q;i++)
	{
		scanf("%d%d",&x,&y);
		xx[i]=x,yy[i]=y;
		degq[x]++,degq[y]++;
	}
	for (int i=1;i<=n;i++)
		ans+=degq[i]%2;
	if (ans)
	{
		cout<<"NO"<<endl<<ans/2<<endl;
		return ;
	}
	dfs(1,1);
	MRK();
	cout<<"YES"<<endl;
	for (int i=0;i<q;i++)
	{
		bool rev=false;
		x=xx[i],y=yy[i];
		if (depth[x]<depth[y])
		{
			rev=true;
			swap(x,y);
		}
		vector<int> v1;
		stack<int> v2;
		while (depth[x]>depth[y])
		{
			v1.push_back(x);
			x=pa[x];
		}
		while (x!=y)
		{
			v1.push_back(x);
			v2.push(y);
			x=pa[x],y=pa[y];
		}
		v1.push_back(x);
		while (v2.size())
		{
			v1.push_back(v2.top());
			v2.pop();
		}
		if (rev)
			reverse(v1.begin(),v1.end());
		printf("%d\n",v1.size());
		for (auto p:v1)
			printf("%d ", p);
		putchar('\n');
	}
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