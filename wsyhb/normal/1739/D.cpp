#include<bits/stdc++.h>
using namespace std;
int n,k;
const int max_n=2e5+5;
namespace BIT
{
	int val[max_n];
	inline void add(int k,int v)
	{
		for(int i=k;i<=n;i+=i&(-i))
			val[i]+=v;
	}
	inline int query(int k)
	{
		int res=0;
		for(int i=k;i>0;i-=i&(-i))
			res+=val[i];
		return res;
	}
	inline void clear()
	{
		for(int i=1;i<=n;++i)
			val[i]=0;
	}
}
int p[max_n];
vector<int> son[max_n];
int dep[max_n],dfn[max_n][2],Time,f[max_n][20];
void dfs(int x)
{
	dfn[x][0]=++Time;
	for(int i=1;i<20;++i)
		f[x][i]=f[f[x][i-1]][i-1];
	for(int y:son[x])
	{
		dep[y]=dep[x]+1;
		f[y][0]=x;
		dfs(y);
	}
	dfn[x][1]=Time;
}
inline int jump(int x,int d)
{
	for(int i=0;i<20;++i)
	{
		if(d>>i&1)
			x=f[x][i];
	}
	return x;
}
inline bool check(int d)
{
	typedef pair<int,int> P;
	priority_queue<P> Q;
	for(int i=1;i<=n;++i)
		Q.push(P(dep[i],i));
	int cnt=0;
	while(!Q.empty())
	{
		int x=Q.top().second;
		Q.pop();
		if(dep[x]<=d||BIT::query(dfn[x][0])>0)
			continue;
		++cnt;
		int anc=jump(x,d-1);
		BIT::add(dfn[anc][0],1);
		BIT::add(dfn[anc][1]+1,-1);
	}
	BIT::clear();
	return cnt<=k;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=2;i<=n;++i)
		{
			scanf("%d",p+i);
			son[p[i]].push_back(i);
		}
		dfs(1);
		int L=1,R=n-2,res=n-1;
		while(L<=R)
		{
			int mid=(L+R)>>1;
			if(check(mid))
				res=mid,R=mid-1;
			else
				L=mid+1;
		}
		printf("%d\n",res);
		for(int i=1;i<=n;++i)
			son[i].clear();
		Time=0;
	}
	return 0;
}