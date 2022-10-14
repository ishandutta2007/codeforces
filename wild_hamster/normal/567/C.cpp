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
map <ll,ll> f[4];
int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;
    for (i = 0; i < n; i++)
        scanf("%I64d",&a[i]);
    ll ans = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i]%k == 0)
        {
            ans += f[1][a[i]/k];
            f[1][a[i]] += f[0][a[i]/k];
        }

        f[0][a[i]]++;
    }
    cout << ans << endl;
    return 0;
}