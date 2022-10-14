#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 320
#define N 8388607
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,l,timer;
ll d[505][505], val[505];
long double dp[505][505], p[505][505];
vector<ll> myshit[250];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    int k = (1<<n);
    for (i = 1; i <= k; i++)
        for (j = 1; j <= k; j++)
            cin >> d[i][j];
    for (j = k-1; j >=1; j--)
        val[j] = val[j*2]+1;
    for (j = k; j < 2*k; j++)
    {
        myshit[j].push_back(j-k+1);
        p[j][j-k+1] = 1;
    }
    for (j = k-1; j >= 1; j--)
    {
        for (i = 0; i < myshit[j*2].size(); i++)
            myshit[j].push_back(myshit[j*2][i]);
        for (i = 0; i < myshit[j*2+1].size(); i++)
            myshit[j].push_back(myshit[j*2+1][i]);
    }
    for (j = k-1; j >= 1; j--)
    {
        for (auto i : myshit[j*2])
            for (auto l : myshit[j*2+1])
            {
                p[j][i] += p[j*2][i]*p[j*2+1][l]*d[i][l]/100;
                p[j][l] += p[j*2][i]*p[j*2+1][l]*d[l][i]/100;
            }
        for (auto i : myshit[j*2])
            for (auto l : myshit[j*2+1])
                if (i != l)
                {
                    dp[j][i] += p[j*2][i]*p[j*2+1][l]*d[i][l]*(1<<(val[j]-1))/100;
                    dp[j][l] += p[j*2][i]*p[j*2+1][l]*d[l][i]*(1<<(val[j]-1))/100;
                }
        long double maxi = 0, maxl = 0;
        for (auto i : myshit[j*2])
            dp[j][i] += dp[j*2][i], maxi = max(maxi, dp[j*2][i]);
        for (auto i : myshit[j*2+1])
            dp[j][i] += dp[j*2+1][i], maxl = max(maxl, dp[j*2+1][i]);
        for (auto i : myshit[j*2])
            dp[j][i] += maxl;
        for (auto i : myshit[j*2+1])
            dp[j][i] += maxi;
    }
    long double ans = 0;
    for (i = 1; i <= k; i++)
        ans = max(ans, dp[1][i]);
    printf("%.12f\n",(double)ans);
    return 0;
}