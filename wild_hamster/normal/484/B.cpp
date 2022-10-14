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
#define PI 3.14159265358979323846
typedef long long ll;
using namespace std;
ll n,l,r,i,j,k,x,m,y,v,a[204000],pos[1005000],used[1005000],rez;
vector <ll> f;

int main()
{
    cin >> m;
    n = 0;
    for (i = 0; i < m; i++)
    {
        cin >> x;
        if (!used[x])
        {
         used[x] = 1;
         a[n++] = x;
        }
      }
      sort(a,a+n);
      rez = 0;
      j = 0;
     for (i = 0; i < n; i++)
     {
         while (j <= a[i])
               pos[j++] = i;
     }
     for (i = n-1; i >= 1; i--)
     {
         if (rez > 0)
         for (j = 2; j <= a[i]/rez; j++)
         {
          l = pos[a[i]/j+1];
           if (l < n && a[l] <= a[i] && l >= 0)
               rez = max(rez,a[i]%a[l]);
         } else
         for (j = 2; j <= a[i]; j++)
         {
          l = pos[a[i]/j+1];
           if (l < n && a[l] <= a[i] && l >= 0)
               rez = max(rez,a[i]%a[l]);
         }
     }
     cout << rez << endl;
    return 0;
}