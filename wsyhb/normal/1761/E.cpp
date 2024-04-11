#include<bits/stdc++.h>
using namespace std;
int n;
const int max_n=4e3+5;
char s[max_n][max_n];
bool vis[max_n];
vector<int> now;
void dfs(int x)
{
	vis[x]=true;
	now.push_back(x);
	for(int y=1;y<=n;++y)
	{
		if(!vis[y]&&s[x][y]=='1')
			dfs(y);
	}
}
vector<int> node[max_n],id;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%s",s[i]+1);
		for(int i=1;i<=n;++i)
		{
			vis[i]=false;
			node[i].clear();
		}
		id.clear();
		int cnt=0,ans=-1;
		for(int i=1;i<=n;++i)
		{
			if(!vis[i])
			{
				dfs(i);
				node[i].swap(now);
				++cnt;
				id.push_back(i);
				if((int)node[i].size()==1)
					ans=i;
				if(~ans)
					continue;
				bool is_clique=true;
				for(int x:node[i])
				{
					for(int y:node[i])
					{
						if(x!=y&&s[x][y]=='0')
						{
							is_clique=false;
							break;
						}
					}
					if(!is_clique)
						break;
				}
				if(!is_clique)
					ans=i;
			}
		}
		if(cnt==1)
		{
			puts("0");
			continue;
		}
		if(~ans)
		{
			int mn=1e9,id=-1;
			for(int x:node[ans])
			{
				int deg=0;
				for(int y=1;y<=n;++y)
					deg+=s[x][y]^'0';
				if(deg<mn)
					mn=deg,id=x;
			}
			assert(~id);
			printf("1\n%d\n",id);
			continue;
		}
		if(cnt==2)
		{
			int x=id[0],y=id[1];
			if(node[x].size()>node[y].size())
				swap(x,y);
			printf("%d\n",(int)node[x].size());
			for(int v:node[x])
				printf("%d ",v);
			puts("");
		}
		else
			printf("2\n%d %d\n",node[id[0]][0],node[id[1]][0]);
	}
	return 0;
}