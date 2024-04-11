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

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int LOG = 60;
const int N = 512;
const int B = 64;
const int S = 8;

struct Item
{
    bool a[2][N][N];

    Item() : a() {}

    Item operator * (const Item &A) const
    {
        Item R = Item();

        ull b[N][S];
        ull c[N][S];

        for (int t = 0; t < 2; t++)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < S; j++)
                    b[i][j] = c[i][j] = 0;
                for (int j = 0; j < N; j++)
                    if (a[t][i][j])
                        b[i][j >> 6] |= ((ull)1 << (j % B));
                for (int j = 0; j < N; j++)
                    if (A.a[t ^ 1][j][i])
                        c[i][j >> 6] |= ((ull)1 << (j % B));
            }
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                {
                    R.a[t][i][j] = 0;
                    for (int k = 0; k < S; k++)
                        if (b[i][k] & c[j][k])
                            R.a[t][i][j] = 1;
                }
        }

        return R;
    }
};

Item a[LOG + 1];

void read()
{
    int n, m;
    scanf("%d%d", &n, &m);
    while(m--)
    {
        int v, u, t;
        scanf("%d%d%d", &v, &u, &t);
        v--;u--;
        a[0].a[t][v][u] = 1;
    }
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    read();

    for (int i = 0; i < LOG; i++)
        a[i + 1] = a[i] * a[i];

    int k = LOG;
    while(k >= 0)
    {
        bool ok = false;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                ok |= a[k].a[0][i][j];
        if (ok) break;
        k--;
    }


    if (k == LOG)
    {
        printf("-1\n");
        return 0;
    }
    if (k < 0)
    {
        printf("0\n");
        return 0;
    }

    ll ans = 1LL << k;

    Item A = a[k];
    int t = 1;

    while(k > 0)
    {
        k--;
        Item D = a[k];
        if (!t)
        {
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    swap(D.a[0][i][j], D.a[1][i][j]);
        }
        Item C = A * D;
        bool ok = false;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                ok |= C.a[0][i][j];
        if (!ok) continue;
        A = C;
        t ^= 1;
        ans += 1LL << k;
    }

    printf("%lld\n", (ans > (ll)1e18 ? -1 : ans));

    return 0;
}