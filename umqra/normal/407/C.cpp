#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

const int K = 110;
const int N = (int)1e5 + 300;
const int mod = (int)1e9 + 7;

int add(int a, int b)
{
    a += b;
    if (a < 0)
        return a + mod;
    if (a < mod)
        return a;
    return a - mod;
}

int val[N];
int a[N][K];
int sum[N][K];
int c[N][K];

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    for (int i = 0; i < N; i++)
        for (int s = 0; s <= min(K - 1, i); s++)
        {
            if (i == 0 || s == 0 || i == s)
                c[i][s] = 1;
            else
                c[i][s] = add(c[i - 1][s], c[i - 1][s - 1]);
        }

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);

    for (int i = 0; i < m; i++)
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        l--, r--;
        a[l][k + 1] = add(a[l][k + 1], 1);
        int p = 0;                                 
        for (int s = k + 1; s >= 1; s--)
        {                                    
            a[r + 1][s] = add(a[r + 1][s], -c[r - l + p][p]);
            p++;
        }
    }

    for (int i = 0; i < n; i++)
    {                   
        for (int s = K - 2; s >= 0; s--)
        {                
            a[i][s] = add(a[i][s], sum[i][s + 1]);
            sum[i][s] = add((i == 0 ? 0 : sum[i - 1][s]), a[i][s]);
        }                       
        printf("%d ", add(val[i], a[i][0]));
    }

    return 0;
}