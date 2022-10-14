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
#include <time.h>
#include <stack>
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
#define tr 1000000007
typedef long long ll;
using namespace std;
ll x1,y1,x2,y2,x,y,n,m,q,i,j,k,k1,k2,l,a[100500],used[50000];
double dp[5005][5005];
string s1,s2;

int main()
{
   cin >> n >> m;
   for (i = 0; i < n; i++)
   {
       cin >> x >> y;
       if (i == 0)
       {
             if (y == 1)
             dp[1][0] = 1;
             else
             {
             double tmp = x/100.;
             for (j = 0; j < y; j++)
                 if (j == 0) dp[i+1][j] = tmp;
             else
                 if (j!= y - 1)
                 dp[i+1][j] = dp[i+1][j-1]*(1.-tmp);
             else
                 if (tmp != 0)
                 dp[i+1][j] = dp[i+1][j-1]*(1.-tmp)/tmp;
             else
                 dp[i+1][j] = 1;
             }
       } else
       {
             double p = x/100.;
             double im = 0;
             for (j = i; j < min(i+y-1,m); j++)
             {
                 im = im*(1.-p)+dp[i][j-1]*p;
                 dp[i+1][j] += im;
             }
             double last = p;
             for (j = 0; j < y-2; j++)
                 last*=(1.-p);
             if (y > 1)
             for (j = i+y-1; j < m; j++)
             {
                 im -= last*dp[i][j-y];
                 im = im*(1.-p)+dp[i][j-1]*p;
                 //cout << im << endl;
                 dp[i+1][j] += im;
             }
             if (p == 0)
                last = 1;
             else
                 last*=(1.-p)/p;
             //cout << last << endl;
             if (y == 1) last = 1;
             //cout << last << endl;
             for (j = i; j < m; j++)
             {
                 if (j - y >= 0)
                    dp[i+1][j] += dp[i][j-y]*last;
             }             
       }
   }
   double rez = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < m; j++)
        {
        //cout << dp[i][j] << " ";
        rez += dp[i][j];
        }
        //cout << endl;
    }
    printf("%.10f\n",rez);
    //system("pause");
    return 0;
}