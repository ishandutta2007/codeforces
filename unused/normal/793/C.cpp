#include <bits/stdc++.h>
using namespace std;

int rx[100005], ry[100005], vx[100005], vy[100005];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

struct rational
{
    int up, down;
    rational(int u = 0, int d = 1) : up(u), down(d)
    {
        int g = gcd(abs(up), abs(down));
        up /= g; down /= g;
        if (down < 0)
        {
            down = -down; up = -up;
        }
    }

    bool operator<(const rational &rhs) const
    {
        return up * 1ll * rhs.down < rhs.up * 1ll * down;
    }

    bool operator==(const rational &rhs) const
    {
        return up * 1ll * rhs.down == rhs.up * 1ll * down;
    }
};

map<rational, int> events;
int now;

void make_event(int p, int v, int s, int e)
{
    if (v == 0)
    {
        if (p <= s || p >= e)
        {
            printf("-1\n");
            exit(0);
        }

        ++now;
        return;
    }

    rational zero(0, 1);

    if (v < 0)
    {
        rational r1(p - e, -v);
        events[max(r1, zero)]++;

        rational r2(p - s, -v);
        events[max(r2, zero)]--;
    }
    else
    {
        rational r1(s - p, v);
        events[max(r1, zero)]++;

        rational r2(e - p, v);
        events[max(r2, zero)]--;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d",&rx[i],&ry[i],&vx[i],&vy[i]);
    }

    for (int i = 0; i < n; i++)
    {
        make_event(rx[i], vx[i], x1, x2);
        make_event(ry[i], vy[i], y1, y2);
    }

    if (now == 2 * n)
    {
        printf("0\n");
        return 0;
    }

    for (auto &e : events)
    {
        now += e.second;
        if (now == 2 * n)
        {
            printf("%.15f\n", e.first.up / (double)e.first.down);
            return 0;
        }
    }

    printf("-1\n");
}