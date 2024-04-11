#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define all(x) begin(x), end(x)

const int maxn = 100005;
const int inf = 1e9;

int a[maxn];
int kvbefore[maxn], kvtotal[maxn];
int m, k;

int main()
{
    int NT;
    scanf("%d", &NT);
    for (int T = 0; T < NT; T++)
    {
        scanf("%d%d", &m, &k);
        m--;
        for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
        for (int i = 0; i <= k; i++)
        {
            kvbefore[i] = 0;
            kvtotal[i] = 0;
        }
        bool was = false;
        for (int i = 0; i < m; i++)
        {
            int t, r;
            scanf("%d%d", &t, &r);
            if (r == 1 && !was)
            {
                was = true;
            }
            if (!was) kvbefore[t]++;
            kvtotal[t]++;
        }
        int minget = inf;
        for (int i = 1; i <= k; i++) if (kvtotal[i] == kvbefore[i])
        {
            minget = min(minget, a[i] - kvtotal[i]);
        }
        for (int i = 1; i <= k; i++)
        {
            bool can = false;
            if (kvtotal[i] == kvbefore[i] && kvbefore[i] + kvbefore[0] >= a[i]) can = true;
            if (minget <= kvbefore[0] && kvtotal[i] + kvtotal[0] - minget >= a[i]) can = true;
            printf("%c", (can ? 'Y' : 'N'));
        }
        printf("\n");
    }
    return 0;
}