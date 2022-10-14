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
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
int n,m,j,p,l,r,x,y,a[100500],t[400500],k1,k2,k3,k4,k,i,cur,kokoko;
string s;
map <ll,vector<ll> > f;
ll gcd(ll a, ll b)
{
 if (a%b == 0) return b;
    else
 return gcd(b,a%b);
}
ll init(ll v, ll l, ll r)
{
 if (l == r)
 {
       t[v] = a[l];
       return t[v];
 }
 ll mid = (l+r)/2;
 t[v] = gcd(init(v*2,l,mid),init(v*2+1,mid+1,r));
 return t[v];
}
ll sum(ll v, ll l, ll r, ll fl, ll fr)
{
 //cout << l << " " << r << " " << fl << " " << fr << endl;
 if (fl == l&&fr == r)
    return t[v];
 if (fl > fr)
    return k1;
 ll mid = (l+r)/2;
 return gcd(sum(v*2,l,mid,fl,min(fr,mid)),sum(v*2+1,mid+1,r,max(mid+1,fl),fr));
}
int main()
{
   cin >> n;
   for (i = 0; i < n; i++)
   {
       cin >> a[i];
       f[a[i]].push_back(i+1);
   }
   init(1,0,n-1);
   cin >> m;
   for (j = 0; j < m; j++)
   {       
      // if ((j+1)%1000 == 0) cout << "lalka" << endl;
       cin >> l >> r;
       k1 = a[l-1];
       ll tmp = 0;
       tmp = sum(1,0,n-1,l-1,r-1);
       if (f[tmp].size() == 0)
          cout << r-l+1 << endl;
       else
       {
       ll x = upper_bound(f[tmp].begin(),f[tmp].end(),l-1) - f[tmp].begin();
       ll y = upper_bound(f[tmp].begin(),f[tmp].end(),r) - f[tmp].begin();
       cout << r-l+1-(y-x) << endl;
       }
   }
   return 0;
}