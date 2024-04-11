#include <iostream>
#include <cmath>
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
ll a[200][200],b[200][200],z,cnt,tmp,l,r,n,m,x,y,k,j,p,k1,k2,i,cur,rez;
vector <ll> f;
ll Abs(ll x)
{
 if (x < 0) return -x;
 return x;
}

int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];
    z = 1;
    f.push_back(n);
    while (n%2 == 0)
    {
          f.push_back(n/2);
          n/=2;
    }
    n = f[0];
    sort(f.begin(),f.end());
    for (k = 0; k < f.size(); k++)
    {
     x = f[k];
     for (i = 0; i < x; i++)
        for (j = 0; j < m; j++)
            b[i][j] = a[i][j];
     while (x!=n)
     {
           for (i = 0; i < x; i++)
               for (j = 0; j < m; j++)
                   b[2*x-1-i][j] = b[i][j];
           x*=2;
     }
     z = 1;
     /*for (i = 0; i < n; i++)
     {
        for (j = 0; j < m; j++)
        cout << b[i][j] << " ";
             cout << endl;
     }*/
     for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        if (a[i][j]!=b[i][j]) z = 0;
     if (z)
     {
        cout << f[k] << endl;
        break;
     }
    }
   return 0;
}