#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
ll t[400500],z[400500],rez,l,r,n,m,k,j,p,k1,k2,i;
pair <ll,ll> a[500000];

int main()
{
   cin >> n;
   for (i = 0; i < n; i++)
   cin >> a[i].first >> a[i].second;
   sort(a,a+n);
   rez = 0;
   ll eff = 0;
   for (i = 0; i < n; i++)
       if (a[i].first == a[i+1].first)
       {
             if (a[i].second < eff) rez = 1;
       }
       else 
       {
       if (a[i].second < eff) rez = 1;
       eff = max(eff,a[i].second);
       }
   if (rez) cout << "Happy Alex" << endl;
   else cout << "Poor Alex" << endl;
   return 0;
}