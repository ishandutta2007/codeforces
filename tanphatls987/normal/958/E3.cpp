#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 2e4 + 2;

struct TPoint { int x, y, col; } g[N];
bool ccw(TPoint a, TPoint b, TPoint c) { return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0; }
bool cw(TPoint a, TPoint b, TPoint c) { return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0; }
bool ccw(int a, int b, int c) { return ccw(g[a], g[b], g[c]); }
bool cw(int a, int b, int c) { return cw(g[a], g[b], g[c]); }

int n, mat[N];

void ConvexHull(const vector<short> &a, vector<short> &b)
{
    vector<short> up(1, a[0]), lo(1, a[0]);
    for (int i = 1; i < a.size(); ++i)
    {
        if (i == a.size() - 1 || cw(a[0], a[i], a.back()))
        {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up.back(), a[i])) up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(a[0], a[i], a.back()))
        {
            while (lo.size() >= 2 && !ccw(lo[lo.size() - 2], lo.back(), a[i])) lo.pop_back();
            lo.push_back(a[i]);
        }
    }
    b = vector<short>(up.begin(), up.end());
    reverse(lo.begin(), lo.end());
    b.insert(b.end(), lo.begin() + 1, lo.end() - 1);
}

void Solve(vector<short> &a)
{
    if (a.empty()) return;
    vector<short> b;
    ConvexHull(a, b);
    bool found = false;
    for (size_t i = 0; i < b.size(); ++i)
    {
        int cur = b[i], nex = b[(i + 1) % b.size()];
        if (g[cur].col != g[nex].col && !mat[cur] && !mat[nex])
        {
            mat[cur] = nex + 1;
            mat[nex] = cur + 1;
            found = true;
        }
    }

    b.clear();
    if (found)
    {
        for (auto p: a)
            if (!mat[p]) b.push_back(p);
        a.clear();
        Solve(b);
    }
    else
    {
        int sum = 0;
        do
        {
            sum += g[a.back()].col;
            b.push_back(a.back());
            a.pop_back();
        } while (sum != 0);
        reverse(b.begin(), b.end());            // ensure that b is sorted by x
        Solve(b);
        b.clear();
        Solve(a);
    }
}

int main()
{
    scanf("%d", &n);
    vector<short> a;
    for (int i = 0; i < n * 2; ++i)     // spaceships then bases
    {
        int x, y, col = (i < n ? 1 : -1);
        scanf("%d %d", &x, &y);
        g[i] = {x, y, col};
        a.push_back(i);
    }
    sort(a.begin(), a.end(), [](int p, int q) { return g[p].x < g[q].x; });
    Solve(a);
    for (int i = 0; i < n; ++i)         // print base that attach to spaceship
        printf("%d\n", mat[i] - n);
    return 0;
}