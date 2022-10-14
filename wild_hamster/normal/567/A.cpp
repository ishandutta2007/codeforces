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
multiset <ll> f;
int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
    {
        if (i == 0)
           cout << a[i+1]-a[i] << " ";
        else
        if (i == n-1)
           cout << a[i] - a[i-1] << " ";
        else
            cout << min(a[i+1]-a[i],a[i]-a[i-1]) << " ";

        if (i == 0)
           cout << a[n-1]-a[i] << endl;
        else
        if (i == n-1)
           cout << a[i] - a[0] << endl;
        else
            cout << max(a[n-1]-a[i],a[i]-a[0]) << endl;
    }
    return 0;
}