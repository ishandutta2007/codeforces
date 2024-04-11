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

const ll MMOD = (ll)1e9 + 7;

const int MOD = 5;
int add(int x, int y)
{
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}
int sub(int x, int y)
{
    x -= y;
    if (x < 0) return x + MOD;
    return x;
}
int mult(int x, int y)
{
    return (x * y) % MOD;
}
int rev(int x)
{
    int y = 1;
    while(y % x) y += MOD;
    return y / x;
}

const int N = 555;
int n, m;
int g[N][N];
int a[N];
char s[N];
int b[N];
ll ans = 1;

void gauss()
{
    int k = 0;
    for (int i = 0; i < m; i++) {
        int v = -1;
        for (int j = k; j < n && v == -1; j++) {
            if (g[j][i] != 0) {
                v = j;
            }
        }
        if (v == -1) continue;
        a[i] = k;
        swap(g[k], g[v]);
        int x = rev(g[k][i]);
        for (int j = 0; j < m; j++)
            g[k][j] = mult(g[k][j], x);
        for (int j = k + 1; j < n; j++) {
            for (int h = m - 1; h >= i; h--)
                g[j][h] = sub(g[j][h], mult(g[k][h], g[j][i]));
        }
        k++;
    }
    for (int i = k; i < n; i++)
        ans = (ans * 5) % MMOD;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        for (int j = 0; j < m; j++)
            g[i][j] = (int)(s[j] - 'a');
    }
    for (int i = 0; i < m; i++)
        a[i] = -1;
    gauss();

    int q;
    scanf("%d", &q);
    while(q--) {
        scanf("%s", s);
        for (int i = 0; i < m; i++)
            b[i] = (int)(s[i] - 'a');
        bool bad = false;
        for (int i = 0; i < m; i++) {
            if (b[i] == 0) continue;
            if (a[i] == -1) {
                bad = true;
                break;
            }
            for (int j = m - 1; j >= i; j--) 
                b[j] = sub(b[j], mult(g[a[i]][j], b[i]));
        }
        if (bad)
            printf("0\n");
        else
            printf("%lld\n", ans);
    }

    return 0;
}