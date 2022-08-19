#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
#define mp make_pair

const ll INF = (ll)1e18;
const int N = 400300;
int n, m, k;
ll s;
ll a[2][N];
ll b[N][2];
ll c[N];
pli u[N];

bool check(int d)
{
    ll x = INF, y = INF;
    for (int i = 0; i < d; i++)
    {
        x = min(x, a[0][i]);
        y = min(y, a[1][i]);
    }
    for (int i = 0; i < m; i++)
        c[i] = b[i][0] * (b[i][1] == 0 ? x : y);
//  sort(c, c + m);
    nth_element(c, c + k - 1, c + m);
    ll z = 0;
    for (int i = 0; i < k; i++)
        z += c[i];
    return z <= s;
}

void printAns(int d)
{
    int px = -1, py = -1;
    ll x = INF, y = INF;
    for (int i = 0; i < d; i++)
    {
        if (x > a[0][i])
        {
            px = i;
            x = a[0][i];
        }
        if (y > a[1][i])
        {
            py = i;
            y = a[1][i];
        }
    }
    for (int i = 0; i < m; i++)
        u[i] = mp(b[i][0] * (b[i][1] == 0 ? x : y), i);
    nth_element(u, u + k - 1, u + m);
    for (int i = 0; i < k; i++)
    {
        int f = u[i].second;
        printf("%d %d\n", f + 1, (b[f][1] == 0 ? px : py) + 1);
    }
    return;
}

int main()
{
    scanf("%d%d%d%lld", &n, &m, &k, &s);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[0][i]);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[1][i]);
    for (int i = 0; i < m; i++)
    {
        scanf("%lld%lld", &b[i][1], &b[i][0]);
        b[i][1]--;
    }
    int l = 0, r = n + 1;
    while(r - l > 1)
    {
        int d = (l + r) / 2;
        if (check(d))
            r = d;
        else
            l = d;
    }
    if (r == n + 1)
        r = -1;
    printf("%d\n", r);
    if (r != -1)
        printAns(r);

    return 0;
}