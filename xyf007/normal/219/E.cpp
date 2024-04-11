#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <set>
struct Segment
{
    int l, r, len, pos;
    Segment(int l = 0, int r = 0, int len = 0, int pos = 0) : l(l), r(r), len(len), pos(pos) {}
    bool operator<(const Segment &b) const
    {
        return len == b.len ? pos < b.pos : len > b.len;
    }
};
int n, m, l[200002], r[200002], pos[1000001];
std::set<Segment> s;
Segment MakeSegment(int l, int r)
{
    if (!l)
    {
        return Segment(0, r, r - 1, 1);
    }
    if (r == n + 1)
    {
        return Segment(l, n + 1, n - l, n);
    }
    int len = (r - l) >> 1;
    return Segment(l, r, len, l + len);
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m;
    s.emplace(0, n + 1, 1000000000, 1);
    for (int i = 1; i <= m; i++)
    {
        int op, x;
        std::cin >> op >> x;
        if (op == 1)
        {
            Segment t = *s.begin();
            s.erase(s.begin());
            std::cout << (pos[x] = r[t.l] = l[t.r] = t.pos) << '\n';
            l[t.pos] = t.l;
            r[t.pos] = t.r;
            s.emplace(MakeSegment(t.l, t.pos));
            s.emplace(MakeSegment(t.pos, t.r));
        }
        else
        {
            s.erase(MakeSegment(l[pos[x]], pos[x]));
            s.erase(MakeSegment(pos[x], r[pos[x]]));
            r[l[pos[x]]] = r[pos[x]];
            l[r[pos[x]]] = l[pos[x]];
            s.emplace(MakeSegment(l[pos[x]], r[pos[x]]));
            l[pos[x]] = r[pos[x]] = 0;
        }
    }
    return 0;
}