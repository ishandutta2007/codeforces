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
#include <queue>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF ((ll)1e+15)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define bull 500400
typedef long long ll;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,x1,x,y,y1,x2,y2,x3,y3,h,z;
string s1,s2,s3,s,t;
ll a[800505],dp[5005][5005];
int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (i = 0; i < n; i++)
        scanf("%I64d",&a[i]);
    sort(a,a+n);
    k = n/m;
    if (n%m == 0)
    {
        k1 = m;
        k2 = 0;
    } else
    {
        k2 = n%m;
        k1 = m- n%m;
    }
    //dp[k1][k2]
    for (i = 0; i <= k1; i++)
        for (j = 0; j <= k2; j++)
            dp[i][j] = INF;
    dp[0][0] = 0;
    for (i = 0; i <= k1; i++)
        for (j = 0; j <= k2; j++)
        {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + a[(i+1)*k+j*(k+1) - 1] - a[i*k + j*(k+1)]);
            dp[i][j+1] = min(dp[i][j+1], dp[i][j] + a[(i)*k+(j+1)*(k+1) - 1] - a[i*k + j*(k+1)]);
        }
    cout << dp[k1][k2] << endl;
    return 0;
}