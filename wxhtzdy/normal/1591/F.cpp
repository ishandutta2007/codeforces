// from atcoder...
#include<bits/stdc++.h>
 
using namespace std;
 
const int maxN = 500009;
int bruteDp[maxN], nr, N, dp[maxN], a[maxN], sum[maxN][2], s[maxN][2], stk[maxN];
const int mod = 998244353;
 
int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}
 
int power (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = mul (p, a);
        a = mul (a, a);
    }
    return p;
}
 
int fac[2000009], inv[2000009];
void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = power (fac[lim], mod - 2);for (int i=lim - 1; i>=0; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){if (K > N || N < 0 || K < 0) return 0; int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}
 
int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);
 
scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
/*bruteDp[0] = 1;
for (int i=1; i<=N; i++)
{
    int mi = a[i];
    for (int j=i - 1; j>=0; j--)
    {
        int curr = mul (bruteDp[j], mi);
        if (j % 2 != i % 2) adto (bruteDp[i], curr);
        else bruteDp[i] = subtract (bruteDp[i], curr);
        mi = min (mi, a[j]);
    }
}*/
dp[0] = 1;
for (int i=1; i<=N; i++)
{
    int s0 = 0, s1 = 0;
    while (nr > 0 && a[stk[nr]] > a[i])
    {
        adto (s0, s[nr][0]);
        adto (s1, s[nr][1]);
        nr --;
    }
    if (i == 5)
        i = 5;
    int v[2] = {add (mul (s0, a[i]), sum[nr][0]), add (mul (s1, a[i]), sum[nr][1])};
    adto (v[i % 2], mul (dp[i - 1], a[i]));
    dp[i] = subtract (v[i % 2], v[(i % 2) ^ 1]); ///0 is for j, and then i add dp[j - 1]
 
    stk[++nr] = i;
    s[nr][0] = s0, s[nr][1] = s1;
    adto (s[nr][i % 2], dp[i - 1]);
    sum[nr][0] = add (sum[nr - 1][0], mul (a[i], s[nr][0]));
    sum[nr][1] = add (sum[nr - 1][1], mul (a[i], s[nr][1]));
}
printf ("%d\n", dp[N]);
return 0;
}