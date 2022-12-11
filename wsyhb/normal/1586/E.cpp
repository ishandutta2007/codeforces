#include<bits/stdc++.h>
using namespace std;
const int max_n=3e5+5;
vector<int> edge[max_n];
int dep[max_n],sz[max_n],son[max_n],fath[max_n];
bool vis[max_n];
void dfs1(int x,int fa)
{
	vis[x]=true;
	dep[x]=dep[fa]+1;
	sz[x]=1;
	fath[x]=fa;
	for(int i=0;i<int(edge[x].size());++i)
	{
		int y=edge[x][i];
		if(!vis[y])
		{
			dfs1(y,x);
			sz[x]+=sz[y];
			if(sz[y]>sz[son[x]])
				son[x]=y;
		}
	}
}
int top[max_n];
void dfs2(int x,int top_now)
{
	top[x]=top_now;
	if(son[x])
	{
		dfs2(son[x],top_now);
		for(int i=0;i<int(edge[x].size());++i)
		{
			int y=edge[x][i];
			if(fath[y]==x&&y!=son[x])
				dfs2(y,y);
		}
	}
}
inline int get_LCA(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
			swap(x,y);
		x=fath[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
int val[max_n],ans;
void dfs(int x)
{
	int cnt=0;
	for(int i=0;i<int(edge[x].size());++i)
	{
		int y=edge[x][i];
		if(fath[y]==x)
		{
			dfs(y);
			val[x]^=val[y];
			cnt+=val[y];
		}
	}
	if(val[x])
		cnt=max(cnt-1,0);
	ans+=(cnt+1)>>1;
}
const int max_q=3e5+5;
int a[max_q],b[max_q];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs1(1,0);
	dfs2(1,1);
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d",a+i,b+i);
		val[a[i]]^=1,val[b[i]]^=1;
	}
	dfs(1);
	if(!ans)
	{
		puts("YES");
		for(int i=1;i<=q;++i)
		{
			queue<int> Q;
			int p=get_LCA(a[i],b[i]);
			int x=a[i];
			while(x!=p)
			{
				Q.push(x);
				x=fath[x];
			}
			stack<int> st;
			x=b[i];
			while(x!=fath[p])
			{
				st.push(x);
				x=fath[x];
			}
			printf("%d\n",(int)Q.size()+(int)st.size());
			while(Q.size())
			{
				printf("%d ",Q.front());
				Q.pop();
			}
			while(st.size())
			{
				printf("%d ",st.top());
				st.pop();
			}
			putchar('\n');
		}
	}
	else
	{
		puts("NO");
		printf("%d\n",ans);
	}
	return 0;
}