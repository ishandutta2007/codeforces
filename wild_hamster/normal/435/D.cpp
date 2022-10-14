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
ll a[805][805],i,j,n,m,k,min1,max1;
ll maindiag[900][900],diag[900][900],row[900][900],col[900][900];
void rotateon90()
{
     for (int i = 0; i < n; i++)
         for (int j = i+1; j < n; j++)
             swap(a[i][j],a[j][i]);
     for (int i = 0; i < n; i++)
         for (int j = 0; j < n/2; j++)
             swap(a[i][j],a[i][n-j-1]);
}
ll calc()
{
 ll i,j,k;
 for (i = 0; i < 850; i++)
     for (j = 0; j < 850; j++)
         maindiag[i][j] = diag[i][j] = row[i][j] = col[i][j] = 0;
 for (i = 0; i < n; i++)
 {
     row[i][0] = 0;
     for (j = 1; j <= 2*n; j++)
     row[i][j] = row[i][j-1] + a[i][j-1];
 }
 for (i = 0; i < n; i++)
 {
     col[i][0] = 0;
     for (j = 1; j <= 2*n; j++)
     col[i][j] = col[i][j-1] + a[j-1][i];
 }
 for (i = 0; i <= 2*n - 2; i++)
 {
     diag[i][0] = 0;
     for (j = 1; i-j+1 >= 0; j++)
         diag[i][j] = diag[i][j-1] + a[i-j+1][j-1];
 }
 for (i = -410; i <= n; i++)
 {
     maindiag[i+410][0] = 0;
     for (j = 1; i+j-1 <= n; j++)
     if (i+j-1>=0)
         maindiag[i+410][j] = maindiag[i+410][j-1] + a[i+j-1][j-1];
 }
 ll rez = 0;
 for (i = 0; i < n; i++)
     for (j = 0; j < n; j++)
         for (k = j+1; k < n; k++)
         {
             if (row[i][k+1]-row[i][j] == 0 && col[j][i+k-j+1]-col[j][i] == 0&& 
              diag[i+k][k+1]-diag[i+k][j] == 0)
                rez++;
             if ((k-j)%2 == 0 && row[i][k+1]-row[i][j] == 0 &&
             maindiag[i-j+410][j+(k-j)/2+1]-maindiag[i-j+410][j] == 0 &&
             diag[i+k][k+1]-diag[i+k][j+(k-j)/2] == 0) rez++;
         }
 return rez;
}
int main()
{
    cin >> n >> m;
    for (i = 0; i < 805; i++)
        for (j = 0; j < 805; j++)
            a[i][j] = 1;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == '0')
            a[i][j] = 0;
        }
    n = max(n,m);
    ll rez = 0;
    for (i = 0; i < 4; i++)
    {
    rez += calc();
    rotateon90();
  /*  for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
            cout << a[x][y];
        cout << endl;
    }*/
   }
   cout << rez << endl;
    return 0;
}