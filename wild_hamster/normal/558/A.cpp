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
vector <pair<ll,ll> > f1,f2;
pair<ll,ll> a[100500];
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
    ll dod = 0, vid = 0;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (x > 0)
        {
           dod++;
           f1.push_back(mp(x,y));
        }
        else
        {
            vid++;
            f2.push_back(mp(-x,y));
        }
    }
    sort(f1.begin(),f1.end());
    sort(f2.begin(),f2.end());
    if (dod == vid)
    {
        ll sum = 0;
        for (i = 0; i < f1.size(); i++)
            sum += f1[i].second;
        for (i = 0; i < f2.size(); i++)
            sum += f2[i].second;
        cout << sum << endl;
    } else
    if (dod > vid)
    {
        ll sum = 0;
        for (i = 0; i < vid+1; i++)
            sum += f1[i].second;
        for (i = 0; i < f2.size(); i++)
            sum += f2[i].second;
        cout << sum << endl;
    } else
    {
        ll sum = 0;
        for (i = 0; i < f1.size(); i++)
            sum += f1[i].second;
        for (i = 0; i < dod+1; i++)
            sum += f2[i].second;
        cout << sum << endl;
    }
    return 0;
}