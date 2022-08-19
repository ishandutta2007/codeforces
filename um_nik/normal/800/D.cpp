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

const int MOD = (int)1e9 + 7;
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
    return ((ll)x * y) % MOD;
}

const int N = (int)1e6;
int pw2[N];
int a[N];
int cnt[N];
int sum[N];
int sumSq[N];
int b[N];
int c[N];
int ppc[64];
int maskToAdd[64];

int getShifted(int w, int mask)
{
    int res = w + maskToAdd[mask];
    for (int i = 0; i < 6; i++)
    {
        int x = w % 10;
        w /= 10;
        if ((mask >> i) & 1) x++;
        if (x == 10) return -1;
    }
    return res;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ppc[0] = 0;
    for (int mask = 1; mask < 64; mask++)
        ppc[mask] = ppc[mask >> 1] ^ (mask & 1);

    pw2[0] = 1;
    for (int i = 1; i < N; i++)
        pw2[i] = add(pw2[i - 1], pw2[i - 1]);

    for (int mask = 1; mask < 64; mask++)
    {
        int k = 0;
        int x = 1;
        while(((mask >> k) & 1) == 0)
        {
            x *= 10;
            k++;
        }
        maskToAdd[mask] = maskToAdd[mask ^ (1 << k)] + x;
    }

    int n;
    scanf("%d", &n);
    while(n--)
    {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    //cerr << "one" << endl;
    for (int w = N - 1; w >= 0; w--)
    {
        cnt[w] = a[w];
        sum[w] = mult(a[w], w);
        sumSq[w] = mult(a[w], mult(w, w));
        for (int mask = 1; mask < 64; mask++)
        {
            int r = getShifted(w, mask);
            if (r == -1) continue;
            if (ppc[mask] == 1)
            {
                cnt[w] += cnt[r];
                sum[w] = add(sum[w], sum[r]);
                sumSq[w] = add(sumSq[w], sumSq[r]);
            }
            else
            {
                cnt[w] -= cnt[r];
                sum[w] = sub(sum[w], sum[r]);
                sumSq[w] = sub(sumSq[w], sumSq[r]);
            }
        }
    }
    //cerr << "two" << endl;
    for (int w = 0; w < N; w++)
    {
        b[w] = 0;
        if (cnt[w] == 0) continue;
        if (cnt[w] == 1)
        {
            b[w] = sumSq[w];
            continue;
        }
        b[w] = mult(pw2[cnt[w] - 2], add(mult(sum[w], sum[w]), sumSq[w]));
    }
    //cerr << "three" << endl;
    for (int w = 0; w < N; w++)
    {
        c[w] = 0;
        for (int mask = 0; mask < 64; mask++)
        {
            int r = getShifted(w, mask);
            if (r == -1) continue;
            int q = ppc[mask];
            if (q == 0)
                c[w] = add(c[w], b[r]);
            else
                c[w] = sub(c[w], b[r]);
        }
    }
    //cerr << "four" << endl;
    ll ans = 0;
    for (ll w = 0; w < N; w++)
        ans ^= w * c[w];
    printf("%lld\n", ans);

    return 0;
}