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
#define eps 1e-7
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,ans, curL, curR, SQ, P, Q;
string s, t, s1, t1;
ll a[500500], pa[500500];
map<ll,ll> f;
ll b[5005];
ll Abs(ll x)
{
    return x>0?x:-x;
}
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
    cin >> n >> k;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        pa[i+1] = pa[i] + a[i];
    for (i = 0; i <= n; i++)
        f[pa[i]]++;
    if (k == 1)
        b[sz++] = 1;
    else
    if (k == -1)
    {
        b[sz++] = 1;
        b[sz++] = -1;
    } else
    {
        b[sz++] = 1;
        x = 1;
        while (Abs(x) < (ll)1e+15)
        {
            x *= k;
            b[sz++] = x;
        }
    }
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j < sz; j++)
        {
            if (f.find(b[j]+pa[i]) != f.end())
                ans += f[b[j]+pa[i]];
        }
        f[pa[i]]--;
    }
    cout << ans << endl;
    return 0;
}