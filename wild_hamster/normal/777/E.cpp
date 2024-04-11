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
#define SUM 377
#define MAG 33554431
#define RED 0
#define BLUE 1
#define eps 1e-7
#define N 200005
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,ans, curL, curR, SQ, P, Q, bad;
pair<pair<ll,ll>,ll> queries[100500];
ll a[600500], t[600500];
map<ll,ll> compr;
map<ll,ll>::iterator itr;
bool cmp(pair<pair<ll,ll>,ll> x, pair<pair<ll,ll>,ll> y)
{
    if (x.X.Y > y.X.Y)
        return true;
    if (x.X.Y < y.X.Y)
        return false;
    return (x.X.X > y.X.X);
}
void modify(int p, ll value) {
  for (t[p += N] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
}

ll query(int l, int r) {
  ll res = 0;
  for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res,t[l++]);
    if (r&1) res = max(res,t[--r]);
  }
  return res;
}
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
 	cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d %I64d %I64d",&x,&y,&z);
        queries[i] = mp(mp(x,y),z);
        compr[x] = compr[y] = 0;
    }
    i = 0;
    for (itr = compr.begin(); itr != compr.end(); itr++)
    {
        compr[(*itr).X] = i++;
    }
    sort(queries,queries+n,cmp);
    for (i = 0; i < n; i++)
    {
        x = compr[queries[i].X.X];
        y = compr[queries[i].X.Y];
        ll tmp = query(0, y);
        modify(x, tmp+queries[i].Y);
    }
    cout << query(0,N-1) << endl;
 	return 0;
}