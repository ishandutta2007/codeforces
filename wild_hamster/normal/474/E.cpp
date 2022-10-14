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
ll n,i,j,d,max1,a[100500],tmp,c[100500];
pair<ll,ll> b[100500];
vector <ll> f;
ll Abs(ll x)
{
 if (x < 0)
    return -x;
 return x;
}
int main()
{
    cin >> n >> d;
    for (i = 0; i < n; i++)
        cin >> a[i];
    max1 = 1;
    b[1].first = b[1].second = a[0];
    c[0] = 1;
    for (i = 1; i < n; i++)
    {
        if (a[i] >= b[max1].first + d||a[i] <= b[max1].first - d||a[i] >= b[max1].second + d||a[i] <= b[max1].second - d)
        {
            max1++;
            tmp = i+1;
            b[max1].first = b[max1].second = a[i];
            c[i] = max1;
        } else
        if (max1 == 1 || a[i] >= b[max1-1].first + d||a[i] <= b[max1-1].first - d||a[i] >= b[max1-1].second + d||a[i] <= b[max1-1].second - d)
        {           
            if (a[i] > b[max1].second) b[max1].second = a[i],c[i] = max1;
            if (a[i] < b[max1].first) b[max1].first = a[i],c[i] = max1;
        } else
        {
        if (max1 < 2) continue;
        if (max1 <= 2 || a[i] >= b[max1-2].first + d||a[i] <= b[max1-2].first - d||a[i] >= b[max1-2].second + d||a[i] <= b[max1-2].second - d)
        {           
            if (a[i] > b[max1-1].second) b[max1-1].second = a[i],c[i] = max1 - 1;
            if (a[i] < b[max1-1].first) b[max1-1].first = a[i],c[i] = max1 - 1;
        }
        }
    }
    cout << max1 << endl;
    f.push_back(tmp);
    ll start = tmp-1;
    n = start;
    for (i = n; i >= 0; i--)
        if (c[i] == max1 - 1&&Abs(a[i]-a[start]) >= d)
        {
         f.push_back(i+1);
         max1--;
         start = i;
        }
    reverse(f.begin(),f.end());
    for (i = 0; i < f.size(); i++)
        cout << f[i] << " ";
    return 0;
}