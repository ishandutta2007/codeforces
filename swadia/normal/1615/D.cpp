#include <bits/stdc++.h>

using namespace std;


#define Not(x) (-x-1)
#define True(x) (x>=0 ? 2*x+1:2*Not(x))
#define False(x) (x>=0 ? 2*x:2*Not(x)+1)
#define Flip(x) (x^1)

struct TwoSAT
{
	typedef pair<int,int> pii;
	vector<pii> record;
	vector<vector<int>> g;
	vector<int> col,dfn,low,vis;
	int n=0,tim=0,sccCnt=0;
	stack<int> stk;


	void setn(int _n)
	{
		n=2*_n;
	}

	void init()
	{
		if (n==0)
		{
			for (auto p:record)
			{
				n=max(n,p.first+1);
				n=max(n,p.second+1);
			}
			n=(n+1)/2*2;
		}
		g.resize(n);vis.resize(n);dfn.resize(n);low.resize(n);col.resize(n);
		for (auto p:record)
		{
			g[p.first].push_back(p.second);
		}
	}

	void tarjan(int u) 
	{
    	low[u] = dfn[u] = ++tim;
    	stk.push(u); vis[u] = true;
    	for (auto v : g[u]) 
        	if (!dfn[v]) 
        		tarjan(v), low[u] = min(low[u], low[v]);
        	else if (vis[v]) 
        		low[u] = min(low[u], dfn[v]);
    	if (low[u] == dfn[u]) 
    	{
      		++sccCnt;
       		do {
            	col[u] = sccCnt;
           		u = stk.top(); stk.pop(); vis[u] = false;
        	} while (low[u] != dfn[u]);
    	}
	}

	bool check()
	{
		init();
		for (int i = 0; i < n; ++i) 
			if (!dfn[i]) 
				tarjan(i);
		for (int i=0;i<n/2;i++)
			if (col[True(i)]==col[False(i)])
				return false;
		return true;
	}


	vector<int> build()
	{
		vector<int> ans;
		ans.resize(n/2);
		for (int i=0;i<n/2;i++)
			ans[i]=(col[True(i)]<col[False(i)]);
		return ans;
	}

	string trans(int x)
	{
		if (x&1)
			return "  "+to_string(x/2);
		else
			return "~ "+to_string(x/2);
	}

	void output()
	{
		for (auto p:record)
			cout<<trans(p.first)<<" -> "<<trans(p.second)<<endl;
	}

	void Add(int x,int y){record.push_back({x,y});}

	void AddTrue(int x){Add(False(x),True(x));}
	void AddFalse(int x){Add(True(x),False(x));}

	void AddAnd(int x,int y){AddTrue(x);AddTrue(y);}
	void AddOr(int x,int y){Add(False(x),True(y));Add(False(y),True(x));}
	void AddXor(int x,int y){Add(True(x),False(y));Add(False(y),True(x));
							 Add(True(y),False(x));Add(False(x),True(y));}

	void AddNotAnd(int x,int y){AddOr(Not(x),Not(y));}
	void AddNotOr(int x,int y){AddAnd(Not(x),Not(y));}
	void AddNotXor(int x,int y){AddXor(Not(x),y);}
	void AddIf(int x,int y){AddOr(Not(x),y);}

};



void init()
{
	
}
typedef pair<int,int> pii;

void work()
{
	vector<vector<pii>> g;
	int n,m,x,y,w;
	scanf("%d%d",&n,&m);
	TwoSAT tst;
	tst.setn(n+2);
	g.resize(n+1);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		g[x].push_back({y,w});
		//g[y].push_back(x);
		if (w>=0)
		{
			if (__builtin_popcount(w)%2)
				tst.AddXor(x,y);
			if (__builtin_popcount(w)%2==0)
				tst.AddNotXor(x,y);
		}
	}
	while (m--)
	{
		scanf("%d%d%d",&x,&y,&w);
		if (w)
			tst.AddXor(x,y);
		else
			tst.AddNotXor(x,y);
	}
	//tst.output();
	bool ok=tst.check();
	if (!ok)
		printf("NO\n");
	else
	{
		printf("YES\n");
		auto ans=tst.build();
		for (int i=1;i<=n;i++)
			for (auto p:g[i])
				if (p.second>=0)
					printf("%d %d %d\n",i,p.first,p.second);
				else
					printf("%d %d %d\n",i,p.first,ans[i]^ans[p.first]);
	}

}

signed main()
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
	return 0;
}