#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n, k, m, tmp;
int l, r;
ll p, c;
vector<int> g[100100];
int h[100100];
int a[100100];
bool u[100100];

void dfs(int v)
{
    u[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (!u[to])
        {
            h[to] = h[v] + 1;
            dfs(to);
        }
    }
    return;
}

int main()
{
    scanf("%d%d%I64d", &n, &k, &p);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0);
    for (int i = 1; i < n; i++)
        a[ h[i] ]++;

    for (; r < n; r++)
    {
        c += (ll)tmp;
        tmp += a[r];
        while (c > p)
        {
            if (a[l] > 0)
            {
                tmp--;
                a[l]--;
                c -= (ll)(r - l);
            }
            else
                l++;
        }
        m = max(m, tmp);
    }
    m = min(m, k);
    printf("%d\n", m);
//  cin >> n;
    return 0;
}