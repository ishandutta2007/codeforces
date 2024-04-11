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
ll a[100500],b[100500],z,cnt,tmp,l,x1,x2,x3,x4,x5,x6,r,n,m,x,y,k,j,p,k1,k2,i,cur;
ll rez;
string s,t,s2;
ll Abs(ll x)
{
 if (x < 0) return -x;
 return x;
}
ll findk(ll l, ll r, ll dif)
{
 ll rez = 0;
 ll z = 1, i;
 if (l == r) return 1;
 for (i = l; i < r; i++)
     if (a[i]!=a[i+1]) z = 0;
 if (z) return min(a[l]-dif,r-l+1);
 ll min1 = (ll)1e+10;
 for (i = l; i <= r; i++)
     min1 = min(min1,a[i]);
 i = l;
 while (a[i] == min1) i++;
 ll prev = i;
 while (i <= r)
 {
       while (a[i]!=min1 && i <= r) i++;   
       rez += findk(prev,i-1,min1);
       i++;
       prev = i;
 }
 rez += min1-dif;
 rez = min(rez,r-l+1);
 return rez;
}
int main()
{
   cin >> n;
   for (i = 0; i < n; i++)
       cin >> a[i];
  // cout << findk(0,1,1) << endl;
   cout << findk(0,n-1,0) << endl;
   return 0;
}