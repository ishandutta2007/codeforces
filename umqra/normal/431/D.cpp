#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <string>
using namespace std;
                 
typedef long long ll;
const int N = 100;
ll dp[N][N];
int par[N][N];
ll C[N][N];

ll genAns(int pos, int cntOne)
{
    if (pos == 0)
        return 0;
    ll res = 0;
    int t = par[pos][cntOne];             
    if (t == 0)
    {
        res = genAns(pos - 1, cntOne);
        res *= 2;
    }
    else
    {
        res = genAns(pos - 1, cntOne - 1);
        res *= 2;
        res++;
    }
    return res;
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif


    ll m, k;
    cin >> m >> k;
    for (int i = 0; i < N; i++)
        for (int s = 0; s <= i; s++)
        {
            if (i == 0 || s == 0 || i == s)
                C[i][s] = 1;
            else
                C[i][s] = C[i - 1][s] + C[i - 1][s - 1];
            if (C[i][s] > m)
                C[i][s] = m + 1;   
        }                       
    for (ll len = 1; len < 63; len++)
    {                               
        for (ll pos = 0; pos <= len; pos++) for (int cnt = 0; cnt <= k; cnt++) dp[pos][cnt] = -1;
        dp[0][0] = 0;
        for (ll pos = 0; pos < len; pos++)
            for (int cntOne = 0; cntOne <= k; cntOne++)
            {
                if (dp[pos][cntOne] == -1)
                    continue;
                if (dp[pos + 1][cntOne] < dp[pos][cntOne])
                {
                    dp[pos + 1][cntOne] = dp[pos][cntOne];
                    par[pos + 1][cntOne] = 0;
                }
                ll d = 0;             
                if (k - cntOne - 1 >= 0)
                {                     
                    d = C[len - pos - 1][k - cntOne - 1];
                }


                if (dp[pos + 1][cntOne + 1] < dp[pos][cntOne] + d && dp[pos][cntOne] + d <= m)
                {
                    dp[pos + 1][cntOne + 1] = dp[pos][cntOne] + d;
                    par[pos + 1][cntOne + 1] = 1;
                }

            }                     
        for (int cntOne = 0; cntOne <= k; cntOne++)
        {                                   
            if (dp[len][cntOne] == m)
            {                                  
                ll t = genAns(len, cntOne);
                if (t <= (ll)1e18 && t > 0)
                {
                    cout << t;
                    return 0;
                }
            }
        }
    }
    throw;

    return 0;
}