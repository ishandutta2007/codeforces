#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 (33LL+(ll)1e+17)
#define INF (1+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 558228
typedef int ll;
using namespace std;
ll l,i,j,n,k,k1,k2,k3,k4,k5,m,x1,y1,x2,y2,r,x,y,z,ans;
long double dp[105][100005];
ll a[N];
set <ll> f;
set <ll>::iterator itr;
pii g[N];
vector <pii> gg;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    dp[0][0] = 1;
    cin >> n >> m;
    if (m == 1)
    {
        printf("%.12f\n",1.0);
        return 0;
    }
    ll sum = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    long double cons = 1./(m-1);
    for (i = 1; i <= n; i++)
    {
        long double tmp = 0;
        for (j = max(0,i-m-1); j < max(0,i-2); j++)
            tmp += dp[i-1][j];
        for (k = i; k <= n*m; k++)
        {
            tmp += dp[i-1][k-1];
            if (k >= m+1)
               tmp -= dp[i-1][k-m-1];
            ll num = a[i-1];
            long double tt = 0;
            if (k >= num)
               tt = dp[i-1][k-num];
            dp[i][k] += (tmp-tt)*cons;
        }
    }
    long double ans = 1;
    for (i = 0; i < sum; i++)
        ans += (long double)(m-1)*dp[n][i];
    printf("%.12f\n",(double)ans);
    return 0;
}