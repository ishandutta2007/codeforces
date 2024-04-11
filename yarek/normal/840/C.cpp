#include <bits/stdc++.h>
using namespace std;

const int N = 301, mod = 1000000007;
long long dp1[N];
long long dp2[N];
long long newton[N][N];
long long fact[N];
map<int, int> mp;

int main()
{
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = fact[i-1] * i % mod;
    for(int i = 0; i < N; i++)
    {
        newton[i][0] = newton[i][i] = 1;
        for(int j = 1; j < i; j++)
            newton[i][j] = (newton[i-1][j-1] + newton[i-1][j]) % mod;
    }
    int n;
    scanf("%d", &n);
    dp2[0] = 1;
    while(n--)
    {
        int x;
        scanf("%d", &x);
        for(int i = 2; i * i <= x; i++)
        {
            while(x % (i * i) == 0)
                x /= i * i;
        }
        mp[x]++;
    }
    int s = 0;
    bool first = true;
    long long f = 1;
    for(auto p: mp)
    {
        int k = p.second;
        f = f * fact[k] % mod;
        for(int i = 0; i < N; i++)
        {
            dp1[i] = dp2[i];
            dp2[i] = 0;
        }
        for(int t = 0; t < s; t++)
            for(int i = 1; i <= k && i <= s + 1; i++)
                for(int j = 0; j <= 2 && j <= i; j++)
                    for(int l = 0; l <= t && l + j <= i; l++)
                    {
                        dp2[k-i+t-l] += dp1[t] * newton[2][j] * newton[t][l] % mod * newton[s-1-t][i-l-j] % mod * newton[k-1][i-1];
                        dp2[k-i+t-l] %= mod;
                    }
        if(first)
        {
            dp2[k-1] = 1;
            first = false;
        }
        s += k;
    }
    printf("%lld\n", dp2[0] * f % mod);
}