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
ll i,j,x1,y1,x2,y2,n,k,k1,k2,m,y,x;
ll a[5005], dp[3][5005];
vector <ll> b;
map<ll,ll> was;
string s;
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
    cin >> n >> x >> y;
    if (y % n == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    y /= n;
    ll l = (n+1)/2;
    if (y == 0 || y%2 == 1)
    {
        if (x > -l && x < l)
        {
            if (y == 0)
               cout << 1 << endl;
            else
                cout << 2 + (y/2)*3 << endl;
        } else
        cout << -1 << endl;
        return 0;
    } else
    {
        if (x == 0)
           cout << -1 << endl;
        else
        if (x > -n && x < 0)
           cout << (y/2)*3 << endl;
        else
        if (x > 0 && x < n)
           cout << (y/2)*3 + 1 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}