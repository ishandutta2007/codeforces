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
#define MOD 1000000009
typedef long long ll;
using namespace std;
map <ll, vector<ll> > used;
map <ll, vector<ll> >::iterator itr;
ll t[3005000];
ll x,y,w,l,r,i,j,n,k,k1,k2,d,m,q,max1,a[505000],b[505000],dist[500500],anc[500500];
pair<pair <ll,ll>,ll> queries[500500];
ll rez[500500];
bool ff(pair<pair <ll,ll>,ll> x, pair<pair <ll,ll>,ll> y)
{
 if (x.first.second > y.first.second)
    return true;
 return false;
}
void build(ll v, ll tl, ll tr)
{
 if (tl == tr)
 {
  t[v] = dist[tl];
  return;
 }
 ll tm = (tl+tr)/2;
 build(2*v,tl,tm);
 build(2*v+1,tm+1,tr);
 t[v] = min(t[v*2],t[v*2+1]);
} 

ll find1(ll v, ll tl, ll tr, ll l, ll r)
{
 if (l > r)
    return (ll)1e+18;
 if (l == tl && r == tr)
    return t[v];
 ll tm = (tl+tr)/2;
 return min(find1(v*2,tl,tm,l,min(r,tm)),find1(v*2+1,tm+1,tr,max(l,tm+1),r));
}

void update(ll v, ll tl, ll tr, ll pos, ll val)
{
 if (tl == tr)
 {
    t[v] = val;
    return;
 }
 ll tm = (tl+tr)/2;
 if (tm >= pos)
    update(v*2,tl,tm,pos,val);
 else
     update(v*2+1,tm+1,tr,pos,val);
 t[v] = min(t[v*2],t[v*2+1]);
}
int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d",&a[i]);
        used[a[i]].push_back(i+1);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%I64d%I64d",&queries[i].first.first,&queries[i].first.second);
        queries[i].second = i;
    }
        
    for (i = 1; i <= n; i++)
        dist[i] = (ll)1e+18;
    
    for (i = 1; i <= n; i++)
        anc[i] = -1;    
    for (itr = used.begin(); itr != used.end(); itr++)
    {
        ll tmp = (*itr).first;
        ll sz = used[tmp].size();
        for (i = 0; i < sz - 1; i++)
        {
            dist[used[tmp][i]] = used[tmp][i+1] - used[tmp][i];
            anc[used[tmp][i+1]] = used[tmp][i];
        }
    }
    sort(queries,queries+m,ff);
    build(1,1,n);
    r = n;
    for (i = 0; i < m; i++)
    {
        x = queries[i].first.first;
        y = queries[i].first.second;
        while (r > y)
        {
         if (anc[r] != -1)
         {
         dist[anc[r]] = (ll)1e+18;
         update(1,1,n,anc[r],(ll)1e+18);
         }
         r--;
        } 
        /*for (j = 1; j <= n; j++)
            cout << dist[j] << " ";
        cout << endl;     */  
        //cout << x << " " << y << endl;
        ll tmp = find1(1,1,n,x,y);
        
        if (tmp == (ll)1e+18)
           rez[queries[i].second] = -1;
        else
           rez[queries[i].second] = tmp; 
    }
    for (i = 0; i < m; i++)
        printf("%I64d\n",rez[i]);
    return 0;
}