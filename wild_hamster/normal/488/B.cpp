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
ll n,l,r,j,k,m,y,x,v,a[3005],b[10],rez,h,i,cnt;
bool lalka(int x)
{
     if (x < 0) x = -x;
     while (x)
     {
           if (x%10 == 8) return true;
           x/=10;
     }
     return false;
}
vector <ll> f[5];
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    if (n == 0)
    {
       cout << "YES" << endl << 1 << endl << 1 << endl << 3 << endl << 3 << endl;
       return 0;
    }
    for (i = 1; i <= 500; i++)
        for (j = i; j <= 2*i; j++)
        {
         f[0].pb(i);
         f[1].pb(j);
         f[2].pb(4*i-j);
         f[3].pb(3*i);
        }
    for (i = 0; i < f[0].size(); i++)
    {
        ll flag = 1;
        for (j = 0; j < n; j++)
        {
            ll z = 1;
            for (k = 0; k < 4; k++)
            if (a[j] == f[k][i])
            {
               z = 0;
               f[k][i] = -1;
               break;
            }
            if (z) flag = 0;
        }
        if (flag)
        {
           cout << "YES" << endl;
           for (k = 0; k < 4; k++)
           if (f[k][i]!=-1)
              cout << f[k][i] << endl;
           return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}