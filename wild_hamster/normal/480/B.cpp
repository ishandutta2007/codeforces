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
ll a[100500];
map <ll,ll> c;
int main()
{
    cin >> n >> l >> x >> y;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        c[a[i]] = 1;
    }
    ll flag = 0;
    for (i = 0; i < n; i++)
        if (c[a[i] + x] == 1) flag = 1;
    if (flag)
    {
     flag = 0;
     for (i = 0; i < n; i++)
         if (c[a[i] + y] == 1) flag = 1;
     if (flag) cout << 0 << endl;
        else cout << 1 << endl << y << endl;
     return 0;
    } else
    {
     flag = 0;
     for (i = 0; i < n; i++)
        if ((c[a[i] + x - y] == 1 || c[a[i] + x + y]  == 1)&&a[i]+x < l)
        {
             cout << 1 << endl << a[i]+x << endl;
             flag = 1;
             break;
        }
        else
        if ((c[a[i] - x + y] == 1 && a[i] - x >= 0)||
        (c[a[i] - x - y] == 1 && a[i] - x >= 0))
        {
             cout << 1 << endl << a[i]-x << endl;
             flag = 1;
             break;
        }
        else
        if (c[a[i] + y] == 1)
        {
         cout << 1 << endl << x << endl;
         flag = 1;
         break;
        }
     if (!flag) cout << 2 << endl << x << " " << y << endl;
    }
   return 0;
}