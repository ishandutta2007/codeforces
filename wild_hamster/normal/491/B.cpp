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
#include <time.h>
#include <stack>
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
typedef long long ll;
using namespace std;
ll n,l,r,j,k,m,y,x,v,a[3005],b[10],rez,h,i,cnt;
ll Abs(ll x)
{
 if (x < 0) return -x;
 return x;
}
int main()
{
    cin >> x >> y;
    ll min2,max2;
    ll min1 = min2 = (ll)1e+18, max1 = max2 = -(ll)1e+18;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        min1 = min(min1,x+y);
        max1 = max(max1,x+y);
        min2 = min(min2,x-y);
        max2 = max(max2,x-y);
    }
    cin >> m;
    rez = (ll)1e+18;
    j = 0;
    //cout << min1 << " " << max1 << endl;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y;
        ll tmp = max(max(Abs(x+y-min1),Abs(x+y-max1)),max(Abs(x-y-min2),Abs(x-y-max2)));
        if (rez > tmp) 
        {
                rez = tmp;
                j = i+1;
        }
    }
    cout << rez << endl << j << endl;
    return 0;
}