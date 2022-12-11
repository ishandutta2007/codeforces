#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],E=1;
inline void add_edge(int x,int y)
{
	End[++E]=y,Next[E]=Last[x],Last[x]=E;
	End[++E]=x,Next[E]=Last[y],Last[y]=E;
}
int a[max_n],b[max_n],ans;
multiset<int> S[max_n];
bool mark[max_n];
void dfs(int x,int fa)
{
	b[x]=b[fa]^a[x];
//	fprintf(stderr,"x=%d b[x]=%d\n",x,b[x]);
	S[x].insert(b[x]);
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			dfs(y,x);
			if(!mark[x])
			{
				if(S[x].size()<S[y].size())
					swap(S[x],S[y]);
				for(int v:S[y])
				{
					if(S[x].find(v^a[x])!=S[x].end())
					{
						mark[x]=true;
						break;
					}
				}
				if(mark[x])
					continue;
				for(int v:S[y])
					S[x].insert(v);
				S[y].clear();
			}
		}
	}
	if(mark[x])
	{
		S[x].clear();
		++ans;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1;i<=n-1;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}