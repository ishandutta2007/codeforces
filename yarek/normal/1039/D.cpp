#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
vector<int> g[N];
vector<int> t[N];
vector<int> vec;
int ans[N];
int path[N];

void dfs(int v, int prev)
{
    for(int u: g[v])
        if(u != prev)
        {
            t[v].push_back(u);
            dfs(u, v);
        }
    vec.push_back(v);
}

int algo(int k)
{
    int ans = 0;
    for(auto v: vec)
    {
        int b1 = 0, b2 = 0;
        for(auto u: t[v])
        {
            int p = path[u];
            if(p >= b1)
            {
                b2 = b1;
                b1 = p;
            }
            else if(p >= b2)
                b2 = p;
        }
        if(b1 + b2 + 1 >= k) 
        {
            ans++;
            path[v] = 0;
        }
        else path[v] = b1 + 1;
    }
    return ans;
}

void solve(int a, int b, int low, int up)
{
    if(a > b) return;
    if(low == up)
    {
        for(int i = a; i <= b; i++)
            ans[i] = low;
        return;
    }
    int c = (a + b) / 2;
    ans[c] = algo(c);
    solve(a, c - 1, ans[c], up);
    solve(c + 1, b, low, ans[c]);
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    solve(1, n, 0, n);
    for(int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
}