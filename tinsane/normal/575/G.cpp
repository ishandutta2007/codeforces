#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

struct Edge
{
    int to, len;
    Edge() {}
    Edge(int _to, int _len) : to(_to), len(_len) {}
};

const int N = 1e5 + 10;
int n, m;
int anc[N];
int dist[N], groups[N], dist2[N];
int used[N];
vector<Edge> edges[N];
int wave[N];
int wsi;
int first, last;

void solve()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[a].emplace_back(b, c);
        edges[b].emplace_back(a, c);
    }
    wave[0] = n - 1;
    wsi = 1;
    used[n - 1] = 1;
    for(int i = 0; i < wsi; ++i)
    {
        int w = wave[i];
        for(auto e : edges[w])
        {
            if (e.len != 0 || used[e.to])
                continue;
            used[e.to] = 1;
            dist2[e.to] = dist2[w] + 1;
            anc[e.to] = w;
            wave[wsi++] = e.to;
        }
    }
    while(!used[0])
    {
        first = last;
        last = wsi;
        for(int i = first; i < last; ++i)
        {
            int w = wave[i];
            for(auto e : edges[w])
            {
                if (used[e.to] == used[w] + 1)
                {
                    int d = groups[w] * 10 + e.len;
                    if (d < dist[e.to])
                    {
                        dist[e.to] = d;
                        dist2[e.to] = dist2[w];
                        anc[e.to] = w;
                    }
                    continue;
                }
                else if (used[e.to])
                    continue;
                used[e.to] = used[w] + 1;
                dist[e.to] = groups[w] * 10 + e.len;
                dist2[e.to] = dist2[w];
                anc[e.to] = w;
                wave[wsi++] = e.to;
            }
        }
        sort(wave + last, wave + wsi, [&](int a, int b) {return dist[a] == dist[b] ? dist2[a] < dist2[b] : dist[a] < dist[b];});
        int now = 0;
        groups[wave[last]] = now;
        for(int i = last + 1; i < wsi; ++i)
        {
            int w = wave[i];
            int pw = wave[i - 1];
            if (dist[w] != dist[pw])
                ++now;
            groups[w] = now;
        }
    }
    int now = 0;
    vector<int> cities;
    string way;
    if (used[now] == 1)
        way = "0";
    for(; used[now] != 1; now = anc[now])
    {
        cities.push_back(now);
        for(auto e : edges[anc[now]])
            if (e.to == now)
                way += '0' + e.len;
    }
    reverse(way.begin(), way.end());
    for(; now != n - 1; now = anc[now])
        cities.push_back(now);
    cities.push_back(n - 1);
    printf("%s\n", way.c_str());
    printf("%d\n", (int)cities.size());
    for(auto c : cities)
        printf("%d ", c);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

    return 0;
}