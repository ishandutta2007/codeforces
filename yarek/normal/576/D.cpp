#include <cstdio>
#include <bitset>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 150;
struct matrix
{
    bitset<N> bs[N];
    
    matrix()
    {
	for(int i = 0; i < N; i++)
	    bs[i].reset();
    }
    
    matrix operator*(matrix m)
    {
	bitset<N> ps[N];
	for(int i = 0; i < N; i++)
	    for(int j = 0; j < N; j++)
		ps[i][j] = m.bs[j][i];
	matrix res;
	for(int i = 0; i < N; i++)
	    for(int j = 0; j < N; j++)
		res.bs[i][j] = (bs[i] & ps[j]).any();
	return res;
    }
};

matrix pow(matrix a, int b)
{
    if(b == 1) return a;
    if(b & 1) return pow(a, b - 1) * a;
    return pow(a * a, b / 2);
}

pair<int, pair<int, int> > ed[150];
vector<int> g[150];
int dist[150];

int bfs(bitset<N> start, int n)
{
    queue<int> q;
    for(int i = 0; i < n; i++)
	if(start[i])
	{
	    dist[i] = 0;
	    q.push(i);
	}
	else dist[i] = -1;
    while(!q.empty())
    {
	int v = q.front();
	q.pop();
	for(int u: g[v])
	    if(dist[u] == -1)
	    {
		dist[u] = dist[v] + 1;
		q.push(u);
	    }
    }
    return dist[n-1];
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
	int a, b, d;
	scanf("%d %d %d", &a, &b, &d);
	a--; b--;
	ed[i] = make_pair(d, make_pair(a, b));
    }
    sort(ed, ed + m);
    matrix r, k;
    for(int i = 0; i < n; i++)
	r.bs[i][i] = 1;
    int prev = 0;
    for(int i = 0; i < m; i++)
    {
	if(prev != ed[i].first)
	{
	    r = r * pow(k, ed[i].first - prev);
	    prev = ed[i].first;
	}
	int a = ed[i].second.first, b = ed[i].second.second;
	k.bs[a][b] = true;
	g[a].push_back(b);
	int ans = bfs(r.bs[0], n);
	if(ans != -1)
	{
	    printf("%d\n", prev + ans);
	    return 0;
	}
    }
    puts("Impossible");
}