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
ll a[N], d1[405], d2[405], p[N], nxt[N], prv[N], val[N];
set <ll> f;
set <ll>::iterator itr;
pii g[N];
vector <pii> gg;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        cin >> r;
        x = x*m + r;
    }
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        cin >> r;
        y = y*m + r;
    }
    if (x < y)
       cout << "<" << endl;
    else
    if (x > y)
       cout << ">" << endl;
    else
        cout << "=" << endl;
    return 0;
}