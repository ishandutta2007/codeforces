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

ll euclid(ll x, ll y, ll &k, ll &l)
{
    if (y == 0)
    {
        k = 1;
        l = 0;
        return x;
    }
    ll g = euclid(y, x % y, l, k);
    l -= k * (x / y);
    return g;
}

const int N = 200200;
const int M = 1000;
int m;
bool bad[N];
int d[M];
int id[N];
int k;
vector<int> a[M];
int dp[M], par[M];

void read()
{
    int n;
    scanf("%d%d", &n, &m);
    while(n--)
    {
        int x;
        scanf("%d", &x);
        bad[x] = 1;
    }
    k = 0;
    for (int x = 1; x <= m; x++)
    {
        id[x] = -1;
        if (m % x) continue;
        id[x] = k;
        d[k++] = x;
    }
    for (int x = 0; x < m; x++)
    {
        if (bad[x]) continue;
        ll p = 0, q = 0;
        int g = euclid(x, m, p, q);
        a[id[m / g]].push_back(x / g);
    }
    return;
}

ll getRev(ll x, ll mod)
{
    ll k, l;
    if (euclid(x, mod, k, l) != 1) throw;
    k %= mod;
    if (k < 0) k += mod;
    return k;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    read();
    for (int i = 0; i < k; i++)
    {
        dp[i] = (int)a[i].size();
        par[i] = -1;
        for (int j = 0; j < i; j++)
            if (d[i] % d[j] == 0 && dp[j] + (int)a[i].size() > dp[i])
            {
                dp[i] = dp[j] + (int)a[i].size();
                par[i] = j;
            }
    }

    vector<int> ans;
    int curX = 1;
    int w = k - 1;
    int toMul = 1;
    while(true)
    {
        for (int x : a[w])
        {
            ll y = ((ll)x * getRev(curX % d[w], d[w])) % d[w];
            ans.push_back((y * toMul) % m);
            curX = x;
            toMul = 1;
        }
        if (par[w] == -1) break;
        toMul = d[w] / d[par[w]];
        w = par[w];
    }
    printf("%d\n", (int)ans.size());
    for (int x : ans)
        printf("%d ", x);
    printf("\n");

    return 0;
}