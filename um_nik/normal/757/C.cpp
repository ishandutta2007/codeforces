#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <complex>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const ll MOD = (ll)1e9 + 7;
ll mult(ll x, ll y)
{
    return (x * y) % MOD;
}

const int N = (int)1e6 + 3;
int n, m, k;
int a[N];
map<pii, int> mapchik;
int b[N], c[N];
int d[N];

void myInsert(int x, int y)
{
    pii t = mp(x, y);
    if (mapchik.count(t) != 0) return;
    mapchik[t] = k++;
}

int main()
{
    scanf("%d%d", &n, &m);
    k = 1;
    for (int i = 0; i < m; i++)
        a[i] = 0;
    while(n--)
    {
        int s;
        scanf("%d", &s);
        mapchik.clear();
        for (int i = 0; i < s; i++)
        {
            scanf("%d", &b[i]);
            b[i]--;
            c[b[i]]++;
        }
        sort(b, b + s);
        s = unique(b, b + s) - b;
        for (int i = 0; i < s; i++)
            myInsert(a[b[i]], c[b[i]]);
        for (int i = 0; i < s; i++)
            a[b[i]] = mapchik[mp(a[b[i]], c[b[i]])];
        for (int i = 0; i < s; i++)
            c[b[i]] = 0;
    }
    for (int i = 0; i < m; i++)
        d[a[i]]++;
    ll ans = 1;
    for (int x = 0; x < k; x++)
    {
        for (int i = 1; i <= d[x]; i++)
            ans = mult(ans, i);
    }
    printf("%lld\n", ans);

    return 0;
}