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
ll a[300505],bb[1200500];
ll Abs(ll x)
{
    return x>0?x:-x;
}
int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //for (i = 0; i <= 1200400; i++)
    //  bb[i] = 0;
    ll a,b,c,l;
    cin >> a >> b >> c >> l;
    ll ans = (l+3)*(l+1)*(l+2)/6;
    for (i = 0; i <= l; i++)
    if (b + c <= a + i)
    {
        ll x = min(l-i,a+i-b-c);
        ans -= (x+2)*(x+1)/2;
    }
    
    for (i = 0; i <= l; i++)
    if (a + c <= b + i)
    {
        ll x = min(l-i,b+i-a-c);
        ans -= (x+2)*(x+1)/2;
    }
    
    for (i = 0; i <= l; i++)
    if (b + a <= c + i)
    {
        ll x = min(l-i,c+i-b-a);
        ans -= (x+2)*(x+1)/2;
    }
    cout << ans << endl;
    return 0;
}