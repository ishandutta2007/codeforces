#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Edge
{
    int idx;
    int w;
    int f;

    Edge() : idx(), w(), f() {}

    void scan(int _idx)
    {
        idx = _idx;
        scanf("%d%d", &w, &f);
    }

    bool operator < (const Edge &e) const
    {
        if (w != e.w) return w < e.w;
        return f > e.f;
    }
};

const int N = 200100;
int n, m;
Edge e[N];
int a[N][2];

void Fail()
{
    printf("-1\n");
    exit(0);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        e[i].scan(i);
    sort(e, e + m);
    int k = 0;
    int v = 2, u = 0;

    for (int i = 0; i < m; i++)
    {
        if (e[i].f)
        {
            a[e[i].idx][0] = k;
            k++;
            a[e[i].idx][1] = k;
        }
        else
        {
            if (v > k)
                Fail();
            a[e[i].idx][0] = u;
            a[e[i].idx][1] = v;
            u++;
            if (u + 1 == v)
            {
                v++;
                u = 0;
            }
        }
    }
    for (int i = 0; i < m; i++)
        printf("%d %d\n", a[i][0] + 1, a[i][1] + 1);

    return 0;
}