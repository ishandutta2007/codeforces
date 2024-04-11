#include <cctype>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <array>
#include <random>
#include <regex>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;

constexpr unsigned P[4] = {1000003, 1000033, 4000037, 1000003};
constexpr unsigned Q[4] = {1'000'000'007, 1'000'000'009, 1'000'000'007, 999'999'937};

unsigned modpow[4][200005];

struct hashval
{
    unsigned u[4];
    int len;

    hashval operator+(const hashval &rhs) const
    {
        hashval ret;

        for (int i = 0; i < 4; i++)
        {
            ret.u[i] = (u[i] * 1ull * modpow[i][rhs.len] % Q[i] + rhs.u[i]) % Q[i];
        }
        ret.len = len + rhs.len;
        return ret;
    }
};

hashval tree[524288];

void setseg(int t, int ch)
{
    t += 262144;
    tree[t] = {{ch, ch, ch, ch}, 1};

    while (t >>= 1)
    {
        tree[t] = tree[t<<1] + tree[t<<1|1];
    }
}

hashval query(int a, int b)
{
    hashval L{}, R{};
    a += 262144; b += 262144;
    while (a <= b)
    {
        if (a & 1)
        {
            L = L + tree[a];
            a++;
        }
        if (!(b & 1))
        {
            R = tree[b] + R;
            b--;
        }
        a >>= 1; b >>= 1;
    }
    return L + R;
}

char str[200005];
vector<pair<int, int>> queries[200005];
pair<hashval, hashval> ans[200005];
int last[256];

int main()
{
    for (int i = 0; i < 4; i++)
    {
        modpow[i][0] = 1;
        for (int j = 1; j <= 200000; j++) modpow[i][j] = modpow[i][j-1] * 1ull * P[i] % Q[i];
    }

    int n, m;
    scanf("%d%d%s",&n,&m,str);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        queries[a - 1].emplace_back(i, c);
        queries[b - 1].emplace_back(i, -c);
    }

    for (int i = 0; i < 256; i++) last[i] = -1;

    for (int i = n - 1; i >= 0; i--)
    {
        int old = last[str[i]];

        if (old != -1)
        {
            setseg(old, old - i + 1);
        }

        last[str[i]] = i;

        setseg(i, n + 1);

        for (auto &e : queries[i])
        {
            if (e.second < 0)
            {
                ans[e.first].second = query(i, i - e.second - 1);
            }
            else
            {
                ans[e.first].first = query(i, i + e.second - 1);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (memcmp(&ans[i].first, &ans[i].second, sizeof(hashval)) == 0) printf("YES\n");
        else printf("NO\n");
    }
}