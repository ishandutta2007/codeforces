#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair
#define X first
#define Y second

const int INF = (int)1e9;
const int N = 30;
int n;
int a[N][3];
map<pii, pii> mapchik;
int p[N];
int ansVal = -INF;
pii ans;

int main()
{
    scanf("%d", &n);
    p[0] = 1;
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] * 3;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
    int m = (n + 1) / 2;
    for (int mask = 0; mask < p[m]; mask++)
    {
        int b[3];
        b[0] = b[1] = b[2] = 0;
        int mm = mask;
        for (int i = 0; i < m; i++)
        {
            int x = mm % 3;
            mm /= 3;
            for (int j = 0; j < 3; j++)
                b[j] += a[i][j];
            b[x] -= a[i][x];
        }
        int val = b[0];
        for (int j = 0; j < 3; j++)
            b[j] -= val;
        pii key = mp(-b[1], -b[2]);
        if (mapchik.count(key) == 0)
            mapchik[key] = mp(val, mask);
        else
        {
            pii v = mapchik[key];
            if (val > v.X)
                mapchik[key] = mp(val, mask);
        }
    }
    for (int mask = 0; mask < p[n - m]; mask++)
    {
        int b[3];
        b[0] = b[1] = b[2] = 0;
        int mm = mask;
        for (int i = m; i < n; i++)
        {
            int x = mm % 3;
            mm /= 3;
            for (int j = 0; j < 3; j++)
                b[j] += a[i][j];
            b[x] -= a[i][x];
        }
        int val = b[0];
        for (int j = 0; j < 3; j++)
            b[j] -= val;
        pii key = mp(b[1], b[2]);
        if (mapchik.count(key) == 0)
            continue;
        else
        {
            pii v = mapchik[key];
            val += v.X;
            if (val > ansVal)
            {
                ansVal = val;
                ans = mp(v.Y, mask);
            }
        }
    }
    if (ansVal == -INF)
        printf("Impossible\n");
    else
    {
        int mm = ans.X;
        for (int i = 0; i < m; i++)
        {
            int x = mm % 3;
            mm /= 3;
            if (x == 0)
                printf("MW\n");
            else if (x == 1)
                printf("LW\n");
            else
                printf("LM\n");
        }
        mm = ans.Y;
        for (int i = m; i < n; i++)
        {
            int x = mm % 3;
            mm /= 3;
            if (x == 0)
                printf("MW\n");
            else if (x == 1)
                printf("LW\n");
            else
                printf("LM\n");
        }
    }

    return 0;
}