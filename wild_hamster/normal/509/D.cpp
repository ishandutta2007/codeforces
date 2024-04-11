#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,i,j,k,d,x,y,m,len,r,sum,a[1005][1005],b[1005];
int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            cin >> a[i][j];
            r = max(r,a[i][j] + 1);
        }
    ll ost = -1;
    for (i = 0; i < n; i++)
        for (j = i+1; j < n; j++)
    {
        ll tmp1 = 1, tmp2 = -1;
        for (k = 0; k < m; k++)
        {
            b[k] = a[j][k] - a[i][k];
            if (b[k] < 0 && tmp1 == 1)
               tmp1 = b[k];
            if (b[k] >= 0 && tmp2 == -1)
               tmp2 = b[k];
            if (b[k] >= 0 && tmp2 >= 0 && b[k]!=tmp2)
            {
                     cout << "NO" << endl;
                     return 0;
            }
            
            if (b[k] < 0 && tmp1 < 0 && b[k]!=tmp1)
            {
                     cout << "NO" << endl;
                     return 0;
            }
        }
        if (tmp1 < 0&&tmp2 > 0&&tmp2 - tmp1 < r)
        {
         cout << "NO" << endl;
         return 0;
        }
        if (tmp1 < 0&&tmp2 > 0&&ost == -1)
           ost = tmp2 - tmp1;
        if (tmp1 < 0&&tmp2 > 0&&ost != -1&&ost!=tmp2-tmp1)
        {
         cout << "NO" << endl;
         return 0;
        }
    }
    if (ost == -1) ost = r;
    cout << "YES" << endl;
    cout << ost << endl;
    cout << 0 << " ";
    for (i = 1; i < n; i++)
    {
        cout << (a[i][0] - a[0][0] + ost)%ost;
        if (i != n-1) cout << " ";
    }
    cout << endl;
    for (i = 0; i < m; i++)
    {
        cout << a[0][i];
        if (i != m-1) cout << " ";
    }
    cout << endl;
    return 0;
}