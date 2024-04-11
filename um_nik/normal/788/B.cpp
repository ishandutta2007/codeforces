#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = (int)1e6 + 10;
int n, m;
vector<int> g[N];
int loops[N];
bool used[N];

void dfs(int v)
{
    used[v] = 1;
    for (int u : g[v])
        if (!used[u])
            dfs(u);
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        v--;u--;
        if (v == u)
            loops[v]++;
        else
        {
            g[v].push_back(u);
            g[u].push_back(v);
        }
    }
    int v = 0;
    while(loops[v] == 0 && g[v].empty()) v++;
    dfs(v);
    for (int i = 0; i < n; i++)
    {
        if (!used[i] && (loops[i] > 0 || !g[i].empty()))
        {
            printf("0\n");
            return 0;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll x = (ll)g[i].size();
        ans += x * (x - 1) / 2;
    }
    ll allLoops = 0;
    for (int i = 0; i < n; i++)
        allLoops += loops[i];
    ans += allLoops * (allLoops - 1) / 2 + allLoops * (m - allLoops);
    printf("%lld\n", ans);

    return 0;
}