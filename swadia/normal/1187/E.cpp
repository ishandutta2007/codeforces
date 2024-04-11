#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl; 
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#define LINK(i,graph,pos) for (REG int i=graph.head[pos];i;i=graph.next[i])

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;


class GRAPH 
{
	public:
		int to[MAXM],next[MAXM];
		int head[MAXN];
		int cnt;
		
	GRAPH()
	{
		cnt=1;
	} 
	
	void add(int x,int y)
	{
		next[cnt]=head[x];
		to[cnt]=y;
		head[x]=cnt++;
	}
};

GRAPH g;
int n;
LL dp[MAXN];
LL s[MAXN];
LL son[MAXN];
LL mx;
LL dfs1(int pos,int pa)
{
	son[pos]=1;
	LINK(i,g,pos)
		if (g.to[i]!=pa)
		{
			dp[pos]+=dfs1(g.to[i],pos);
			son[pos]+=son[g.to[i]];
		}
	dp[pos]+=son[pos];
	return dp[pos];
}

LL dfs2(int pos,int pa)
{
	s[pos]=s[pa]+dp[pa]-dp[pos]-son[pa]+n-son[pos];
	if (pos==1)
		s[1]=0;
	mx=max(mx,s[pos]+dp[pos]+n-son[pos]);
	LINK(i,g,pos)
		if (g.to[i]!=pa)
		{
			dfs2(g.to[i],pos);
		}
}
int main()
{
	cin>>n;
	int x,y;
	RPT(i,0,n-1)
	{
		cin>>x>>y;
		g.add(x,y);
		g.add(y,x);
	}
	dfs1(1,1);
	dfs2(1,1);
	//RPT(i,1,n+1)
	//	cout<<i<<' '<<dp[i]<<' '<<s[i]<<endl;
	cout<<mx;
	return ~~(0^_^0);
}