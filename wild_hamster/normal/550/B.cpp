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
typedef int ll;
using namespace std;
ll i,j,n,p,m,k,k1,k2,y,x,xs,ys,zs,xf,yf,zf,x1,y1,x2,y2,x3,y3,ans,kk,l,r;
string s;
ll a[30];
vector <ll> f;
ll Abs(ll x)
{
    return x>0?x:-x;
}
int main()
{
    //cout << C(29,15) << endl;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> l >> r >> x;
    for (i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    for (i = 0; i < (1<<n); i++)
    {
        ll sum = 0;
        f.clear();
        for (j = 0; j < n; j++)
            if ((i&(1<<j)) != 0)
            {
               f.push_back(a[j]);
               sum += a[j];
            }
        sort(f.begin(),f.end());
        ll tt = f.size();
        if (f.size() >= 2 && sum >= l && sum <= r && f[tt-1] - f[0] >= x)
           ans++;
    }
    cout << ans << endl;
    return 0;
}