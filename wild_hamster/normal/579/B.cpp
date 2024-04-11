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
#define SQ 500400
#define CI 43534
typedef long long ll;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,x,y,l,r,z;
string s1,s2,s3,s,t;
vector<pair<ll,pair<ll,ll> > > f;
ll a[100500];
int main()
{
    cin >> n;
    for (i = 1; i <= 2*n-1; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cin >> x;
            f.push_back(mp(x,mp(i+1,j)));
        }
    }
    sort(f.begin(),f.end());
    reverse(f.begin(),f.end());
    for (i = 0; i < f.size(); i++)
    {
        ll x = f[i].second.first, y = f[i].second.second;
        if (!a[x] && !a[y])
           a[x] = y, a[y] = x;
    }
    for (i = 1; i <= 2*n; i++)
        cout << a[i] << " ";
    return 0;
}