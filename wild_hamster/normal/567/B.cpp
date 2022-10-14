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
ll st[1000500];
char tt[105];
ll yy[105];
int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        char c;
        cin >> c >> x;
        tt[i] = c;
        yy[i] = x;
        if (c == '+')
           b[x]++;
        else
            b[x]--;
        if (b[x] < 0)
           st[x] = 1;
    }
    ll ans = 0;
    ll tmp = 0;
    for (i = 0; i <= 1000000; i++)
        tmp += st[i];
    ans = tmp;
    for (i = 0; i < n; i++)
    {
        if (tt[i] == '+')
           tmp++;
        else
            tmp--;
        ans = max(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}