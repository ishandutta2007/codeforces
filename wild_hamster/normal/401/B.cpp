#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
ll i,j,n,rez,y,z,a[100500],x,k;
int main()
{
    cin >> x >> k;
    for (i = 0; i < k; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
           cin >> y >> z;
           a[y] = 1;
           a[z] = 1;
        } else
        {
         cin >> y;
         a[y] = 1;
        }
    }
    ll min1 = 0, max1 = 0;
    for (i = 1; i < x; i++)
        if (a[i] == 0) max1++;
    for (i = 1; i < x; i++)
        if (a[i] == 0)
        {
         if (i < x-1 && a[i+1] == 0)
            i++;
         min1++;
        }
    cout << min1 << " " << max1 << endl;
    return 0;
}