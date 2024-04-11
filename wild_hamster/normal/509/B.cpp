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
ll n,i,j,d,x,y,m,l,r,sum,a[1005];
double k,rez,tmp;
int main()
{
    cin >> n >> k;
    ll max1 = -1000, min1 = 1000;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        min1 = min(min1,a[i]);
        max1 = max(max1,a[i]);
    }
    if (k < max1 - min1)
    {
          cout << "NO" << endl;
          return 0;
    }
    cout << "YES" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < min1; j++)
            cout << 1 << " ";
        for (j = min1; j < a[i]; j++)
        {
            cout << j-min1+1;
            if (j != a[i] - 1)
               cout << " ";
        }
        cout << endl;
    }
    return 0;
}