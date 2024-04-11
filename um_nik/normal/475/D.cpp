#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;
typedef long long ll;

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

int n;
int q;
map<int, ll> ans;
int a[100100];
int b[100100][20];
int lg[200100];

int get_gcd(int l, int r)
{
    int len = r - l;
    int k = lg[len];
    return gcd( b[l][k], b[r - (1 << k)][k] );
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    lg[1] = 0;
    for (int i = 2; i < 200000; i++)
    {
        lg[i] = lg[i - 1];
        while ((1 << lg[i]) <= i) lg[i]++;
        lg[i]--;
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        b[i][0] = a[i];
    for (int k = 1; k < 20; k++)
        for (int i = 0; i + (1 << k) <= n; i++)
        {
            b[i][k] = gcd(b[i][k - 1], b[i + (1 << (k - 1))][k - 1]);
        }
    for (int L = 0; L < n; L++)
    {
        int R = L;
        while(R < n)
        {
            int g = get_gcd(L, R + 1);
            int l = R;
            int r = n;
            while (r - l > 1)
            {
                int m = (l + r) / 2;
                int x = get_gcd(L, m + 1);
                if (x < g)
                    r = m;
                else
                    l = m;
            }
            ans[g] += r - R;
            R = r;
        }
    }
    scanf("%d", &q);
    while(q--)
    {
        int x;
        scanf("%d", &x);
        printf("%I64d\n", ans[x]);
    }

    return 0;
}