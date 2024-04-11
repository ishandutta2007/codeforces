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
ll a[1005],b[1005][1005],i,j,n,k,min1,max1;
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    k = min1 = max1 = 0;
    for (i = 0; i < n; i++)
    {
        if (i%2 == 0) k-= a[i] - 1;
        else k += a[i] - 1;
        min1 = min(min1,k);
        max1 = max(max1,k);
    }
    ll tmp = -min1;
    ll cnt = 0;
    for (i = 0; i < n; i++)
    {
        if (i%2 == 0) tmp++;
           else tmp--;
        for (j = 0; j < a[i]; j++)
        {
            if (i%2 == 0)
            {
             tmp--;
             b[cnt++][tmp] = 1;
            }
            else
            {
             tmp++;
             b[cnt++][tmp] = 2;
            }
        }
    }
    for (i = 0; i <= max1-min1; i++)
    {
        for (j = 0; j < cnt; j++)
            if (b[j][i] == 0)
               cout << " ";
            else
            if (b[j][i] == 1)
               cout << "/";
            else
                cout << (char)92;
            cout << endl;
    }
    return 0;
}