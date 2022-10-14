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
#define MOD 100003
#define MOD2 (33LL+(ll)1e+17)
#define INF (1+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 118228
typedef long long ll;
using namespace std;
ll l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,x,y,r,z,max1,tx,flag,timer,start,finita,ans;
ll p2[1005],a[N],b[N],letter[N],used[N],dp[60005][3],fac[6005],inv[6005];
string s;
ll C(ll n, ll k)
{
    if (k > n)
       return 0;
    if (k < 0)
       return 0;
    return (1LL*fac[n]*inv[k]*inv[n-k])%MOD;
}
ll binpow(ll x, ll y)
{
    if (y == 0)
       return 1;
    ll tmp = binpow(x,y/2);
    if (y%2 == 0)
       return (1LL*tmp*tmp)%MOD;
    return (1LL*x*tmp*tmp)%MOD;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s;
    cin >> m;
    for (i = 0; i < m; i++)
    {
     cin >> l >> r >> k;
     l--;
     r--;
     ll len = r-l+1;
     k %= len;
     string tmp;
     for (j = 0; j < len; j++)
     {
        tmp.push_back(s[(j-k+len)%len+l]);
     }
     //cout << tmp << endl;
     for (j = l; j <= r; j++)
         s[j] = tmp[j-l];
    }
    cout << s << endl;
    return 0;
}