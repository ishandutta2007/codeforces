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
#include <assert.h>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 1000000009
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 131072
#define SUM 377
#define MAG 33554431
#define RED 0
#define BLUE 1
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,c,ans, curL, curR, SQ;
ll a[100500];
pair<pii,ll> queries[300500];
ll res[300500];
vector<ll> f[100500];
ll t[400500], t1[400500];
ll compr[100500];
map<ll,ll> g;
map<ll,ll>::iterator itr;
vector<ll> fn;

void modify(int p, int value) {  // set value at position p
    p += n;
    t[p] = min(t[p], value);
  for (; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = MOD;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(res, t[l++]);
    if (r&1) res = min(res, t[--r]);
  }
  return res;
}

void modify1(int p, int value) {  // set value at position p
  for (t1[p+=n] = value; p > 1; p >>= 1) t1[p>>1] = min(t1[p], t1[p^1]);
}

int query1(int l, int r) {  // sum on interval [l, r)
  int res = MOD;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(res, t1[l++]);
    if (r&1) res = min(res, t1[--r]);
  }
  return res;
}

void make_magic()
{
    for (i = 0; i <= 2*n; i++)
        t[i] = t1[i] = MOD;
    g.clear();
    fn.clear();
    for (i = 0; i < n; i++)
    {
        g[a[i]] = 0;
        f[i].clear();
    }
    i = 0;
    for (itr = g.begin(); itr != g.end(); itr++)
    {
        g[(*itr).X] = i++;
        fn.push_back((*itr).X);
    }
    ll sz = i;
    for (i = 0; i < n; i++)
    {
        compr[i] = g[a[i]];
    }
    for (i = n-1; i >= 0; i--)
    {
        ll cur = compr[i];
        ll tmp = query1(cur, sz);
        if (tmp == MOD)
        {
            modify1(compr[i], i);
            continue;
        }
        f[i].push_back(tmp);
        if (a[i] == a[tmp])
        {
            modify1(compr[i], i);
            continue;
        }
        ll border = (a[i] + a[tmp])/2;
        while (1)
        {
            ll pos = upper_bound(fn.begin(), fn.end(), border) - fn.begin();
            ll tmp = query1(cur, pos);
            if (tmp == MOD)
                break;
            f[i].push_back(tmp);
            if (a[i] == a[tmp])
                break;
            border = (a[i] + a[tmp])/2;
        }
        modify1(compr[i], i);
    }
    ll cur = n-1;
    for (i = 0; i < m; i++)
    {
        x = queries[i].X.X, y = queries[i].X.Y;
        while (cur >= x)
        {
            for (j = 0; j < f[cur].size(); j++)
            {
                modify(f[cur][j], a[f[cur][j]]-a[cur]);
            }
            cur--;
        }
        res[queries[i].Y] = min(res[queries[i].Y], query(x, y+1));
    }
}

int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
    cin >> n;
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]);
    cin >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d %d",&queries[i].X.X, &queries[i].X.Y);
        queries[i].X.X--;
        queries[i].X.Y--;
        queries[i].Y = i;
        res[i] = MOD;
    }
    sort(queries,queries+m);
    reverse(queries, queries+m);

    make_magic();
    for (i = 0; i < n; i++)
        a[i] = MOD-7-a[i];
    make_magic();

    for (i = 0; i < m; i++)
        printf("%d\n", res[i]);
    return 0;
}