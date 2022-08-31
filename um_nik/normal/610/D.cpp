#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;

struct Point
{
    int type;
    ll x;

    Point() : type(), x() {}
    Point (int _type, ll _x) : type(_type), x(_x) {}

    bool operator < (const Point &p) const
    {
        if (x != p.x) return x < p.x;
        return type < p.type;
    }
};

struct Event
{
    int type;
    int x;
    int y1, y2;

    Event() : type(), x(), y1(), y2() {}
    Event(int _type, int _x, int _y1, int _y2) : type(_type), x(_x), y1(_y1), y2(_y2) {}

    bool operator < (const Event &e) const
    {
        if (x != e.x) return x < e.x;
        return type < e.type;
    }
};

struct Node
{
    int l, r;
    int val;

    Node() : l(), r(), val() {}
    Node(int _l, int _r) : l(_l), r(_r), val(0) {}
};

const int N = 1 << 19;
ll ans;
map<ll, vector<Point>> forX, forY;
vector<ll> allX, allY;
vector<Event> ev;
Node tree[2 * N];

void buildTree()
{
    for (int i = 0; i < N; i++)
        tree[N + i] = Node(i, i + 1);
    for (int i = N - 1; i > 0; i--)
        tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
    return;
}
void add(int v, int d)
{
    v += N;
    tree[v].val += d;
    while(v > 1)
    {
        v >>= 1;
        tree[v].val += d;
    }
    return;
}
ll getSum(int v, int l, int r)
{
    if (l <= tree[v].l && tree[v].r <= r)
        return tree[v].val;
    if (l >= tree[v].r || tree[v].l >= r)
        return 0;
    return getSum(2 * v, l, r) + getSum(2 * v + 1, l, r);
}

void read()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        ll x1, y1, x2, y2;
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        if (x1 == x2)
        {
            y2++;
            forX[x1].push_back(Point(-1, y1));
            forX[x1].push_back(Point(1, y2));
        }
        else if (y1 == y2)
        {
            x2++;
            forY[y1].push_back(Point(-1, x1));
            forY[y1].push_back(Point(1, x2));
        }
        else throw;
    }
    return;
}

void normalize()
{
    for (auto it : forX)
    {
        ll X = it.first;
//      printf("%lld\n", X);
        vector<Point> a = it.second;
        sort(a.begin(), a.end());
        vector<Point> b = vector<Point>();
        int bal = 0;
        ll lastX = 0;
        for (Point P : a)
        {
            if (P.type == -1)
            {
                if (bal == 0)
                    lastX = P.x;
                bal++;
            }
            else
            {
                bal--;
                if (bal == 0)
                {
                    ans += P.x - lastX;
                    b.push_back(Point(-1, lastX));
                    b.push_back(Point(1, P.x));
                }
            }
        }
        forX[X] = b;
    }

    for (auto it : forY)
    {
        ll Y = it.first;
        vector<Point> a = it.second;
        sort(a.begin(), a.end());
        vector<Point> b = vector<Point>();
        int bal = 0;
        ll lastX = 0;
        for (Point P : a)
        {
            if (P.type == -1)
            {
                if (bal == 0)
                    lastX = P.x;
                bal++;
            }
            else
            {
                bal--;
                if (bal == 0)
                {
                    ans += P.x - lastX;
                    b.push_back(Point(-1, lastX));
                    b.push_back(Point(1, P.x));
                }
            }
        }
        forY[Y] = b;
    }

    for (auto it : forX)
    {
        allX.push_back(it.first);
        vector<Point> a = it.second;
        for (Point P : a)
            allY.push_back(P.x);
    }
    for (auto it : forY)
    {
        allY.push_back(it.first);
        vector<Point> a = it.second;
        for (Point P : a)
            allX.push_back(P.x);
    }
    sort(allX.begin(), allX.end());
    allX.resize(unique(allX.begin(), allX.end()) - allX.begin());
    sort(allY.begin(), allY.end());
    allY.resize(unique(allY.begin(), allY.end()) - allY.begin());

    for (auto it : forX)
    {
        int x = lower_bound(allX.begin(), allX.end(), it.first) - allX.begin();
        vector<Point> a = it.second;
        for (int i = 0; i < (int)a.size(); i += 2)
        {
            int y1 = lower_bound(allY.begin(), allY.end(), a[i].x) - allY.begin();
            int y2 = lower_bound(allY.begin(), allY.end(), a[i + 1].x) - allY.begin();
            ev.push_back(Event(1, x, y1, y2));
        }
    }
    for (auto it : forY)
    {
        int y = lower_bound(allY.begin(), allY.end(), it.first) - allY.begin();
        vector<Point> a = it.second;
        for (int i = 0; i < (int)a.size(); i++)
        {
            int x = lower_bound(allX.begin(), allX.end(), a[i].x) - allX.begin();
            ev.push_back(Event((a[i].type == -1 ? -1 : 0), x, y, y));
        }
    }
    sort(ev.begin(), ev.end());

    return;
}

void solve()
{
    normalize();
    buildTree();
    for (Event e : ev)
    {
        if (e.type == -1)
            add(e.y1, 1);
        else if (e.type == 0)
            add(e.y1, -1);
        else
            ans -= getSum(1, e.y1, e.y2);
    }
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    read();
    solve();
    printf("%lld\n", ans);

    return 0;
}