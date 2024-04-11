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
ll i,j,n,k,k1,k2,k3,m,x1,x,y,y1,x2,y2,x3,y3,h,z;
string s1,s2,s3,s,t;
ll a[300505],b[1200500];
ll Abs(ll x)
{
    return x>0?x:-x;
}
set<ll> f;
set<ll>::iterator itr;
int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll cnt;
    cin >> n >> cnt >> k;
    cin >> m;
    f.insert(0);
    f.insert(n+1);
    ll ans = (n+1)/(k+1);
    for (i = 0; i < m; i++)
    {
        scanf("%I64d",&x);
        itr = f.upper_bound(x);
        ll l,r;
        r = *itr;
        itr--;
        l = *itr;
        ans -= (r-l)/(k+1);
        ans += (x-l)/(k+1);
        ans += (r-x)/(k+1);

        //cout << ans << endl;
        f.insert(x);
        if (ans < cnt)
        {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}