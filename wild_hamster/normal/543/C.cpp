#include <omp.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <fstream>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll cur,k,oz,w,l,r,i,j,k1,k2,dr,n,m, t, qt, qh, md, dp[1080005], a[25][25], c[25][25], bt[25][25], x, y, p;
string s[30];


int main()
{
    //freopen("race.in","r",stdin);
    //freopen("race.out","w",stdout);
    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> s[i];
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            ll price = -1;
            for (k = 0; k < n; k++)
            {
                if (s[i][j] == s[k][j])
                {
                    price = max(price,a[k][j]);
                    c[i][j] += a[k][j];
                    bt[i][j] |= (1<<k);
                }
            }
            c[i][j] -= price;
        }
        
    dp[0] = 0;
    for (i = 1; i < (1<<n); i++)
        dp[i] = MOD;
    for (int mask = 0; mask < (1<<n); mask++)
    {
        ll lowbit = 0;
        for (i = 0; i < n; i++)
            if ((mask&(1 << i)) == 0)
            {
                lowbit = i;
                break;
            }
        for (i = 0; i < m; i++)
        {
            dp[mask|(1<<lowbit)] = min(dp[mask|(1<<lowbit)],dp[mask] + a[lowbit][i]);
            dp[mask|bt[lowbit][i]] = min(dp[mask|bt[lowbit][i]],dp[mask] + c[lowbit][i]);
        }
    }
    cout << dp[(1<<n)-1] << endl;
    return 0;
}