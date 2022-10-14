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
#define SQ 500400
#define CI 43534
typedef long long ll;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,x,y,x1,y1,x2,y2,x3,y3,h,z,l1,l2,l3;
string s1,s2,s3,s,t;
ll a[100500][2];
ll d[5050][2], used[10050];
ll Abs(ll x)
{
    return x>0?x:-x;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> x;
    ll l = x, r = x, val = 0;
    for (i = 1; i <= n; i++)
    {
        cin >> x >> y;
        if (x <= l && y >= r)
        {
        } else
        if (x >= l && x <= r && y >= r)
        {
            l = x;
        } else
        if (x <= l && y >= l && y <= r)
           r = y;
        else
        if (x >= l && x <= r && y >= l && y <= r)
        {
            l = x;
            r = y;
        }
        else
        if (x >= r)
        {
            val += x-r;
            l = r;
            r = x;
        } else
        if (y <= l)
        {
            val += l-y;
            r = l;
            l = y;
        }
    }
    cout << val << endl;
    return 0;
}