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
#include <time.h>
#include <stack>
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
typedef long long ll;
using namespace std;
ll t,x,y,n,m,q,a[1005][1005],rows_b[1005][1005],rows_f[1005][1005],i,j,rez;
ll cols_b[1005][1005],cols_f[1005][1005];
int main()
{
    cin >> n >> m >> q;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d",&a[i][j]);
    for (i = 0; i < n; i++)
    {
        j = 0;
        while (j < m)
        {
              while (a[i][j] == 0 && j < m) j++;
              ll l = j;
              while (a[i][j] == 1 && j < m)
              {
                    rows_b[i][j] = l;
                    j++;
              }
        }
        j = m-1;
        while (j >= 0)
        {
              while (a[i][j] == 0 && j >= 0) j--;
              ll l = j;
              while (a[i][j] == 1 && j >= 0)
              {
                    rows_f[i][j] = l;
                    j--;
              }
        }
    }
    
    /*for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << rows_b[i][j] << " ";
        cout << endl;
    }   */
    
    for (i = 0; i < m; i++)
    {
        j = 0;
        while (j < n)
        {
              while (a[j][i] == 0 && j < n) j++;
              ll l = j;
              while (a[j][i] == 1 && j < n)
              {
                    cols_b[j][i] = l;
                    j++;
              }
        }
        j = n-1;
        while (j >= 0)
        {
              while (a[j][i] == 0 && j >= 0) j--;
              ll l = j;
              while (a[j][i] == 1 && j >= 0)
              {
                    cols_f[j][i] = l;
                    j--;
              }
        }
    }
    
    
    for (int k = 0; k < q; k++)
    {
        cin >> t;
        cin >> x >> y;
        x--; y--;
        if (t == 1)
        {
              a[x][y] ^= 1;
              i = x;
              j = 0;
                      while (j < m)
                {
                      while (a[i][j] == 0 && j < m) j++;
                            ll l = j;
                            while (a[i][j] == 1 && j < m)
                            {
                                  rows_b[i][j] = l;
                                        j++;
                                  }
                      }
                j = m-1;
                while (j >= 0)
                {
                      while (a[i][j] == 0 && j >= 0) j--;
                            ll l = j;
                            while (a[i][j] == 1 && j >= 0)
                            {
                                  rows_f[i][j] = l;
                                 j--;
                    }
               }
               
               i = y;
               j = 0;
        while (j < n)
        {
              while (a[j][i] == 0 && j < n) j++;
              ll l = j;
              while (a[j][i] == 1 && j < n)
              {
                    cols_b[j][i] = l;
                    j++;
              }
        }
        j = n-1;
        while (j >= 0)
        {
              while (a[j][i] == 0 && j >= 0) j--;
              ll l = j;
              while (a[j][i] == 1 && j >= 0)
              {
                    cols_f[j][i] = l;
                    j--;
              }
        }
        
        } else
        {
              if (a[x][y] == 0)
              {
                          cout << 0 << endl;
                          continue;
              }
              ll l = x,r = x,tmp = y-rows_b[x][y]+1;
              rez = y-rows_b[x][y]+1;
              //cout << rez << endl;
              while (a[r+1][y] == 1||a[l-1][y] == 1)
              {
               //cout << tmp << " " << rez << endl;
               if (a[r+1][y] == 0 || r == n-1)
               {
                l--;
                tmp = min(tmp,y-rows_b[l][y]+1);
               }
               else
               if (a[l-1][y] == 0 || l == 0)
               {
                r++;
                tmp = min(tmp,y-rows_b[r][y]+1);
               }
               else
               {
                if (rows_b[l-1][y] < rows_b[r+1][y])
                {
                   l--;                   
                   tmp = min(tmp,y-rows_b[l][y]+1);
                }
                else
                {
                    r++;
                    tmp = min(tmp,y-rows_b[r][y]+1);
                }
               }
               rez = max(rez,(r-l+1)*tmp);
              }
              
              
              l = x;r = x;tmp = rows_f[x][y]-y+1;
              rez = max(rez,rows_f[x][y]-y+1);
              //cout << rez << endl;
              while (a[r+1][y] == 1||a[l-1][y] == 1)
              {
               if (a[r+1][y] == 0 || r == n-1)
               {
                l--;
                tmp = min(tmp,rows_f[l][y]-y+1);
               }
               else
               if (a[l-1][y] == 0 || l == 0)
               {
                r++;
                tmp = min(tmp,rows_f[r][y]-y+1);
               }
               else
               {
                if (rows_f[l-1][y] > rows_f[r+1][y])
                {
                   l--;                   
                   tmp = min(tmp,rows_f[l][y]-y+1);
                }
                else
                {
                    r++;
                    tmp = min(tmp,rows_f[r][y]-y+1);
                }
               }
               rez = max(rez,(r-l+1)*tmp);
              }
              
              l = y;r = y;tmp = cols_f[x][y]-x+1;
              rez = max(rez,cols_f[x][y]-x+1);
              while (a[x][r+1] == 1||a[x][l-1] == 1)
              {
               if (a[x][r+1] == 0 || r == m-1)
               {
                l--;
                tmp = min(tmp,cols_f[x][l]-x+1);
               }
               else
               if (a[x][l-1] == 0 || l == 0)
               {
                r++;
                tmp = min(tmp,cols_f[x][r]-x+1);
               }
               else
               {
                if (cols_f[x][l-1] > cols_f[x][r+1])
                {
                   l--;                   
                   tmp = min(tmp,cols_f[x][l]-x+1);
                }
                else
                {
                    r++;
                    tmp = min(tmp,cols_f[x][r]-x+1);
                }
               }
               rez = max(rez,(r-l+1)*tmp);
              }
              
              l = y;r = y;tmp = x-cols_b[x][y]+1;
              rez = max(rez,x-cols_b[x][y]+1);
              while (a[x][r+1] == 1||a[x][l-1] == 1)
              {
               if (a[x][r+1] == 0 || r == m-1)
               {
                l--;
                tmp = min(tmp,x-cols_b[x][l]+1);
               }
               else
               if (a[x][l-1] == 0 || l == 0)
               {
                r++;
                tmp = min(tmp,x-cols_b[x][r]+1);
               }
               else
               {
                if (cols_b[x][l-1] < cols_b[x][r+1])
                {
                   l--;                   
                   tmp = min(tmp,x-cols_b[x][l]+1);
                }
                else
                {
                    r++;
                    tmp = min(tmp,x-cols_b[x][r]+1);
                }
               }
               rez = max(rez,(r-l+1)*tmp);
              }
              
              cout << rez << endl;
        }
    }
    return 0;
}