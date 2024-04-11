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
ll n,m,j,p,a[100500],l,r,h,x,y,k1,k2,k3,k4,k5,k,i,w,rez,b[100500];
ll f[3][400500], itr;

int main()
{
   cin >> n >> m;
   rez = 0;
   for (i = 1; i < 1500; i++)
   {
       rez += i;
       if (rez + i + 1 > n+m) break;
   }
   rez = 0;
   h = i;
   f[0][n] = 1;
   ll tmp = 0;
   for (i = 0; i < h; i++)
   {
       j = h - i;
       //cout << f[i].size() << endl;
       for (itr = 0; itr != 200001; itr++)
           f[(i+1)%2][itr] = 0;
       for (itr = 0; itr != 200001; itr++)
       {
           x = itr; y = n+m-itr-tmp;
           if (x >= j)
           {
              f[(i+1)%2][x - j] += f[i%2][x];
              if (f[(i+1)%2][x - j] >= tr)
                 f[(i+1)%2][x - j] -= tr;
           }
           if (y >= j)
           {
              f[(i+1)%2][x] += f[i%2][x];
              if (f[(i+1)%2][x] >= tr)
                f[(i+1)%2][x] -= tr ;
           }
       }
       tmp += j;
              
   }
   for (itr = 0; itr!=200001; itr++)
   {
       rez = (rez + f[h%2][itr])%tr;
   }
   cout << rez << endl;
   return 0;
}