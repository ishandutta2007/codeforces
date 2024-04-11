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
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
typedef long long ll;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,h,x,y;
string s1,s2,s3;

ll fact[4005],inv[4005],dp[4005],pow2[4005],sum[4005];
ll binpow(ll x, ll y)
{
    if (y == 0)
       return 1;
    ll tmp = binpow(x,y/2);
    tmp = (tmp*tmp)%MOD;
    if (y%2 == 0)
       return tmp;
    else
        return (tmp*x)%MOD;
}
ll C(ll n, ll k)
{
    ll ans = (fact[n]*inv[k])%MOD;
    ans = (ans*inv[n-k])%MOD;
    return ans;
}
ll CC(ll n, ll k)
{
    ll ans = (inv[n]*fact[k])%MOD;
    ans = (ans*fact[n-k])%MOD;
    return ans;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(0);
    //printf("%.3f\n",15.5554);
    cin >> n;
    dp[1] = 1;
    dp[2] = 3;
    sum[1] = 1;
    sum[2] = 4;
    fact[0] = fact[1] = 1;
    inv[0] = inv[1] = 1;
    for (i = 2; i <= 4000; i++)
    {
        fact[i] = (fact[i-1]*i)%MOD;
        inv[i] = binpow(fact[i],MOD-2LL);
    }
    for (j = 3; j <= n; j++)
    {
        for (i = j-1; i >= 2; i--)
            dp[j] = (dp[j]+C(j,i)*sum[i-1])%MOD;
        for (i = j-1; i >= 0; i--)
            dp[j] = (dp[j] + C(j,i))%MOD;
        sum[j] = (dp[j] + sum[j-1])%MOD;
    }
    cout << dp[n] << endl;
    return 0;
}