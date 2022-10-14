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
#include <fstream>
#include <queue>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF ((ll)1e+15)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
typedef long long ll;
using namespace std;
ll minor[10][10],i,j,x1,y1,x2,y2,n,k,k1,k2,m,y,x,p;
string s;
ll a[100500],b[1000500],min1[1005000],max1[1005000];
ll Abs(ll x)
{
    if (x < 0)
       return -x;
    return x;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
       return a;
    return gcd(b,a%b);
}

int main()
{
    cin >> n;
    for (i = 1; i <= 1000000; i++)
        min1[i] = INF;
    ll mmax = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        b[a[i]]++;
        mmax = max(mmax,b[a[i]]);
        min1[a[i]] = min(min1[a[i]],i);
        max1[a[i]] = max(max1[a[i]],i);
    }
    ll min_dist = INF;
    ll l,r;
    for (i = 1; i <= 1000000; i++)
        if (b[i] == mmax)
        {
            if (max1[i] - min1[i] < min_dist)
            {
                min_dist = max1[i] - min1[i];
                l = min1[i];
                r = max1[i];
            }
        }
    cout << l+1 << " " << r+1 << endl;
    return 0;
}