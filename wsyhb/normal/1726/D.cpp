#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
vector<int> edge[max_n];
typedef pair<int,int> P;
vector<P> special;
bool vis[max_n];
int fath[max_n],dep[max_n];
void dfs(int x,int fa)
{
	vis[x]=true;
	fath[x]=fa;
	dep[x]=dep[fa]+1; 
	for(int y:edge[x])
	{
		if(y!=fa)
		{
			if(!vis[y])
				dfs(y,x);
			else
			{
				if(x<y)
					special.push_back(P(x,y)); 
			}
		}
	}
}
const int max_m=2e5+10;
int u[max_m],v[max_m];
char ans[max_m];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i)
		{
			scanf("%d%d",u+i,v+i);
			if(u[i]>v[i])
				swap(u[i],v[i]);
			edge[u[i]].push_back(v[i]);
			edge[v[i]].push_back(u[i]);
		}
		dfs(1,0);
		assert((int)special.size()==m-(n-1));
		set<int> S;
		for(auto v:special)
			S.insert(v.first),S.insert(v.second);
		if(!S.empty()&&S.size()==special.size())
		{
			assert((int)S.size()==3);
			int a=special.back().first;
			int b=special.back().second;
			special.pop_back();
			if(dep[a]<dep[b])
				swap(a,b);
			int x=fath[a];
			assert(S.find(x)==S.end());
			if(a>x)
				swap(a,x);
			special.push_back(P(a,x));
		}
		for(int i=1;i<=m;++i)
			ans[i]='0';
		ans[m+1]='\0';
		for(auto now:special)
		{
			int x=now.first,y=now.second;
			for(int i=1;i<=m;++i)
			{
				if(u[i]==x&&v[i]==y)
				{
					ans[i]='1';
					break;
				}
			}
		}
		printf("%s\n",ans+1);
		for(int i=1;i<=n;++i)
		{
			edge[i].clear();
			vis[i]=false;
		}
		special.clear();
	}
	return 0;
}