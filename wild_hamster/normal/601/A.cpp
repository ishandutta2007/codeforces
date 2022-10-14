#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 (33LL+(ll)1e+17)
#define INF (1+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 558228
typedef long long ll;
using namespace std;
ll l,i,j,n,k,k1,k2,k3,k4,k5,m,x1,y1,x2,y2,r,x,y,z,ans;
ll a[405][405], d1[405], d2[405], used[405];
vector <ll> f;
ll gcd(ll a, ll b)
{
    if (b == 0)
       return a;
    return gcd(b,a%b);
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            if (i != j)
               a[i][j] = 2;
            d1[i] = INF;
            d2[i] = INF;
        }
    cin >> m;
    for (i = 1; i <= m; i++)
    {
        scanf("%I64d %I64d",&x,&y);
        a[x][y] = a[y][x] = 1;
    }
    d1[1] = d2[1] = 0;
    for (i = 1; i <= n; i++)
        used[i] = 0;
    f.clear();
    f.push_back(1);
    i = 0;
    while (i < f.size())
    {
        ll v = f[i++];
        used[v] = 1;
        for (int j = 1; j <= n; j++)
            if (a[v][j] == 1 && !used[j])
            {
                used[j] = 1;
                f.push_back(j);
                d1[j] = d1[v] + 1;
            }
    }
    for (i = 1; i <= n; i++)
        used[i] = 0;
    f.clear();
    f.push_back(1);
    i = 0;
    while (i < f.size())
    {
        ll v = f[i++];
        used[v] = 1;
        for (int j = 1; j <= n; j++)
            if (a[v][j] == 2 && !used[j])
            {
                used[j] = 1;
                f.push_back(j);
                d2[j] = d2[v] + 1;
            }
    }
    ll ans = max(d1[n],d2[n]);
    if (ans == INF)
    {
        cout << -1 << endl;
    } else
      cout << ans << endl;
    return 0;
}