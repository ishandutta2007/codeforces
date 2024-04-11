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
#define N 100499
typedef long long ll;
using namespace std;
ll i,j,n,l,r,rez,k,m,y,z,q,x,a[100500],b[100500][35],t[500500],queries[100500][3];
string s;
void build(ll v, ll fl, ll fr)
{
     if (fl == fr)
     {
        t[v] = a[fl];
        return;
     }
     ll mid = (fl+fr)/2;
     build(v*2,fl,mid);
     build(v*2+1,mid+1,fr);
     t[v] = t[v*2]&t[v*2+1];
}
ll sum(ll v, ll fl, ll fr, ll l, ll r)
{
     if (l > r)
        return ((1<<31)-1);
     if (fl == l && fr == r)
        return t[v];
     ll mid = (fl+fr)/2;
     return sum(v*2,fl,mid,l,min(r,mid))&sum(v*2+1,mid+1,fr,max(l,mid+1),r);
}
int main()
{
    cin >> n >> m >> x >> y;
    l = 0; r = (ll)1e+10;
    while (l < r)
    {
          ll mid = (l+r+1)/2-1;
          //cout << mid << " " << l << " " << r << endl;
          ll tmp = mid - mid/(x*y);
          ll n1 = mid - mid/x;
          ll m1 = mid - mid/y;
          if (tmp >= n+m&&n1 >= n&&m1 >= m)
             r = mid;
          else
              l = mid+1;
    }
    cout << l << endl;
    return 0;
}