#include <bits/stdc++.h>

using namespace std;

const int maxn = 50005;
const int maxm = 100005;
const int maxg = 1000006;

int x[maxm], y[maxm], id[maxg], gr[maxn];
vector <int> ke[maxn];
int n, m, g, thre;

bool ktr()
{
	int res = 0;
	for(int i=1; i<=m; i++)
	{
		if (id[gr[x[i]]] != id[gr[y[i]]])
			res++;
	}
	return (res >= thre);
}

int main()
{
	//freopen("test.inp", "r", stdin);
	srand(time(NULL));
	scanf("%d%d", &n, &m);
	thre = (m+1)/2;
	g = 0;
	for(int i=1; i<=m; i++)
		scanf("%d%d", &x[i], &y[i]);
	for(int i=1; i<=n; i++)
	{
		int t;
		scanf("%d", &t);
		for(int j=1; j<=t; j++)
		{
			int u;
			scanf("%d", &u);
			ke[i].push_back(u);
			g = max(g, u);
		}
	}
	
	while (1)
	{
		for(int i=1; i<=n; i++)
		{
			int k = rand()% (int)(ke[i].size());
			gr[i] = ke[i][k];
		}
		for(int i=1; i<=g; i++)
			id[i] = (rand()% 2) + 1;
		if (ktr())
			break;
	}
	
	for(int i=1; i<=n; i++)
		printf("%d ", gr[i]);
	printf("\n");
	for(int i=1; i<=g; i++)
		printf("%d ", id[i]);
	return 0;
}