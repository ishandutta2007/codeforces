#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100007];
int sz[100007];
int par[100007];
bool cen[100007] = {false};
char rang[100007];
void dfs(int x, int y)
{
    sz[x] = 1;
    for (int i : adj[x])
    {
        if (i != y && !cen[i])
        {
            par[i] = x;
            dfs(i, x);
            sz[x] += sz[i];
        }
    }
}
void medis(int u, char x)
{
    par[u] = u;
    dfs(u, u);
    int mini = sz[u];
    int c = u;
    queue<int>A;
    A.push(u);
    while (!A.empty())
    {
        int a = A.front();
        A.pop();
        int s = 0;
        for (int i : adj[a])
        {
            if (par[a] != i && !cen[i])
            {
                s = max(s, sz[i]);
                A.push(i);
            }
        }
        s = max(s, sz[u] - sz[a]);
        if (s <= mini)
        {
            mini = s;
            c = a;
        }
    }
    rang[c] = x;
    cen[c] = true;
    for (int i : adj[c])
    {
        if (!cen[i])
            medis(i, x + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N;
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    medis(1, 'A');
    for (int i = 1; i <= N; i++)
        cout << rang[i] << " ";
}