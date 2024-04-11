#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#define tr 1000000007
#define mp make_pair
typedef long long ll;
using namespace std;
ll i,n,a[300500],max1,min1,x,y;
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    max1 = min1 = a[0];
    for (i = 1; i < n; i++)
        max1 = max(max1,a[i]), min1 = min(min1,a[i]);
    for (i = 0; i < n; i++)
    {
        if (a[i] == min1) x++;
        if (a[i] == max1) y++;
    }
    if (min1 == max1)
    cout << 0 << " " << (x*(x-1))/2 << endl;
    else
    cout << max1 - min1 << " " << x*y << endl;
    return 0;
}