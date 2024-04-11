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
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define MAXN 100100
typedef long long ll;
using namespace std;
ll x,y,l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,r,z,max1,tx,pnt,flag;
vector <ll> divisors,ans;
ll a[150500],dp[150505],new_dp[150505],t[600500];
ll Abs(ll x)
{
    return x>0?x:-x;
}
void build() {  // build the tree
  for (int i = n-1; i >= 1; --i) t[i] = max(t[i<<1],t[i<<1|1]);
}
ll query(ll l, ll r) {  // sum on interval [l, r)
  ll res = -INF;

    //cout << l << " " << r << endl;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res,t[l++]);
    if (r&1) res = max(res,t[--r]);
  }
  //cout << res << endl;
  return res;
}
int main()
{
    //freopen("input.txt","r",stdin);
    ll d;
    cin >> n >> m >> d;
    ll val = 0;
    for (i = 0; i < m; i++)
    {
        //for (j = 1; j <= n; j++)
        //  cout << dp[j] << " ";
        //cout << endl;
        scanf("%I64d%I64d%I64d",&x,&y,&z);
        ll dif;
        if (i == 0)
        {
            val = z;
            dif = 0;
        } else
        {
            dif = z-val;
            val = z;
        }
        for (j = 1; j <= n; j++)
            t[j+n-1] = dp[j];
        build();
        for (j = 1; j <= n; j++)
            new_dp[j] = y - Abs(x-j);
        for (j = 1; j <= n; j++)
        {
            ll l = max(1LL,j-d*dif);
            ll r = min(n,j+d*dif);
            new_dp[j] += query(l-1,r);
        }
        for (j = 1; j <= n; j++)
            dp[j] = new_dp[j];
    }
    ll max1 = -INF;
    for (i = 1; i <= n; i++)
        max1 = max(max1,dp[i]);
    cout << max1 << endl;
    return 0;
}