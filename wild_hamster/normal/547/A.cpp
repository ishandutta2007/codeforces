#include <omp.h>
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
typedef long long ll;
using namespace std;
ll globalflag,oz,l,i,j,k1,k2,dr,n,k,w,m, qt, qh, a[500050], b[500050], r[1000005], md;
ll x,y,x1,x2,y1,y2,h1,h2,a1,a2,t1,t2;
ll binpow(ll x, ll y)
{
    if (y == 0)
       return 1%m;
    ll tmp = binpow(x,y/2);
    tmp = (tmp*tmp)%m;
    if (y%2 == 0)
       return tmp;
    else
        return (x*tmp)%m;
}
ll inv( ll x)
{
    return binpow(x,m-2);
}
int main()
{
    //freopen("kokoko.in","r",stdin);
    //freopen("kokoko.out","w",stdout);
    cin >> m;
    cin >> h1 >> a1 >> x1 >> y1;
    cin >> h2 >> a2 >> x2 >> y2;
    k1 = k2 = 0;

    t1 = t2 = 0;
    
    for (i = 1; i <= m+1; i++)
    {
        h1 = (x1*h1+y1)%m;
        if (h1 == a1)
        {
            k1 = i;
            break;
        }
    }
    
    for (i = 1; i <= m+1; i++)
    {
        h1 = (x1*h1+y1)%m;
        if (h1 == a1)
        {
            t1 = i;
            break;
        }
    }
    
    for (i = 1; i <= m+1; i++)
    {
        h2 = (x2*h2+y2)%m;
        if (h2 == a2)
        {
            k2 = i;
            break;
        }
    }

    for (i = 1; i <= m+1; i++)
    {
        h2 = (x2*h2+y2)%m;
        if (h2 == a2)
        {
            t2 = i;
            break;
        }
    }
    if (k1 == k2 && k1 != 0)
    {
        cout << k1 << endl;
        return 0;
    }
    
    //cout << k1 << " " << k2 << " " << t1 << " " << t2 << endl;
    if (k1 == 0 || k2 == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    if (t1 == 0 && t2 == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    if (t1 == 0)
    {
        if (k1 - k2 >= 0 && (k1 - k2)%t2 == 0)
           cout << k1 << endl;
        else
            cout << -1 << endl;
        return 0;
    }
    if (t2 == 0)
    {
        if (k2 - k1 >= 0 && (k2 - k1)%t1 == 0)
           cout << k2 << endl;
        else
            cout << -1 << endl;
        return 0;
    }
    i = 10*m+1;
    for (x = 0; x <= 10*m; x++)
    {
        if ((k1 + x*t1 - k2)%t2 == 0 && k1 + x*t1 - k2 >= 0)
        {
           i = x;
           break;
        }
    }
    if (i == 10*m+1)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << k1 + i*t1 << endl;
    return 0;
}