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
ll dp[3][5005];
pair <ll,string> a[100500];
vector<pair<ll,string> > f,g;
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
    for (i = 0; i < n; i++)
        cin >> a[i].second >> a[i].first;
    sort(a,a+n);
    for (i = 0; i < n; i++)
    {
        x = a[i].first;
        if (x > f.size())
        {
            cout << -1 << endl;
            return 0;
        }
        for (j = 0; j < x; j++)
            g.push_back(f[j]);
        g.push_back(a[i]);
        for (j = x; j < f.size(); j++)
            g.push_back(f[j]);
        f.clear();
        for (j = 0; j < g.size(); j++)
            f.push_back(g[j]);
        g.clear();
    }
    for (i = 0; i < f.size(); i++)
        cout << f[i].second << " " << 10000-f[i].first << endl;
    return 0;
}