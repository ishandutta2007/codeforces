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
    cin >> n;
    ll ans = 0;
    for (i = 2; i < n; i++)
    {
        x = n;
        while (x)
        {
            ans += x%i;
            x /= i;
        }
    }
    ll g = gcd(n-2,ans);
    cout << ans/g << "/" << (n-2)/g << endl;
    return 0;
}