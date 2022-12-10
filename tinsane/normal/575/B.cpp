#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif
#define rank my_rank
const int P = (int) 1e9 + 7;

typedef pair<int, int> pii;

struct Edge
{
    int to, type;
    Edge() {}
    Edge(int _to, int _type) : to(_to), type(_type) {}
};

const int N = 1e5 + 10;
const int K = 1e6 + 10;
const int UP = 1;
const int DOWN = 2;
bool used[N];
vector< pii > queries[N];
int val[N], val1[N];
int n, k;
int dsu[N], rank[N], repr[N];
int ans;
int prog[K];
vector<Edge> edges[N];

int sum(int a, int b)
{
    a += b;
    if (a >= P)
        return a - P;
    return a;
}

int mul(int a, int b)
{
    return (long long) a * b % P;
}

int get(int x)
{
    return x == dsu[x] ? x : dsu[x] = get(dsu[x]);
}

void unite(int a, int b, int rep)
{
    a = get(a);
    b = get(b);
    if (a == b)
        return;
    if (rank[a] == rank[b])
        ++rank[a];
    if (rank[b] > rank[a])
        swap(a, b);
    dsu[b] = a;
    repr[a] = rep;
}

void tarjan(int v)
{
    used[v] = true;
    for(auto q : queries[v])
    {
        if (!used[q.first])
            continue;
        int lca = repr[get(q.first)];
        --val[lca];
        --val1[lca];
        //cout << v << ' ' << q.first << ' ' << lca << '\n';
        if (q.second == UP)
        {
            ++val[v];
            ++val1[q.first];
        }
        else
        {
            ++val1[v];
            ++val[q.first];
        }
    }
    for(auto e : edges[v])
    {
        if (used[e.to])
            continue;
        tarjan(e.to);
        unite(v, e.to, v);
    }
}

void calc(int v, int p)
{
    for(auto e : edges[v])
    {
        if (e.to == p)
            continue;
        calc(e.to, v);
        if (e.type == 1)
            ans = sum(ans, prog[val[e.to]]);
        val[v] += val[e.to];
    }
}

void solve()
{
    for(int i = 1; i < K; ++i)
        prog[i] = sum(1, mul(2, prog[i - 1]));
    scanf("%d", &n);
    for(int i = 1; i < n; ++i)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        --a, --b;
        edges[a].emplace_back(b, c);
        if (c == 0)
            edges[b].emplace_back(a, 0);
        else
            edges[b].emplace_back(a, 2);
    }
    scanf("%d", &k);
    int prev = 0;
    for(int i = 0; i < k; ++i)
    {
        int now;
        scanf("%d", &now);
        --now;
        queries[prev].emplace_back(now, UP);
        queries[now].emplace_back(prev, DOWN);
        prev = now;
    }
    for(int i = 0; i < n; ++i)
        dsu[i] = i, repr[i] = i;
    //cout << "------------\n";
    tarjan(0);
    //cout << "------------\n";
    calc(0, -1);
    copy(val1, val1 + N, val);
    for(int i = 0; i < n; ++i)
        for(auto& e : edges[i])
            if (e.type != 0)
                e.type = 3 - e.type;
    calc(0, -1);
    printf("%d", ans);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

    return 0;
}