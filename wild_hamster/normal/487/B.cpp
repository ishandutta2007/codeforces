#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
typedef long long ll;
using namespace std;
ll n,l,r,i,j,k,x,m,y,v,s,rez,a[100500];
ll tmax[500500],tmin[500500],dp[200500];
void buildmax (ll v, ll tl, ll tr) {
    if (tl == tr)
        tmax[v] = a[tl];
    else {
        ll tm = (tl + tr) / 2;
        buildmax (v*2, tl, tm);
        buildmax (v*2+1, tm+1, tr);
        tmax[v] = max(tmax[v*2],tmax[v*2+1]);
    }
}
ll findmax (ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
        return -(ll)1e+18;
    if (l == tl && r == tr)
        return tmax[v];
    ll tm = (tl + tr) / 2;
    return max(findmax (v*2, tl, tm, l, min(r,tm)), findmax(v*2+1, tm+1, tr, max(l,tm+1), r));
}

void buildmin (ll v, ll tl, ll tr) {
    if (tl == tr)
        tmin[v] = a[tl];
    else {
        ll tm = (tl + tr) / 2;
        buildmin (v*2, tl, tm);
        buildmin (v*2+1, tm+1, tr);
        tmin[v] = min(tmin[v*2],tmin[v*2+1]);
    }
}
ll findmin (ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
        return (ll)1e+18;
    if (l == tl && r == tr)
        return tmin[v];
    ll tm = (tl + tr) / 2;
    return min(findmin (v*2, tl, tm, l, min(r,tm)), findmin(v*2+1, tm+1, tr, max(l,tm+1), r));
}
int main()
{
    cin >> n >> s >> l;
    for (i = 0; i < n; i++)
        cin >> a[i];
    buildmax(1,0,n-1);
    buildmin(1,0,n-1);
    for (i = 0; i <= n; i++)
        dp[i] = (ll)1e+18;
    dp[0] = 0;
    ll left = 0;
    for (i = 0; i < n-l+1; i++)
    {
        if (dp[i] == (ll)1e+18) continue;
        for (j = max(i+l-1,left); j < n; j++)
        {
         ll tmp = findmax(1,0,n-1,i,j) - findmin(1,0,n-1,i,j);
         if (tmp > s) break;
         dp[j+1] = dp[i]+1;
         left = j+1;
        }
    }
    if (dp[n]!=(ll)1e+18)
    cout << dp[n] << endl;
    else
    cout << -1 << endl;
    return 0;
}