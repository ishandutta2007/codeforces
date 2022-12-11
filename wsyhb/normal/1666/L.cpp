#include<bits/stdc++.h>
using namespace std;
int n,m,s;
const int max_n=2e5+5;
const int max_m=2e5+5;
int End[max_m],Last[max_n],Next[max_m],E;
inline void add_edge(int x,int y)
{
	End[++E]=y;
	Next[E]=Last[x];
	Last[x]=E;
}
int vis[max_n],f1,f2,goal;
bool flag_over;
void dfs(int x,int from)
{
//	fprintf(stderr,"x=%d from=%d\n",x,from);
	if(x==s)
		return;
	if(vis[x])
	{
		if(vis[x]!=from)
		{
			f1=vis[x],f2=from,goal=x;
			flag_over=true;
		}
		return;
	}
	vis[x]=from; 
	for(int i=Last[x];i&&!flag_over;i=Next[i])
		dfs(End[i],from);
}
int pre[max_n];
void dfs(int x)
{
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=s&&!pre[y])
		{
			pre[y]=x;
			dfs(y);
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v); 
	}
	for(int i=Last[s];i&&!flag_over;i=Next[i])
	{
		int y=End[i];
		dfs(y,y);
	}
	if(flag_over)
	{
		puts("Possible");
		pre[f1]=s;
		dfs(f1);
		vector<int> ans1(1,goal);
		while(ans1.back()!=s)
			ans1.push_back(pre[ans1.back()]);
		reverse(ans1.begin(),ans1.end());
		memset(pre,0,sizeof(pre));
		pre[f2]=s;
		dfs(f2);
		vector<int> ans2(1,goal);
		while(ans2.back()!=s)
			ans2.push_back(pre[ans2.back()]);
		reverse(ans2.begin(),ans2.end());
		assert(int(ans1.size())>=2&&ans1[0]==s&&ans1[1]==f1);
		assert(int(ans2.size())>=2&&ans2[0]==s&&ans2[1]==f2);
		vector<bool> vis(n+1);
		for(int i=1;i<int(ans1.size());++i)
			vis[ans1[i]]=true;
		for(int i=1;i<int(ans2.size());++i)
		{
			if(vis[ans2[i]])
			{
				int x=ans2[i];
				while(ans1.back()!=x)
					ans1.pop_back();
				while(ans2.back()!=x)
					ans2.pop_back();
				break;
			}
		}
		printf("%d\n",int(ans1.size()));
		for(int i=0;i<int(ans1.size());++i)
			printf("%d%c",ans1[i],i+1<int(ans1.size())?' ':'\n');
		printf("%d\n",int(ans2.size()));
		for(int i=0;i<int(ans2.size());++i)
			printf("%d%c",ans2[i],i+1<int(ans2.size())?' ':'\n');
	}
	else
		puts("Impossible");
	return 0;
}