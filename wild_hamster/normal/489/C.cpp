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
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
typedef long long ll;
using namespace std;
ll n,l,r,j,k,m,y,x,v,a[100005],b[100005],flag,rez,h,i,cnt,used[100005];
ll Abs(ll x)
{
          if (x < 0) return -x;
          return x;
}
int main()
{
    cin >> n >> m;
    if (n == 1&&m == 0)
    {
          cout << "0 0" << endl;
          return 0;
    }
    if (n*9 < m||m == 0)
    {
            cout << -1 << " " << -1 << endl;
            return 0;
    }
    rez = m;
    for (i = 0; i < n; i++)
    {
        if ((n-i-1)*9 >= rez)
        {
         if (i > 0) cout << 0;
         else
         {
         cout << 1;
         rez--;
         }
        } else
        {
         cout << rez - (n-i-1)*9;
         rez = (n-i-1)*9;
        }
    }
    cout << " ";
    rez = m;
    for (i = 0; i < n; i++)
    {
        if (rez >= 9)
        {
           cout << 9;
           rez-=9;
        } else
        {
        cout << rez;
        rez = 0;
        }
    }
    return 0;
}