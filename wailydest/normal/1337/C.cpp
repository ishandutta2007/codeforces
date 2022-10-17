#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<vector<int> > g;
vector<int> s, d;
multimap<int, int> co;

void dfs(int v, int prev = -1)
{
    s[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != prev) {
            d[g[v][i]] = d[v] + 1;
            dfs(g[v][i], v);
            s[v] += s[g[v][i]];
        }
    }
    co.insert(make_pair(s[v] - d[v] - 1, v));
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    g.resize(n);
    s.resize(n);
    d.resize(n);
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &a, &b);
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    d[0] = 0;
    dfs(0);
    long long ans = 0;
    map<int, int>::iterator t;
    while (k--) {
        t = co.begin();
        ans -= (long long)t->first;
        co.erase(t);
    }
    printf("%lld\n", ans);
    return 0;
}