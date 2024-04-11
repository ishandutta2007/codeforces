#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100001, inf = 1000000001;
int rep[N];
int size[N];
int odd;

int Find(int k)
{
    return k == rep[k] ? k : Find(rep[k]);
}

pair<int, int> Union(int a, int b)
{
    a = Find(a); b = Find(b);
    if(a == b) return make_pair(0, 0);
    if(size[a] > size[b]) swap(a, b);
    rep[a] = b;
    if(size[a] % 2 && size[b] % 2) odd -= 2;
    size[b] += size[a];
    return make_pair(a, b);
}

void Disconnect(int a, int b)
{
    size[b] -= size[a];
    rep[a] = a;
    if(size[a] % 2 && size[b] % 2)
	odd += 2;
}

struct edge
{
    int a, b, cost, nr;
    edge(int A = 0, int B = 0, int Cost = 0, int Nr = 0) : a(A), b(B), nr(Nr), cost(Cost) { }
};

bool operator<(edge a, edge b)
{
    return a.cost < b.cost;
}

const int M = 300000;
int ans[M];
edge chrono[M];
edge sorted[M];

void algo(int left, int right, int min, int max)
{
    if(left >= right) return;
    int center = (left + right) / 2;
    vector<pair<int, int>> edges;
    for(int i = left; i <= center; i++)
	if(chrono[i].cost <= sorted[min].cost)
	    edges.push_back(Union(chrono[i].a, chrono[i].b));
    int k = edges.size();
    ans[center] = inf;
    for(int i = min; i <= max; i++)
    {
	if(sorted[i].nr > center) 
	    continue;
	edges.push_back(Union(sorted[i].a, sorted[i].b));
	if(odd == 0)
	{
	    ans[center] = i;
	    break;
	}
    }
    while(edges.size() > k)
    {
	Disconnect(edges.back().first, edges.back().second);
	edges.pop_back();
    }
    algo(center + 1, right, min, max);
    while(edges.size())
    {
	Disconnect(edges.back().first, edges.back().second);
	edges.pop_back();
    }
    if(ans[center] != inf)
    {
	for(int i = min; i < ans[center]; i++)
	    if(sorted[i].nr < left)
		edges.push_back(Union(sorted[i].a, sorted[i].b));
	algo(left, center, ans[center], max);
	while(edges.size())
	{
	    Disconnect(edges.back().first, edges.back().second);
	    edges.pop_back();
	}
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
	rep[i] = i;
	size[i] = 1;
    }
    odd = n;
    for(int i = 0; i < m; i++)
    {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	chrono[i] = sorted[i] = edge(a, b, c, i);
	ans[i] = inf;
    }
    sort(sorted, sorted + m);
    algo(0, m, 0, m - 1);
    for(int i = 0; i < m; i++)
	printf("%d\n", ans[i] == inf ? -1 : sorted[ans[i]].cost);
}