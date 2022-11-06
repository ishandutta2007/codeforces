#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
vector<int>e[200010];
int d[200010];
int sz[200010];
int ct[200010];
bool ok[200010];
int sum = 0;
bool del[200010]; 

void dfs(int x,int fa)
{
	ok[x] = true;
	sz[x] = 1;
	ct[x] = 0;
	for (auto t:e[x])
	if (t != fa)
	{
		dfs(t,x);
		sz[x] += sz[t];
		ct[x] += (sz[t] % 2 == 0);
	}
	ok[x] &= (sz[x]%2==1);
	if (x != 1) ct[x] += (sz[x]%2==1);
}

queue<int>q;

int main()
{
	scanf("%d",&N);
	
	for (int i=1;i<=N;i++)
	{
		int p;
		scanf("%d",&p);
		if (p)
		{	
			e[p].push_back(i);
			e[i].push_back(p);
			d[i]++;
			d[p]++;
		}
	}
	if (N % 2 == 0) 
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	dfs(1,0);
	for (int i=1;i<=N;i++)if (ct[i] == 0)q.push(i),del[i] = true;
	while(!q.empty())
	{
		int now = q.front();
		printf("%d\n",now);
		q.pop();
		for (auto t:e[now])
		if (!del[t] && --ct[t]==0)
		{
			del[t] = true;
			q.push(t);
		}
	}
}