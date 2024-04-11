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
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
#define x1 flkdgl
#define x2 fdgdfgh
#define y1 lfdkgl
#define y2 lhkgflhkf
typedef long long ll;
using namespace std;
ll x1,x2,y1,y2,x,y,z,w,l,r,i,j,n,t[1005000],k,k1,k2,d,m,q,dr,a[200500],ans[200500];
string s;
vector <ll> ladv[100500],ladh[100500];
vector <pair<pair<ll,ll>,pair<ll,ll> > > vv[100500],hh[100500];
void build(ll v, ll tl, ll tr)
{
 if (tl == tr)
 {
    t[v] = a[tl];
    return;
 }
 ll tm = (tl+tr)/2;
 build(v*2,tl,tm);
 build(v*2+1,tm+1,tr);
 t[v] = min(t[v*2],t[v*2+1]);
}

void update(ll v, ll tl, ll tr, ll pos, ll val)
{
 if (tl == tr)
 {
  t[v] = val;
  return;
 }
 ll tm = (tl+tr)/2;
 if (pos <= tm)
    update(v*2,tl,tm,pos,val);
 else
     update(v*2+1,tm+1,tr,pos,val);
 t[v] = min(t[v*2],t[v*2+1]);
}
ll sum(ll v, ll tl, ll tr, ll l, ll r)
{
 if (l > r)
    return (ll)1e+18;
 if (tl == l && tr == r)
    return t[v];
 ll tm = (tl+tr)/2;
 return min(sum(v*2,tl,tm,l,min(tm,r)),sum(v*2+1,tm+1,tr,max(l,tm+1),r));
}
int main()
{
    cin >> n >> m >> k >> q;
    for (i = 0; i < k; i++)
    {
        scanf("%I64d%I64d",&x,&y);
        ladh[x].push_back(y);
        ladv[y].push_back(x);
    }
    

    for (i = 0; i < q; i++)
    {
        scanf("%I64d%I64d%I64d%I64d",&x1,&y1,&x2,&y2);
        hh[x2].push_back(mp(mp(x1,i),mp(y1,y2)));
        vv[y2].push_back(mp(mp(y1,i),mp(x1,x2)));
    }
    for (i = 0; i <= n+m; i++)
        a[i] = 0;
    build(1,0,m+n);
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < ladh[i].size(); j++)
        {
            update(1,0,m+n,ladh[i][j],i);
        }
        for (j = 0; j < hh[i].size(); j++)
        {
            if (sum(1,0,m+n,hh[i][j].second.first,hh[i][j].second.second) >=
               hh[i][j].first.first)
               ans[hh[i][j].first.second] = 1;
        }
    }
    
    for (i = 0; i <= m+n; i++)
        a[i] = 0;
    build(1,0,m+n);
    
    for (i = 1; i <= m; i++)
    {
        for (j = 0; j < ladv[i].size(); j++)
        {
            update(1,0,m+n,ladv[i][j],i);
        }
        for (j = 0; j < vv[i].size(); j++)
        {
            if (sum(1,0,m+n,vv[i][j].second.first,vv[i][j].second.second) >=
               vv[i][j].first.first)
               ans[vv[i][j].first.second] = 1;
            
        }
    }
    
    for (i = 0; i < q; i++)
        if (ans[i])
           cout << "YES" << endl;
        else
            cout << "NO" << endl;
    return 0;
}