#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N;
vector<int>e[1000010];
int fa[1000010];
LL a[1000010];
int size[1000010];
bool vis[1000010];
int p[1000010];

int find(int x)
{
	return x == fa[x]? x : fa[x] = find(fa[x]); 
}

bool cmp(int x,int y)
{
	return a[x] < a[y];
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%lld",&a[i]);
	for (int i=1;i<=N;i++)fa[i] = i;
	for (int i=1;i<N;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	LL ans = 0;
	
	for (int i=1;i<=N;i++)p[i] = i;
	sort(p + 1, p + N + 1, cmp);
	
	for (int i=1;i<=N;i++)
	{
		fa[i] = i;
		size[i] = 1;
		vis[i] = false;
	}
	int cnt = 0;
	for (int i=1;i<=N;i++)
	{
		int x = p[i];
		for (auto y:e[x])
		if (vis[y])
		{
			int tmp = find(y);
			ans += 1LL * size[x] * size[tmp] * a[x];
			//cnt += size[x] * size[tmp];
			size[x] += size[tmp]; 
			fa[tmp] = x;
		}
		vis[x] = true;
	}
	
	for (int i=1;i<=N;i++)
	{
		fa[i] = i;
		size[i] = 1;
		vis[i] = false;
	}
	for (int i=N;i>=1;i--)
	{
		int x = p[i];
		for (auto y:e[x])
		if (vis[y])
		{
			int tmp = find(y);
			ans -= 1LL * size[x] * size[tmp] * a[x];
			//cnt += size[x] * size[tmp];
			size[x] += size[tmp]; 
			fa[tmp] = x;
		}
		vis[x] = true;
	}
	printf("%lld\n",ans);
}