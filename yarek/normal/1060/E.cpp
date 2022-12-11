#include <bits/stdc++.h>
using namespace std;

const int N = 200001;
typedef long long ll;

vector<int> g[N];
ll sum[N];
ll ch[N][2];
ll ans;

void dfs(int v, int prev)
{
    ch[v][0] = 1;
    vector<pair<ll, int>> vec;
    for(int u: g[v])
        if(u != prev)
        {
            dfs(u, v);
            vec.push_back({ sum[u], ch[u][0] + ch[u][1] });
            sum[v] += sum[u] + ch[u][0] + ch[u][1];
            ans += (ll)ch[u][0] * ch[v][0] + (ll)ch[u][1] * ch[v][1];
            ch[v][0] += ch[u][1];
            ch[v][1] += ch[u][0];
        }
    for(auto p: vec)
        ans += (ch[v][0] + ch[v][1] - p.second) * (p.first + p.second);
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    printf("%lld\n", ans / 2);
}