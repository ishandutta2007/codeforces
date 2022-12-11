#include <bits/stdc++.h>
#define Maxn 400007
using namespace std;
int n;
int last[Maxn],pre[Maxn],other[Maxn],cnt=0;
bool f[Maxn][2];
int d1[Maxn],d2[Maxn],d3[Maxn];
vector<int> s[Maxn][4];
void insert(int u,int v)
{
	other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void dfs(int u,int fa)
{
	bool check=true;
	int tot=0;
	for (int q=last[u];q;q=pre[q])
	{
		int v=other[q];
		if (v!=fa)
		{
			dfs(v,u);
			++tot;
			if (f[v][1]==false&&f[v][0]==false)
			{
				f[u][0]=false;
				f[u][1]=false;
				check=false;
			} else if (f[v][1]&&f[v][0]) 
			{
				++d3[u];
				s[u][3].push_back(v);
			}
			else if (f[v][0]) 
			{
				++d1[u];
				s[u][1].push_back(v);
			}
			else 
			{
				++d2[u];
				s[u][2].push_back(v);
			}
		}
	}
	if (check)
	{
		if (d3[u]==0)
		{
			tot-=d2[u];
			if (tot%2==0) f[u][0]=true; else f[u][1]=true;
		} else f[u][0]=true,f[u][1]=true;
	}
}
void get_ans(int u,int type)
{
	if (d3[u]==0)
	{
		int t=(int)s[u][2].size();
		for (int i=0;i<t;i++)
			get_ans(s[u][2][i],1);
		printf("%d\n",u);
		t=(int)s[u][1].size();
		for (int i=0;i<t;i++)
			get_ans(s[u][1][i],0);
	} else
	{
		int now=d1[u];
		if (type==1) ++now;
		if (now%2==0)
		{
			int t=(int)s[u][3].size();
			for (int i=0;i<t;i++)
				get_ans(s[u][3][i],1);
			t=(int)s[u][2].size();
			for (int i=0;i<t;i++)
				get_ans(s[u][2][i],1);
			printf("%d\n",u);
			t=(int)s[u][1].size();
			for (int i=0;i<t;i++)
				get_ans(s[u][1][i],0);
		} else
		{
			get_ans(s[u][3][0],1);
			int t=(int)s[u][2].size();
			for (int i=0;i<t;i++)
				get_ans(s[u][2][i],1);
			printf("%d\n",u);
			t=(int)s[u][1].size();
			for (int i=0;i<t;i++)
				get_ans(s[u][1][i],0);
			t=(int)s[u][3].size();
			for (int i=1;i<t;i++)
				get_ans(s[u][3][i],0);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if (x!=0) insert(x,i),insert(i,x);
	}
	memset(f,false,sizeof(f));
	dfs(1,0);
	if (f[1][0])
	{
		printf("YES\n");
		if (f[1][0]) get_ans(1,0);
	} else printf("NO\n");
	return 0;
}