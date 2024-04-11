
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
#define MOD 99991  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n,k;
int depth[MAXN];
int ed[MAXN];
vector<int> g[MAXN];
int cnt[MAXN];
int leafcnt=0;
bool isleaf[MAXN];
bool cmp(int x,int y)
{
	return cnt[ed[x]]<cnt[ed[y]];
}

void dfs(int pos,int f)
{
	if (f)
		g[pos].erase(find(g[pos].begin(), g[pos].end(), f));
	for (auto p:g[pos])
		dfs(p,pos);
	sort(g[pos].begin(), g[pos].end(),cmp);
	depth[pos]=depth[f]+1;
	if (g[pos].size()==0)
	{
		leafcnt++;
		isleaf[pos]=1;
		ed[pos]=pos;
	}
	else
		ed[pos]=ed[g[pos][g[pos].size()-1]];
	cnt[ed[pos]]++;
	//cout<<pos<<' '<<ed[pos]<<endl;
}

void init()
{
	
}

LL calc(int x)
{
	return (LL)(n-x)*x;
}

void work()
{
	cin>>n>>k;
	int x,y;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	vector<int> tmpv;
	for (int i=1;i<=n;i++)
		if (isleaf[i])
			tmpv.push_back(cnt[i]);
	sort(tmpv.begin(), tmpv.end());
	WRT(leafcnt);
	int bluecnt=0;
	for (int i=0;i<max(leafcnt-k,0);i++)
		bluecnt+=tmpv[i];
	WRT(bluecnt);
	if (k<=leafcnt)
	{
		LL ans=LLINF;
		//min((LL)(n-bluecnt-k)*(k-bluecnt),(LL)(n-leafcnt)*(k-(leafcnt-k)));
		for (int i=0;i<=bluecnt;i++)
			ans=min(ans,(LL)(n-k-i)*(k-i));
		printf("%lld\n",ans);
		return;
	}
	LL ans=-LLINF;
	for (int i=leafcnt;i<=k;i++)
		ans=max(ans,calc(i));
	printf("%lld\n",ans);

}

signed main()
{
	init();
	int casenum=1;
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}