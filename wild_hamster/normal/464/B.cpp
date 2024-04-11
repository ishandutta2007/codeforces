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
ll a[10][10],j,x,y,n,m,cnt,k,i,sixs[10],b[30];
map <ll,ll> f;
struct trio
{
       int x1,x2,x3;
};
ll sq(ll x)
{
 return x*x;
}

trio rez[10];
int main()
{
    ll tmp = 1;
    for (i = 0; i < 8; i++)
        for (j = 0; j < 3; j++)
            cin >> a[i][j];
     rez[7].x1 = a[7][0];     rez[7].x2 = a[7][1];     rez[7].x3 = a[7][2];

   
        sixs[0] = 1;
    for (i = 1; i <= 8; i++)
        sixs[i] = sixs[i-1]*6;

    bool rez1 = 0;
    for (i = 0; i < sixs[7]; i++)
    {
        for (j = 0; j < 7; j++)
        {
            ll tmp = (i/sixs[j])%6;
            if (tmp == 0) rez[j].x1 = a[j][0], rez[j].x2 = a[j][1], rez[j].x3 = a[j][2];
            if (tmp == 1) rez[j].x1 = a[j][0], rez[j].x2 = a[j][2], rez[j].x3 = a[j][1];
            if (tmp == 2) rez[j].x1 = a[j][1], rez[j].x2 = a[j][0], rez[j].x3 = a[j][2];
            if (tmp == 3) rez[j].x1 = a[j][1], rez[j].x2 = a[j][2], rez[j].x3 = a[j][0];
            if (tmp == 4) rez[j].x1 = a[j][2], rez[j].x2 = a[j][0], rez[j].x3 = a[j][1];
            if (tmp == 5) rez[j].x1 = a[j][2], rez[j].x2 = a[j][1], rez[j].x3 = a[j][0];
        }
        bool z = true;
        ll cnt = 0, k1 = 0, k2 = 0, k3 = 0;
        ll min1 = (ll)1e+15;
        for (k = 1; k < 6; k++)
            min1 = min(min1,sq(rez[k].x1-rez[0].x1)+ sq(rez[k].x2-rez[0].x2)
               +sq(rez[k].x3-rez[0].x3));
        for (j = 0; j < 8; j++)
           for (k = j+1; k < 8; k++)   
           {   
               b[cnt] = sq(rez[k].x1-rez[j].x1)+ sq(rez[k].x2-rez[j].x2)
               +sq(rez[k].x3-rez[j].x3);
               if (b[cnt] == 0) z = false;
               if (b[cnt] == min1) k1++;
               if (b[cnt] == min1*2LL) k2++;
               if (b[cnt] == min1*3LL) k3++;
               cnt++;
           }
       
      //  cout << k1 << " " << k2 << " " << k3 << endl;
       
        
        if (k1 == 12 && k2 == 12 && k3 == 4)
        {
              cout << "YES" << endl;
              for (j = 0; j < 8; j++)
                  cout << rez[j].x1 << " " << rez[j].x2 << " " 
                  << rez[j].x3 << endl; 
              rez1 = 1;
              break;
        }
    }    
    if (!rez1) cout << "NO" << endl;
    return 0;
}