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
#define bull 500400
typedef long long ll;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,x1,x,y,y1,x2,y2,x3,y3,h,z,l1,l2,l3;
string s1,s2,s3,s,t;
pair<ll,ll> a[300500];
ll g[4005][4005],pw[4005];
ll b[300];
int main()
{
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> a[i].first >> a[i].second;
        x = a[i].first;
        y = a[i].second;
        g[x][y] = g[y][x] = 1;
        pw[x]++;
        pw[y]++;
    }
    ll sum = INF;
    for (i = 0; i < m; i++)
    {
        x = a[i].first;
        y = a[i].second;
        for (j = 1; j <= n; j++)
            if (g[x][j] == 1 && g[y][j] == 1)
               sum = min(sum,pw[x]+pw[y]+pw[j]-6);
    }
    if (sum == INF)
       cout << -1 << endl;
    else
        cout << sum << endl;
    return 0;
}