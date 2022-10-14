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
ll n,l,r,j,k,x1,x2,y1,y2,m,y,v,a[100005],flag,rez,h,i,cnt,used[100005];
vector <ll> f,g;
int main()
{
    cin >> n;
    if (n == 1)
    {
          cout << "YES" << endl;
          cout << 1 << endl;
          return 0;
    }
    if (n == 3)
    {
          cout << "YES" << endl;
          cout << 1 << endl << 2 << endl << 3 << endl;
          return 0;
    }
    if (n == 4)
    {
          cout << "YES" << endl;
          cout << 1 << endl << 3 << endl << 2 << endl << 4 << endl;
          return 0;
    }
    for (i = 2; i < n; i++)
    if (n%i == 0)
    {
            cout << "NO" << endl;
            return 0;
    }
    srand(time(0));
    i = 0;
    while (1)
    {
          f.clear();
          ll k = 1;
          f.push_back(1);
          ll t = rand()%(n-1)+1;
          i++;
          for (j = 0; j < n-2; j++)
          {
              k=(k*t)%n;
              if (k!=0&&used[k]!=i)
              {
                 f.push_back(k);
                 used[k] = i;
              }
          }
          if (f.size() == n-1)
             break;
    }
    g.push_back(0);
    for (i = 0; i < n-2; i++)
    {
        if (i%2==0) g.push_back((i/2)*2+1);
           else g.push_back(n-3-(i/2)*2);
    }
    cout << "YES" << endl;
    for (i = 0; i < g.size(); i++)
        cout << f[g[i]] << endl;
    cout << n << endl;
    return 0;
}