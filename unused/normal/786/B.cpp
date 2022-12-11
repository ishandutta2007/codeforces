#include <bits/stdc++.h>
using namespace std;

constexpr int TSIZE = 131072;
int stree1[TSIZE * 2], stree2[TSIZE * 2];
vector<pair<int,int>> graph[TSIZE * 4];
long long weight[TSIZE * 4];

constexpr long long INF = 1e18;

int main()
{
    int n, q, s;
    scanf("%d%d%d",&n,&q,&s);
    --s;
    fill(weight,weight+TSIZE*4,INF);

    for (int i = TSIZE - 1; i >= 1; i--)
    {
        graph[i<<1].emplace_back(i, 0);
        graph[i<<1|1].emplace_back(i, 0);
        graph[i+TSIZE*2].emplace_back((i<<1)+TSIZE*2,0);
        graph[i+TSIZE*2].emplace_back((i<<1|1)+TSIZE*2,0);
    }
    for (int i = 0; i < n; i++)
    {
        graph[i + TSIZE * 3].emplace_back(i + TSIZE, 0);
    }

    for (int i = 0; i < q; i++)
    {
        int t;
        scanf("%d",&t);
        if (t == 1)
        {
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            a--; b--;
            graph[a+TSIZE].emplace_back(b+TSIZE,w);
        }
        else if (t == 2)
        {
            int v,l,r,w;
            scanf("%d%d%d%d",&v,&l,&r,&w);
            --v; --l; --r;
            l += TSIZE; r += TSIZE;
            while (l <= r)
            {
                if (l & 1) graph[v+TSIZE].emplace_back((l++)+TSIZE*2,w);
                if (!(r & 1)) graph[v+TSIZE].emplace_back((r--)+TSIZE*2,w);
                l>>=1; r>>=1;
            }
        }
        else
        {
            int v,l,r,w;
            scanf("%d%d%d%d",&v,&l,&r,&w);
            --v; --l; --r;
            l += TSIZE; r += TSIZE;
            while (l <= r)
            {
                if (l & 1) graph[l++].emplace_back(v+TSIZE*3,w);
                if (!(r & 1)) graph[r--].emplace_back(v+TSIZE*3,w);
                l>>=1; r>>=1;
            }
        }
    }

    priority_queue<pair<long long, int>> pq;
    weight[s+TSIZE] = 0;
    pq.emplace(0, s+TSIZE);
    while (pq.empty() == false)
    {
        long long w; int v;
        tie(w, v) = pq.top(); pq.pop();
        w = -w;
        if (weight[v] < w) continue;

        for (auto &e : graph[v])
        {
            if (weight[e.first] > w + e.second)
            {
                weight[e.first] = w + e.second;
                pq.emplace(-w - e.second, e.first);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%lld ", weight[i+TSIZE] == INF ? -1 : weight[i+TSIZE]);
    }
    printf("\n");
}