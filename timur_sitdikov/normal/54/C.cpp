#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back

long long num_of_1(long long v)
{
    long long ans=0, st10=1;
    for(; st10<=v; )
    {
        ans+=min(st10, v-st10+1);
        st10*=10;
        if (st10%10)
            break;
    }
    return ans;
}

const int maxn=1005;
double dp[maxn][maxn], p[maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long n, i, j, l, r, k;
    double ans;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> l >> r;
        p[i]=(num_of_1(r)-num_of_1(l-1)+0.)/(r-l+1.);
    }
    cin >> k;
    dp[1][0]=1-p[1];
    dp[1][1]=p[1];
    for(i=1; i<n; i++)
        for(j=0; j<=i; j++)
        {
            dp[i+1][j]+=(1-p[i+1])*dp[i][j];
            dp[i+1][j+1]+=p[i+1]*dp[i][j];
        }
    ans=0.;
    for(j=0; j<=n; j++)
        if (j*100>=k*n)
            ans+=dp[n][j];
    printf("%.12lf", ans);
}