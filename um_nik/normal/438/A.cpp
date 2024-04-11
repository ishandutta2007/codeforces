#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> g[1010];
pair<int, int> v[1001];
int p[1010];
int ans = 0;
bool used[1010];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i + 1]);
        v[i].first = p[i + 1];
        v[i].second = i + 1;
    }
    sort(v, v + n);
    reverse(v, v + n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int u = v[i].second;
        used[u] = 1;
        for (int j = 0; j < g[u].size(); j++)
        {
            int to = g[u][j];
            if (!used[to])
                ans += p[to];
        }
    }
    printf("%d\n", ans);
//  cin >> n;
    return 0;
}