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
#define MOD 1000000033
#define MOD2 (33LL+(ll)1e+17)
#define INF (1LL+2LL*(ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 228228
typedef long long ll;
using namespace std;
ll l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,x,y,r,z,max1,tx,flag,timer,start,finita,ans;
ll c[N],a[N],b[N],dp[N][15],t[N*4][15];
set<ll> f;
map<ll,ll> sr;
set<ll>::iterator itr;
ll sum (ll v, ll tl, ll tr, ll l, ll r, ll ind) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v][ind];
    ll tm = (tl + tr) / 2;
    return sum (v*2, tl, tm, l, min(r,tm),ind)
        + sum (v*2+1, tm+1, tr, max(l,tm+1), r,ind);
}
void update (ll v, ll tl, ll tr, ll pos, ll new_val, ll ind) {
    if (tl == tr)
        t[v][ind] += new_val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update (v*2, tl, tm, pos, new_val, ind);
        else
            update (v*2+1, tm+1, tr, pos, new_val, ind);
        t[v][ind] = t[v*2][ind] + t[v*2+1][ind];
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    k++;
    update(1,0,n,0,1,0);
    for (i = 0; i < n; i++)
    {
        scanf("%I64d",&x);
        for (j = 1; j <= k; j++)
        {
            ll tmp = sum(1,0,n,0,x-1,j-1);
            update(1,0,n,x,tmp,j);
        }
    }
    ll ans = sum(1,0,n,0,n,k);
    cout << ans << endl;
    return 0;
}