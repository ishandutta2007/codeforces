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
ll x,y,n,m,k;

int main()
{
    cin >> n >> m >> k;
    if (k > n+m-2)
    {
          cout << -1 << endl;
          return 0;
    }   
    if (m > n)
       swap(m,n);
    if (k < m)
       cout << max((m/(k+1))*n,(n/(k+1))*m) << endl;
    else
    if (k < n)
       cout << (n/(k+1))*m << endl;
    else
        cout << max(m/(k-n+2),n/(k-m+2)) << endl;
    return 0;
}