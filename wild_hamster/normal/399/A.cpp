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
ll n,i,j,d,m,x,y,p,k,max1,a[100500];

int main()
{
    cin >> n >> p >> k;
    if (p - k > 1)
    {
          cout << "<< ";
          for (i = p-k; i < p; i++)
              cout << i << " ";
    } else
    {
          for (i = 1; i < p; i ++)
              cout << i << " ";
    }
    cout << "(" << p << ") ";
    if (p+k < n)
    {
            for (i = p+1; i <= p+k; i++)
                cout << i << " ";
            cout << ">>";
    } else
    {
            for (i = p+1; i <= n; i++)
                cout << i << " ";
    }
    return 0;
}