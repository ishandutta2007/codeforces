#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#define tr 1000000007
#define mp make_pair
typedef long long ll;
using namespace std;
ll a[30],x,k,i,j,n;
void make_swap(ll x, ll maxed)
{
    // cout << x << " " << maxed << endl;
     if (maxed >= n || x == 0) return;
     ll tmpmax = a[maxed], maxpos = maxed;
     for (int i = maxed+1; i < min(maxed+x+1,n); i++)
         if (a[i] > tmpmax)
         {
                  tmpmax = a[i];
                  maxpos = i;
         }
     for (int i = maxpos; i >= maxed+1; i--)
         a[i] = a[i-1];
     a[maxed] = tmpmax;
     make_swap(x-(maxpos-maxed),maxed+1);
}
int main()
{
    cin >> x >> k;
    n = 0;
    while (x)
    {
          a[n++] = x%10;
          x/=10;
    }
    reverse(a,a+n);
    make_swap(k,0);
    for (i = 0; i < n; i++)
        cout << a[i];
    cout << endl;
    return 0;
}