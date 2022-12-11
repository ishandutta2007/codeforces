#include <bits/stdc++.h>
using namespace std;

int a[5005];
int L[5005], R[5005];
int dp[5005];
bool v[5005];
int n;

int D(int t)
{
    if (t == n + 1) return 0;

    if (v[t] == false)
    {
        v[t] = true;
        dp[t] = D(t + 1);

        int maxi = R[a[t]], adde = 0;
        bool wrong = false;

        for (int i = t; i <= maxi; i++)
        {
            if (L[a[i]] < t)
            {
                wrong = true; break;
            }
            maxi = max(maxi, R[a[i]]);
            if (i == R[a[i]]) adde ^= a[i];
        }

        if (wrong == false) dp[t] = max(dp[t], D(maxi + 1) + adde);
    }

    return dp[t];
}

int main()
{
    scanf("%d",&n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        if (L[a[i]] == 0) L[a[i]] = i;
        R[a[i]] = i;
    }

    printf("%d\n", D(1));
}