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
typedef long long ll;
using namespace std;
ll i,j,x1,y1,x2,y2,n,k,k1,k2,m,y,x;
ll a[5005], dp[3][5005];
vector <ll> b;
map<ll,ll> was;
string s;
ll Abs(ll x)
{
    if (x < 0)
       return -x;
    return x;
}
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] -= i;
        if (!was[a[i]])
        {
         b.push_back(a[i]);
         was[a[i]] = 1;
        }
    }
    sort(b.begin(),b.end());
    k = b.size();
    dp[0][0] = Abs(a[0] - b[0]);
    for (i = 0; i < n; i++)
    {
        if (i != 0)
           dp[i&1][0] = dp[(i-1)&1][0] + Abs(a[i]-b[0]);
        if (i != 0)
        {
        for (j = 1; j < k; j++)
            dp[i&1][j] = min(dp[i&1][j-1],dp[(i-1)&1][j] + Abs(a[i]-b[j]));
        }
        else
        for (j = 1; j < k; j++)
            dp[0][j] = min(dp[0][j-1],Abs(a[0] - b[j]));
    }
    cout << dp[(n-1)&1][k-1] << endl;
    return 0;
}