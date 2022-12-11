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

const int N = 200500;

char buf[N];
string a, b;

string read_token()
{
    scanf("%s", buf);
    return string(buf);
}

struct Tuple
{
    int a, b, c, d;

    Tuple(): a(), b(), c(), d() {}

    Tuple(int _a, int _b, int _c, int _d):
        a(_a), b(_b), c(_c), d(_d) {}

    bool operator < (const Tuple & o) const
    {
        if (a == o.a)
        {
            if (b == o.b)
            {
                if (c == o.c)
                    return d < o.d;
                return c < o.c;
            }
            return b < o.b;
        }
        return a < o.a;
    }
};

map<Tuple, bool> cache;

bool solve(int x, int y, int l, int r)
{
    bool win = false;

    if (a.substr(x, y - x + 1) == b.substr(l, r - l + 1))
        win = true;
    else if ((x + y) % 2 == 0 || (l + r) % 2 == 0)
        win = false;
    else
    {
        int m = (x + y) / 2;
        int p = (l + r) / 2;
        win = (solve(x, m, p + 1, r) && solve(m + 1, y, l, p)) ||
            (solve(x, m, l, p) && solve(m + 1, y, p + 1, r));
    }

    return win;
}

void solve()
{
    a = read_token();
    b = read_token();
    puts(solve(0, (int)a.length() - 1, 0, (int)b.length() - 1) ? "YES" : "NO");
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("time = %.3lf\n", (double) clock() / CLOCKS_PER_SEC);

    return 0;
}