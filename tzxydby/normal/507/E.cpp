#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int d[N],s[N],p[N],out[2][N];
queue<int>q;
vector<int>ans,o;
vector<pair<int,int>>e[N];
int main()
{
	int n,m,x,y,z;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		e[x].push_back(make_pair(y,z));
		e[y].push_back(make_pair(x,z));
	}
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	p[1]=-1;
	q.push(1);
	while(!q.empty())
	{
		int v=q.front();
		q.pop();
		for(int i=0;i<e[v].size();i++)
		{
			int u=e[v][i].first,l=e[v][i].second;
			if((d[u]>d[v]+1)||(d[u]==d[v]+1&&s[u]<s[v]+l))
			{
				d[u]=d[v]+1;
				s[u]=s[v]+l;
				p[u]=v;
				q.push(u);
			}
		}
	}
	for(int i=n;p[i]!=-1;i=p[i])
		ans.push_back(i);
	ans.push_back(1);
	out[0][ans[0]]=ans[1];
	out[0][1]=ans[ans.size()-2];
	for(int i=1;i<ans.size()-1;i++)
	{
		out[0][ans[i]]=ans[i-1];
		out[1][ans[i]]=ans[i+1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<e[i].size();j++)
		{
			int x=i,y=e[i][j].first,z=e[i][j].second;
			if(x>y)
				continue;
			if(!z)
			{
				if(out[0][x]==y||out[1][x]==y)
				{
					o.push_back(x);
					o.push_back(y);
					o.push_back(1);
				}
			}
			else
			{
				if(out[0][x]!=y&&out[1][x]!=y)
				{
					o.push_back(x);
					o.push_back(y);
					o.push_back(0);
				}
			}
		}
	}
	printf("%d\n",o.size()/3);
	for(int i=0;i<o.size();i+=3)
		printf("%d %d %d\n",o[i],o[i+1],o[i+2]);
	return 0;
}