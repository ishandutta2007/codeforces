#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

struct edge
{
    int a, b, color;
    edge(int A = 0, int B = 0, int Color = 0) : a(A), b(B), color(Color) { }
};

struct request
{
    bool ans;
    edge e;
    int nr, next;
    
    request(edge E = edge(), int Nr = 0, int Next = 0) : e(E), nr(Nr), next(Next) { }
};

const int TREE = 1 << 19;
vector<edge> edges[TREE << 1];
request req[TREE];
int offset;

int pa, pb;
edge pe;
void insert(int v, int a, int b)
{
    if(a >= pb || b <= pa) return;
    if(a >= pa && b <= pb)
	edges[v].push_back(pe);
    else
    {
	insert(v * 2, a, (a + b) / 2);
	insert(v * 2 + 1, (a + b) / 2, b);
    }
}

void insert(int a, int b, edge e)
{
    pa = a;
    pb = b;
    pe = e;
    insert(1, 0, offset);
}

const int N = 500001, K = 51;
int r[K][N];
int c[K][N];
int s[K][N];

int col[N];
int ea[N];
int eb[N];

pair<int, int> Find(int k, int color)
{
    int side = 0;
    while(r[color][k] != k)
    {
	side ^= s[color][k];
	k = r[color][k];
    }
    return make_pair(k, side);
}

pair<int, int> Union(int a, int b, int color)
{
    auto pa = Find(a, color), pb = Find(b, color);
    if(pa.first != pb.first)
    {
	if(c[color][pa.first] > c[color][pb.first])
	    swap(pa, pb);
	s[color][pa.first] = pa.second ^ pb.second ^ 1;
	c[color][pb.first] += c[color][pa.first];
	r[color][pa.first] = pb.first;
    }
    return make_pair(pa.first, pb.first);
}

void algo(int v, int q)
{
    static stack<edge> s;
    int ssize = s.size();
    for(auto e: edges[v])
    {
	auto p = Union(e.a, e.b, e.color);
	s.push(edge(p.first, p.second, e.color));
    }
    if(v >= offset)
    {
	int k = v - offset;
	if(k < q)
	{
	    if(Find(req[k].e.a, req[k].e.color) == Find(req[k].e.b, req[k].e.color))
		req[k].ans = false;
	    else
	    {
		req[k].ans = true;
		col[req[k].nr] = req[k].e.color;
	    }
	    insert(k + 1, req[k].next, edge(req[k].e.a, req[k].e.b, col[req[k].nr]));
	}
    }
    else
    {
	algo(v * 2, q);
	algo(v * 2 + 1, q);
    }
    while(s.size() > ssize)
    {
	auto e = s.top();
	s.pop();
	if(e.a == e.b) continue;
	c[e.color][e.b] -= c[e.color][e.a];
	r[e.color][e.a] = e.a;
    }
}

vector<pair<int, int>> re[N];

int main()
{
    int n, m, q, k;
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for(int i = 0; i <= k; i++)
	for(int j = 1; j <= n; j++)
	{
	    r[i][j] = j;
	    c[i][j] = 1;
	}
    offset = 1;
    while(offset < q) offset *= 2;
    for(int i = 1; i <= m; i++)
	scanf("%d %d", ea + i, eb + i);
    for(int i = 0; i < q; i++)
    {
	int e, c;
	scanf("%d %d", &e, &c);
	re[e].emplace_back(i, c);
    }
    for(int i = 1; i <= m; i++)
	for(int j = 0; j < re[i].size(); j++)
	    req[re[i][j].first] = request(edge(ea[i], eb[i], re[i][j].second), i, j + 1 == re[i].size() ? q : re[i][j+1].first);
    algo(1, q);
    for(int i = 0; i < q; i++)
	puts(req[i].ans ? "YES" : "NO");
}