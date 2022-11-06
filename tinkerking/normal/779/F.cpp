#include <bits/stdc++.h>
#define MAXN 300010
using namespace std;

typedef long long LL;

int ch[MAXN][26];
int ans[MAXN],maxdep = 0;
int N;

int merge(vector<int>now)
{
	//for (int i=0;i<now.size();i++)printf("%d ",now[i]);puts("");
	int res = now.size()-1;
	vector<int>next;
	for (int i=0;i<26;i++)
	{
		next.clear();
		for (int j=0;j<now.size();j++)
		if (ch[now[j]][i]) next.push_back(ch[now[j]][i]);
		if (next.size()<=1) continue;
		res+=merge(next);
	}
	return res;
}

void dfs(int x,int dep)
{
	vector<int>now;
	now.clear();
	maxdep = max(maxdep,dep);
	for (int i=0;i<26;i++)
	{
		if (!ch[x][i]) continue;
		now.push_back(ch[x][i]);
	}
	//printf("Merge %d\n",x);
	int res = merge(now)+1;
	ans[dep]+=res;
	//printf("%d %d\n",x,res);
	for (int i=0;i<26;i++)
	{
		if (ch[x][i]) dfs(ch[x][i],dep+1);
	}
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<N;i++)	
	{
		int u,v;
		char s[5];
		scanf("%d%d",&u,&v);
		scanf("%s",s);
		ch[u][s[0]-'a'] = v;
	}
	memset(ans,0,sizeof(ans));
	dfs(1,1);
	int maxres = 0,mp;
	for (int i=1;i<=maxdep;i++)
	if (maxres<ans[i])
	{
		maxres = ans[i];
		mp = i;
	}
	printf("%d\n%d\n",N-maxres,mp);
}