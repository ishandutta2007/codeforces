#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int INF = (int)1e9 + 8;
int a[5];
int n;
int b[5], c[5];
int d[5];
int ans = INF;

int solve()
{
    for (int z = 0; z < (n << 7) + 3 ; z++)
    {
        bool good = true;
        for (int i = 0; i < 5; i++)
        {
            bool strict = b[i] == -1;
            int x = a[i];
            int q = n + z;
            int gr = d[i];
            int l = (gr == 5 ? 0 : (q >> (gr + 1))), r = q >> gr;
            while(gr != 5 && (l << (gr + 1)) <= q) l++;
            if (x > r || x + z < l) good = false;
            if (strict && x < l) return INF;
        }
        //printf("solve %lld %lld %d : %lld\n", x, y, gr, z);
        if (good) return z;
    }
    return INF;
}

int getScore(int gr, int minute)
{
    return gr * (500 - 2 * minute);
}

void brute(int p)
{
    if (p == 5)
    {
        int sc1 = 0, sc2 = 0;
        for (int i = 0; i < 5; i++)
        {
            if (b[i] != -1)
                sc1 += getScore(d[i] + 1, b[i]);
            if (c[i] != -1)
                sc2 += getScore(d[i] + 1, c[i]);
        }
        if (sc1 > sc2)
            ans = min(ans, solve());

        return;
    }

    for (int i = 0; i < 6; i++)
    {
        d[p] = i;
        brute(p + 1);
    }
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &b[i]);
        if (b[i] != -1)
            a[i]++;
    }
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &c[i]);
        if (c[i] != -1)
            a[i]++;
    }
    for (int k = 2; k < n; k++)
        for (int i = 0; i < 5; i++)
        {
            int x;
            scanf("%d", &x);
            if (x != -1)
                a[i]++;
        }

    brute(0);

    if (ans == INF)
        printf("-1\n");
    else
        printf("%d\n", ans);

    return 0;
}