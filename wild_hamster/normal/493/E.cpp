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
ll n,l,r,j,k,m,y,x,v,a[200505],b[200500],rez,h,i,cnt,last;
vector <ll> f1,f2;
int main()
{
    cin >> n >> x >> y;
    if (n == 1 && x == 1 && y == 1)
    {
          cout << "inf" << endl;
          return 0;
    }
    if ((n == 1 && x == 1))
    {
          cout << 0 << endl;
          return 0;
    }
    if (n == 1)
    {
          if (x == y)
          {
                cout << 1 << endl;
                return 0;
          }
          if (y == 1)
          {
                cout << 0 << endl;
                return 0;
          }
         while (y)
         {
          f1.push_back(y%x);
          y /= x;
         } 
         ll sum = 0;
         for (i = 0; i < f1.size(); i++)
             sum += f1[i];
         if ((sum == x && f1[0] == 1 && f1[f1.size() - 1] == x-1) || sum == 1)
            cout << 1 << endl;
         else
             cout << 0 << endl;
         return 0;
    }
    if (x == 1)
    {
          if (y == 1)
             cout << 1 << endl;
          else
              cout << 0 << endl;
          return 0;
    }
    if (x == y) rez++;
    while (y)
    {
          f1.push_back(y%x);
          y /= x;
    }
    while (x)
    {
          f2.push_back(x%n);
          x /= n;
    }
    bool flag = true;
    if (f1.size() != f2.size())
       flag = false;
    else
    for (i = 0; i < f1.size(); i++)
        if (f1[i] != f2[i])
           flag = false;
    if (flag) rez++;
    cout << rez << endl;
    return 0;
}