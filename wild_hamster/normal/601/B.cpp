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
typedef int ll;
using namespace std;
ll l,i,j,n,k,k1,k2,k3,k4,k5,m,x1,y1,x2,y2,r,x,y,z,ans;
ll a[N], d1[405], d2[405], p[N], nxt[N], prv[N], val[N];
set <ll> f;
set <ll>::iterator itr;
pii g[N];
vector <pii> gg;
ll gcd(ll a, ll b)
{
    if (b == 0)
       return a;
    return gcd(b,a%b);
}
ll Abs(ll x)
{
    return x>0?x:-x;
}
int dsu_get (int v) {
    return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}

void dsu_unite (int a, int b) {
    a = dsu_get (a);
    b = dsu_get (b);
    if (rand() & 1)
        swap (a, b);
    if (a != b)
        p[a] = b;
}
int main()
{
    srand(time(0));
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll q;
    cin >> n >> q;
    for (i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }
    for (i = 1; i < n; i++)
    {
        gg.push_back(mp(Abs(a[i+1]-a[i]),i));
    }
    sort(gg.begin(),gg.end());
    for (i = 0; i < q; i++)
    {
        cin >> x >> y;
        ll sz = 0;
        for (j = 0; j < n-1; j++)
            if (gg[j].Y >= x && gg[j].Y < y)
               g[sz++] = gg[j];
        long long ans = 0;
        for (j = x; j < y; j++)
        {
            nxt[j] = j+1;
            val[j] = 1;
            p[j] = j;
        }
        val[y] = 1;
        p[y] = y;
        for (j = 0; j < sz; j++)
        {
            ll num = dsu_get(g[j].Y);
            ll val1 = val[num];
            ll tmp = dsu_get(nxt[num]);
            ll val2 = val[tmp];
            ll tmp_val = val[num] + val[tmp];
            nxt[num] = nxt[tmp];
            dsu_unite(num,tmp);
            val[dsu_get(num)] = tmp_val;
            ans += (long long)val1*val2*g[j].X;
        }
        cout << ans << endl;
    }
    return 0;
}