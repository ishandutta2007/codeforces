#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int poww(int a, int b)
{
    if(b == 0) return 1;
    if(b & 1) return 1LL * a * poww(a, b - 1) % mod;
    return poww(1LL * a * a % mod, b / 2);
}

int inv(int x)
{
    return poww(x, mod - 2);
}

const int K = 200001;
int fac[K];
int facinv[K];

const int N = 2002;
int dp[N];

pair<int, int> bl[N];

int newton(int n, int k)
{
    return 1LL * fac[n] * facinv[k] % mod * facinv[n-k] % mod;
}

int jump(int w, int h)
{
//     printf("jump(%d %d)\n", w, h);
    return newton(w + h, w);
}

int main()
{
    fac[0] = 1;
    for(int i = 1; i < K; i++)
        fac[i] = 1LL * fac[i-1] * i % mod;
    facinv[K-1] = inv(fac[K-1]);
    for(int i = K - 2; i >= 0; i--)
        facinv[i] = 1LL * facinv[i+1] * (i+1) % mod;
    
//     for(int i = 0; i < 5; i++)
//         printf("%d: %d %d\n", i, fac[i], facinv[i]);
    
    int h, w, n;
    scanf("%d %d %d", &h, &w, &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &bl[i].first, &bl[i].second);
    bl[n++] = { 1, 1 };
    bl[n++] = { h, w };
    sort(bl, bl + n);
    dp[0] = -1;
    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++)
            if(bl[i].second >= bl[j].second)
            {
//                 printf("%d %d %d\n", i, j, jump(bl[i].first - bl[j].first, bl[i].second - bl[j].second));
                dp[i] = (dp[i] - 1LL * dp[j] * jump(bl[i].first - bl[j].first, bl[i].second - bl[j].second)) % mod;
            }
//     for(int i = 0; i < n; i++)
//         printf("%d: %d\n", i, dp[i]);
    if(dp[n-1] < 0) dp[n-1] += mod;
    printf("%d\n", dp[n-1]);
}