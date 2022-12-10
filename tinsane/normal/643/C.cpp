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

const int N = 200501;
const int K = 51;

struct Line
{
    double a, b;

    Line(): a(), b() {}

    Line(double _a, double _b): a(_a), b(_b) {}

    double get_inter(const Line &o) const
    {
        return (b - o.b) / (o.a - a);
    }

    double eval(double x) const
    {
        return a * x + b;
    }
};

int n, k;
double t[N];
double prefix[N], inv_prefix[N];
double prefix_sum2[N];
double dp[K][N];
Line stack[K][N];
int sz[K];
int ptr[K];

void add_line(int g, int i)
{
    Line line(-prefix[i - 1], dp[g][i] + prefix_sum2[i - 1]);
    while (sz[g] >= 2 && stack[g][sz[g] - 2].get_inter(line) <= stack[g][sz[g] - 2].get_inter(stack[g][sz[g] - 1]))
        sz[g]--;
    stack[g][sz[g]++] = line;
}

void solve()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%lf", &t[i]);

    for (int i = 0; i < n; i++)
    {
        prefix[i] = t[i];
        inv_prefix[i] = 1 / t[i];
    }
    for (int i = 1; i < n; i++)
    {
        prefix[i] += prefix[i - 1];
        inv_prefix[i] += inv_prefix[i - 1];
    }
    for (int i = 1; i < n; i++)
        prefix_sum2[i] = t[i] * inv_prefix[i - 1];
    for (int i = 1; i < n; i++)
        prefix_sum2[i] += prefix_sum2[i - 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = k; j >= 1; j--)
        {
            dp[j][i] = prefix[i - 1] * inv_prefix[i - 1] - prefix_sum2[i - 1];
            if (j > 1)
            {
                double x = inv_prefix[i - 1];
                ptr[j - 1] = min(ptr[j - 1], sz[j - 1] - 1);
                while (ptr[j - 1] + 1 < sz[j - 1] && stack[j - 1][ptr[j - 1]].get_inter(stack[j - 1][ptr[j - 1] + 1]) <= x)
                    ptr[j - 1]++;

                dp[j][i] += stack[j - 1][ptr[j - 1]].eval(x);
            }

            add_line(j, i);
        }
    }

    printf("%.10lf\n", dp[k][n]);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

    return 0;
}