#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

struct Rule
{
    int a, b;
    string sign;

    Rule() : a(), b(), sign() {}

    void scan()
    {
        cin >> a >> sign >> b;
    }

    bool isGood(int x, int y)
    {
        if (sign == "=") return x == y;
        if (sign == "<") return x < y;
        if (sign == "<=") return x <= y;
        if (sign == ">=") return x >= y;
        if (sign == ">") return x > y;
        throw;
    }
};

const int N = 103;
Rule R[N];
int n, m;
ll dp[N][N];

int getVal(int x, int p1, int p2, int l, int r)
{
    if (x == p1 || x == p2) return 0;
    if (x <= l || x > r) return -1;
    return 1;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
        R[i].scan();
    dp[0][0] = 1;
    for (int i = 0; i < n - 1; i++)
        for (int l = 0; l <= 2 * i; l++)
        {
            if (dp[i][l] == 0) continue;
            int r = 2 * i - l;
            r = 2 * n - r;

            bool ok = true;
            for (int j = 0; ok && j < m; j++)
            {
                int x = getVal(R[j].a, l + 1, l + 2, l, r);
                int y = getVal(R[j].b, l + 1, l + 2, l, r);
//              printf("! %d %d %d : %d %d\n", i, l, j, x, y);
                if (x * y != 0) continue;
                ok &= R[j].isGood(x, y);
            }
            if (ok)
                dp[i + 1][l + 2] += dp[i][l];

            ok = true;
            for (int j = 0; ok && j < m; j++)
            {
                int x = getVal(R[j].a, l + 1, r, l, r);
                int y = getVal(R[j].b, l + 1, r, l, r);
//              printf("!! %d %d %d : %d %d\n", i, l, j, x, y);
                if (x * y != 0) continue;
                ok &= R[j].isGood(x, y);
            }
            if (ok)
                dp[i + 1][l + 1] += dp[i][l];

            ok = true;
            for (int j = 0; ok && j < m; j++)
            {
                int x = getVal(R[j].a, r, r - 1, l, r);
                int y = getVal(R[j].b, r, r - 1, l, r);
//              printf("!!! %d %d %d : %d %d\n", i, l, j, x, y);
                if (x * y != 0) continue;
                ok &= R[j].isGood(x, y);
            }
            if (ok)
                dp[i + 1][l] += dp[i][l];

        }
    ll ans = 0;
    for (int l = 0; l <= 2 * (n - 1); l++)
    {
        int r = l + 2;
        bool ok = true;
        for (int i = 0; ok && i < m; i++)
        {
            int x = getVal(R[i].a, l + 1, l + 2, l, r);
            int y = getVal(R[i].b, l + 1, l + 2, l, r);
            if (x * y != 0) continue;
            ok &= R[i].isGood(x, y);
        }
        if (ok)
            ans += dp[n - 1][l];
    }
    cout << ans << endl;

    return 0;
}