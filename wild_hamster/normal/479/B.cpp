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
ll n,m,j,p,l,r,x,y,k1,k2,k3,k4,k,i,w,rez,b[100500];
pair<ll,ll> a[100500];
vector <pair<ll,ll> > f;
int main()
{
   cin >> n >> k;
   for (i = 0; i < n; i++)
   {
       cin >> a[i].first;
       a[i].second = i+1;
   }
   for (i = 0; i < k; i++)
   {
    sort(a,a+n);
    if (a[n-1].first - a[0].first > 1)
       {
               a[0].first++;
               a[n-1].first--;
               f.push_back(mp(a[n-1].second,a[0].second));
       }   
   }
   sort(a,a+n);
   cout << a[n-1].first - a[0].first << " " << f.size() << endl;
   for (i = 0; i < f.size(); i++)
       cout << f[i].first << " " << f[i].second << endl;
   return 0;
}