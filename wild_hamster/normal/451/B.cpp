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
ll m,i,n,j,a[300500],b[300500],x,y,z,rez;
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b,b+n);
    x = 0;
    while (a[x] == b[x])
          x++;
    y = n - 1;
    while (a[y] == b[y])
          y--;
    m = 1;
    if (y < x)
    {
          cout << "yes" << endl;
          cout << "1 1" << endl;
          return 0;
    }
    reverse(a+x,a+y+1);
    for (i = 0; i < n; i++)
        if (a[i]!=b[i]) m = 0;
    if (m)
    {
       cout << "yes" << endl;
       cout << x+1 << " " << y+1 << endl;
    }
    else
        cout << "no" << endl;
    return 0;
}