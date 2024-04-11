#include <iostream>
//#include <cmath>
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
ll n,l,r,i,j,k,x1,x2,y1,y2,m,y,v,a[10],flag;
string s;
vector <ll> rez;
ll toint(string x)
{
 ll k = 0;
 ll i,n = x.size(); 
 for (i = 0; i < n; i++)
     k = k*10 + x[i] - '0';
 return k;
}
ll dok(ll first, string x)
{
 ll i,j,n = x.size();
 ll last = n+1;
 for (i = 0; i < n; i++)
     if (x[i] == '?') last = i;
 if (last == n+1)
 {
  ll t = toint(x);
  if (t <= first) flag = 0;
  return t;
 }
 vector <ll> positions;
 for (i = 0; i < n; i++)
 {
     if (x[i] == '?') 
     {
     positions.push_back(i);
     x[i] = '9';
     }
 }
 ll k = toint(x);
 //cout << x << endl;
 if (k <= first) flag = 0;
 for (i = 0; i < positions.size(); i++)
 {
     j = positions[i];
     
     if (j == 0)
        x[j] = '1';
     else
         x[j] = '0';
     k = toint(x);
     if (k <= first)
              x[j] = (first/a[n-j-1])%10+'0';
     k = toint(x);
     if (k <= first) x[j]++;
 }
 return toint(x);
}
int main()
{
    cin >> n;
    l = 0;
    flag = 1;
    a[0] = 1;
    for (i = 1; i < 9; i++)
        a[i] = a[i-1]*10;
    for (i = 0; i < n; i++)
    {
        cin >> s;
        l = dok(l,s);
        rez.push_back(l);
    }
    if (flag == 0)
       cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        for (i = 0; i < rez.size(); i++)
            printf("%d\n",rez[i]);
    }
    return 0;
}