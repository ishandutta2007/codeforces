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
#define SQ 500400
#define CI 43534
typedef long long ll;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,x,y,x1,y1,x2,y2,x3,y3,h,z,l1,l2,l3;
string s1,s2,s3,s,t;
ll a[2000500],fact[2000500],inv[2000500];
ll binpow(ll x, ll y)
{
    if (y == 0)
       return 1;
    ll tmp = binpow(x,y/2);
    tmp *= tmp;
    tmp %= MOD;
    if (y%2 == 0)
       return tmp;
    return (x*tmp)%MOD;
}
ll C(ll n, ll k)
{
    return (((fact[n]*inv[k])%MOD)*inv[n-k])%MOD;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    fact[0] = 1;
    for (i = 1; i <= 2000300; i++)
    {
        fact[i] = (fact[i-1]*i)%MOD;
        inv[i] = binpow(fact[i],MOD-2);
    }

    cin >> n;
    ll ans = 0;
    for (i = 0; i <= n; i++)
        ans += C(n+i+1,n);
    cout << ans%MOD << endl;
    return 0;
}