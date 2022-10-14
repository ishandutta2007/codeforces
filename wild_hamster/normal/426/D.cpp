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
ll a[300][300],b[300],c[300],z,cnt,tmp,l,r,n,m,x,y,k,j,p,k1,k2,i,cur,rez;
vector <ll> f;

ll Abs(ll x)
{
 if (x < 0) return -x;
 return x;
}

int main()
{
    cin >> n >> m >> k;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];
    if (n <= k)
    {          
          ll rez = n*m;
          for (i = 0; i < (1<<n); i++)
          {
              ll sum = 0;
              for (j = 0; j < n; j++)
                  if (i&(1<<j)) b[j] = 1;
                     else b[j] = 0;
              for (j = 0; j < m; j++)
              {
                  ll tmp = 0;
                  for (y = 0; y < n; y++)
                      tmp += (b[y]^a[y][j]);
                  tmp = min(tmp,n-tmp);
                  sum += tmp;   
              }
              rez = min(rez,sum);
          }
          if (rez <= k) cout << rez << endl;
             else cout << -1 << endl;
    } else
    {
          rez = m*n;
          for (i = 0; i < m; i++)
          {
              ll sum = 0;
              for (j = 0; j < n; j++)
                  b[j] = a[j][i];
              for (j = 0; j < m; j++)
              {
                  ll tmp = 0;
                  for (y = 0; y < n; y++)
                      tmp += (b[y]^a[y][j]);
                  tmp = min(tmp,n-tmp);
                  //cout << i << " " << j << " " << tmp << endl;
                  sum += tmp;    
              }
              rez = min(rez,sum);
          }
          //cout << rez << endl;
          if (rez <= k) cout << rez << endl;
             else cout << -1 << endl;
    }
   return 0;
}