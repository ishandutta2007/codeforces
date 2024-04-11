#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector< pair<int, int> > g[100100];
bool used[100100];
int e[100100][3];
int p[100100];

bool dfs (int v)
{
    used[v] = 1;
    vector< pair<int, int> > s;
    for (int i = 0; i < g[v].size(); i++)
    {
        if (e[ g[v][i].second ][2] == 1)
            continue;
        int to = g[v][i].first;
        if (to == p[v])
            continue;
        if (!used[to])
        {
            p[to] = v;
            if (dfs(to))
            {
                s.push_back( g[v][i] );
            }
            else
            {
                e[ g[v][i].second ][2] = 1;
            }
        }
        else
        {
            s.push_back( g[v][i] );
        }
    }
    if (s.size() % 2 == 1)
    {
        for (int i = 0; i < s.size() / 2; i++)
        {
            e[ s[2 * i].second ][2] = 1;
            e[ s[2 * i + 1].second ][2] = 1;
            printf("%d %d %d\n", s[2 * i].first + 1, v + 1, s[2 * i + 1].first + 1);
        }
        e[ s[s.size() - 1].second ][2] = 1;
        printf("%d %d %d\n", s[s.size() - 1].first + 1, v + 1, p[v] + 1);
        return false;
    }
    else
    {
        for (int i = 0; i < s.size() / 2; i++)
        {
            e[ s[2 * i].second ][2] = 1;
            e[ s[2 * i + 1].second ][2] = 1;
            printf("%d %d %d\n", s[2 * i].first + 1, v + 1, s[2 * i + 1].first + 1);
        }
        return true;
    }
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    if (m % 2 == 1)
    {
        printf("No solution\n");
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &e[i][0], &e[i][1]);
        e[i][0]--;
        e[i][1]--;
        g[e[i][0]].push_back( make_pair( e[i][1], i ) );
        g[e[i][1]].push_back( make_pair( e[i][0], i ) );
    }
    p[0] = -1;
    dfs(0);

    return 0;
}