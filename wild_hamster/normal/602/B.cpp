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
ll a[N], lst[N];
set <ll> f;
set <ll>::iterator itr;
pii g[N];
vector <pii> gg;
ll Abs(ll x)
{
    return x>0?x:-x;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    i = 0; l = 0; m = a[0]; k = a[0]; lst[m] = 0;
    while (i < n)
    {
        i++;
        lst[a[i]] = i;
        if (i == n)
           break;
        if (a[i] > m && a[i]-k >= 2)
        {
            ans = max(ans,i-l);
            if (a[i] - m > 1)
            {
                l = i;
                k = a[i];
                m = a[i];
            } else
            if (a[i] - m == 1)
            {
                l = max(l,lst[m-1]+1);
                k = m;
                m = a[i];
            }
        }
        if (a[i] < k && m - a[i] >= 2)
        {
            ans = max(ans,i-l);
            if (k - a[i] > 1)
            {
                l = i;
                k = a[i];
                m = a[i];
            } else
            if (k - a[i] == 1)
            {
                l = max(l,lst[k+1]+1);
                m = k;
                k = a[i];
            }
        }
        m = max(m,a[i]);
        k = min(k,a[i]);
    }
    ans = max(ans,i-l);
    cout << ans << endl;
    return 0;
}