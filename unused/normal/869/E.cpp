#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <array>
#include <initializer_list>
#include <random>
#include <regex>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct segtree
{
    map<int, int> *dat[6600] {};

    map<int, int> &mp(int idx)
    {
        if (dat[idx] == nullptr) dat[idx] = new map<int, int>;
        return *dat[idx];
    }

    void add(int L, int R, int area, int id)
    {
        L += 4096;
        R += 4096;

        while (L <= R)
        {
            if (L&1) mp(L++).emplace(area, id);
            if (!(R&1)) mp(R--).emplace(area, id);
            L >>= 1; R >>= 1;
        }
    }
    
    void sub(int L, int R, int area)
    {
        L += 4096;
        R += 4096;

        while (L <= R)
        {
            if (L&1) mp(L++).erase(area);
            if (!(R&1)) mp(R--).erase(area);
            L >>= 1; R >>= 1;
        }
    }

    pair<int, int> get(int pos)
    {
        pair<int, int> ret(1e9, 0);

        for (pos += 4096; pos; pos >>= 1)
        {
            if (dat[pos] == nullptr || mp(pos).empty()) continue;
            if (ret.first > mp(pos).begin()->first)
                ret = *mp(pos).begin();
        }

        return ret;
    }
};

struct seg2d
{
    segtree seg[6600];

    void add(int L, int y1, int R, int y2, int area, int id)
    {
        L += 4096;
        R += 4096;

        while (L <= R)
        {
            if (L&1) seg[L++].add(y1, y2, area, id);
            if (!(R&1)) seg[R--].add(y1, y2, area, id);
            L >>= 1; R >>= 1;
        }
    }

    void sub(int L, int y1, int R, int y2, int area, int id)
    {
        L += 4096;
        R += 4096;

        while (L <= R)
        {
            if (L&1) seg[L++].sub(y1, y2, area);
            if (!(R&1)) seg[R--].sub(y1, y2, area);
            L >>= 1; R >>= 1;
        }
    }

    pair<int, int> get(int x1, int y1)
    {
        pair<int, int> ret(1e9, 0);

        for (x1 += 4096; x1; x1 >>= 1)
        {
            ret = min(ret, seg[x1].get(y1));
        }
        return ret;
    }
} seg;

int main()
{
    int n, m, q;
    scanf("%d%d%d",&n,&m,&q);

    for (int i = 1; i <= q; i++)
    {
        int a, b, c, d, e;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        if (a == 1) seg.add(b, c, d, e, (d - b + 1) * (e - c + 1), i);
        if (a == 2) seg.sub(b, c, d, e, (d - b + 1) * (e - c + 1), i);
        if (a == 3)
        {
            auto a1 = seg.get(b, c);
            auto a2 = seg.get(d, e);
            if (a1.second == a2.second) printf("Yes\n");
            else printf("No\n");
        }
    }
}