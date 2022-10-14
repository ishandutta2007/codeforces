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
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 998244353
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
typedef int ll;
using namespace std;

ll l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,r,x,y,z,max1;
string s1,s2,s3;
ll a[305305],cnt[305];
ll dp[305];
vector <ll> ans;
multiset <ll> f;
multiset <ll>::iterator itr;
ll gcd(ll a, ll b)
{
    if (b == 0)
       return a;
    return gcd(b,a%b);
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   cin >> n >> m;
   for (i = 0; i < n; i++)
       cin >> a[i];
   if (m <= 620)
   {
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            a[j*n+i] = a[i];
    ll sz = n*m;
    for (i = 0; i < sz; i++)
        for (j = a[i]; j >= 0; j--)
            dp[a[i]] = max(dp[a[i]], dp[j] + 1);
    ll ans = 0;
    for (i = 0; i <= 300; i++)
        ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
   }
   ll t = 310;
   for (i = 0; i < n; i++)
        for (j = 0; j < t; j++)
            a[j*n+i] = a[i];
    ll sz = n*t;
    for (i = 0; i < sz; i++)
        for (j = a[i]; j >= 0; j--)
            dp[a[i]] = max(dp[a[i]], dp[j] + 1);
    m -= 620;
    for (i = 0; i < n; i++)
        cnt[a[i]]++;
    for (i = 0; i <= 300; i++)
        dp[i] += cnt[i]*m;
    for (i = 0; i < sz; i++)
        for (j = a[i]; j >= 0; j--)
            dp[a[i]] = max(dp[a[i]], dp[j] + 1);
            
    ll ans = 0;
    for (i = 0; i <= 300; i++)
        ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}