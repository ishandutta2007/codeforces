#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = 5000 + 10;
const int INF = (int)1e9;

struct Query
{
    int t, a, b, c;
    Query () {}
    Query (int t, int a, int b, int c) : t(t), a(a), b(b), c(c) {}
} q[N];
int cntQ[N];

struct Item
{
    int t, val;
    Item () {}
    Item (int t, int val) : t(t), val(val) {}
} listQ[N][N];
int a[N];
int ans[N];

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int t;
        scanf("%d", &t);    
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        q[i] = Query(t, a, b, c);
        for (int s = a; s <= b; s++)
        {
            listQ[s][cntQ[s]++] = Item(t, c);
        }
    }

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        int minVal = INF;
        for (int s = 0; s < cntQ[i]; s++)
        {
            if (listQ[i][s].t == 1)
                sum += listQ[i][s].val;
            else
            {
                minVal = min(minVal, listQ[i][s].val - sum);
            }
        }
        a[i] = minVal;
        ans[i] = a[i];
    }

    for (int i = 0; i < m; i++)
    {
        if (q[i].t == 1)
        {
            for (int s = q[i].a; s <= q[i].b; s++)
                a[s] += q[i].c;
        }
        else
        {
            int curMax = -INF;
            for (int s = q[i].a; s <= q[i].b; s++)
                curMax = max(curMax, a[s]);
            if (curMax != q[i].c)
            {
                puts("NO");
                return 0;
            }
        }
    }

    puts("YES");
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);

    return 0;
}