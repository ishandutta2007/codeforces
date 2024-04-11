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

const int N = 400400;
int n, m, k;
int sz;
vector<int> g[N];
int ans[N];
bool used[N];

void dfs(int v)
{
    used[v] = 1;
    ans[sz++] = v;
    for (int u : g[v])
    {
        if (used[u]) continue;
        dfs(u);
        ans[sz++] = v;
    }
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    while(m--)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        v--;u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(0);

    int p = 0;
    for (int i = 0; i < k; i++)
    {
        int q = (sz / k) + (int)(i < (sz % k));
        printf("%d ", q);
        for (int j = 0; j < q; j++)
            printf("%d ", ans[p + j] + 1);
        printf("\n");
        p += q;
    }

    return 0;
}