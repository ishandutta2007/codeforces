#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define mp make_pair 
#define INF ((ll)1e+9)
typedef unsigned long long ull;
typedef long long ll;
ll i,n,j,k,x,y,z,m,l,r,a[228228],b[10],c[10];
string s;

int main()
{
    cin >> n;
    ll ans = 0;
    m = n;
    i = 0;
    while (m)
    {
     ans = max(ans,m%10);
     c[i++] = m%10;
     m/=10;
    }
    cout << ans << endl;
    b[0] = 1;
    for (i = 0; i < ans; i++)
    {
        ll flag = 0;
        for (j = 7; j >= 0; j--)
        if (c[j] > 0)
        {
         cout << 1;
         c[j]--;
         flag = 1;
        } else
        if (flag)
           cout << 0;
        cout << " ";
    }
    return 0;
}