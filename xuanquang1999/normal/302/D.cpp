#include <bits/stdc++.h>
using namespace std;
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define point pair<int, int>
point p[100];
const int maxC = 1000000000;
int n, k, a[100], c[100][100], d[100];
bool visited[100];

int ll_dist(point p1, point p2)
{
    return abs(p1.first-p2.first)+abs(p1.second-p2.second);
}

int main()
{
    scanf("%d%d", &n, &k);
    fto(i, 1, n-2) scanf("%d", &a[i]);
    fto(i, 0, n-1) scanf("%d%d", &p[i].first, &p[i].second);

    fto(u, 0, n-1)
        fto(v, 0, n-1)
            if (u == v) c[u][v] = maxC;
            else c[u][v] = ll_dist(p[u], p[v])*k - a[v];

    fto(i, 0, n-1) d[i] = maxC;
    d[0] = 0;
    while (true)
    {
        int minC = maxC, u = 0;
        fto(v, 0, n-1)
            if (!visited[v] && d[v] < minC)
            {
                minC = d[v];
                u = v;
            }
        if (u == n-1) break;
        visited[u] = true;
        fto(v, 0, n-1)
            if (!visited[v]) d[v] = min(d[v], d[u]+c[u][v]);
    }

    printf("%d", d[n-1]);
}