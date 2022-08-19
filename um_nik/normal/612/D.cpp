#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct Event
{
    int type;
    int x;

    Event() : type(), x() {}
    Event(int _type, int _x) : type(_type), x(_x) {}

    bool operator < (const Event &e) const
    {
        if (x != e.x) return x < e.x;
        return type < e.type;
    }
};

const int INF = (int)1e9 + 100;
const int N = (int)2e6 + 300;
int n;
int ans[N][2];
Event ev[N];
int ansSz = 0;
int k;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        ev[2 * i] = Event(0, l);
        ev[2 * i + 1] = Event(1, r);
    }
    n *= 2;
    sort(ev, ev + n);
    int L = INF;
    for (int i = 0; i < n; i++)
    {
        if (ev[i].type == 0)
        {
            k--;
            if (k == 0)
                L = ev[i].x;
        }
        else
        {
            k++;
            if (k == 1)
            {
                ans[ansSz][0] = L;
                ans[ansSz][1] = ev[i].x;
                ansSz++;
                L = INF;
            }
        }
    }
    printf("%d\n", ansSz);
    for (int i = 0; i < ansSz; i++)
        printf("%d %d\n", ans[i][0], ans[i][1]);

    return 0;
}