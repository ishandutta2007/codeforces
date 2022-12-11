#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 200001;
vector<int> g[N];
int k[N];
bool marked[N];
ll ans;

void dfs1(int v, int prev)
{
    k[v] = marked[v];
    for(int u: g[v])
	if(u != prev)
	{
	    dfs1(u, v);
	    k[v] += k[u];
	}
}

int centroid(int v, int prev, int total)
{
    for(int u: g[v])
	if(u != prev && k[u] * 2 > total)
	    return centroid(u, v, total);
    return v;
}

void dfs2(int v, int prev)
{
    static int d = 0;
    if(marked[v]) ans += d;
    d++;
    for(int u: g[v])
	if(u != prev) dfs2(u, v);
    d--;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < 2 * k; i++)
    {
	int u;
	scanf("%d", &u);
	marked[u] = true;
    }
    for(int i = 1; i < n; i++)
    {
	int a, b;
	scanf("%d %d", &a, &b);
	g[a].push_back(b);
	g[b].push_back(a);
    }
    dfs1(1, 0);
    int c = centroid(1, 0, ::k[1]);
//     printf("%d\n", c);
    dfs2(c, 0);
    printf("%lld\n", ans);
}