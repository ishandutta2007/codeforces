#include <iostream>
#include <vector>
using namespace std;
const int N = 200;
vector <int> g[N];
bool used[N];

void dfs(int v)
{
    used[v] = 1;
    for (int i = 0; i < (int)g[v].size(); i++)
        if (!used[g[v][i]])
            dfs(g[v][i]);
}

struct point
{
    int x, y;
    void scan()
    {
        scanf("%i%i", &x, &y);
    }
} p[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; i++)   
        p[i].scan();    

    for (int i = 0; i < n; i++)
    {
        for (int s = 0; s < n; s++)
        {
            if (i == s)
                continue;   
            if (p[i].x == p[s].x || p[i].y == p[s].y)
                g[i].push_back(s);
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            dfs(i);
            res++;
        }
    }
    printf("%i", res - 1);
    return 0;
}