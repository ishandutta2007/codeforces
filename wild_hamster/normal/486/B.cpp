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
ll n,l,r,i,j,k,x,m,y,v,rez,a[105][105],cols[105],rows[105],b[105][105],c[105][105];
vector <ll> lalka1,lalka2;

int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];
    for (i = 0; i < n; i++)
    {
        ll z = 1;
        for (j = 0; j < m; j++)
            if (a[i][j] == 0)
               z = 0;
        if (z) cols[i] = 1;
    }
    for (i = 0; i < m; i++)
    {
        ll z = 1;
        for (j = 0; j < n; j++)
            if (a[j][i] == 0)
               z = 0;
        if (z) rows[i] = 1;
    }
    ll flag = 1;    
    for (i = 0; i < n; i++)
          for (j = 0; j < m; j++)
          if (cols[i] == 1&&rows[j] == 1)
             c[i][j] = 1;
             
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        if (c[i][j])
        {        
        for (k = 0; k < m; k++)
            b[i][k] = 1;
            
        for (k = 0; k < n; k++)
            b[k][j] = 1;
        }
      
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        if (a[i][j]!=b[i][j])
           flag = 0;
    if (!flag)
    {
              cout << "NO" << endl;
    } else
    {
      cout << "YES" << endl;
      for (i = 0; i < n; i++)
      {
          for (j = 0; j < m; j++)
              cout << c[i][j] << " ";
          cout << endl;          
      }
    }
    return 0;
}