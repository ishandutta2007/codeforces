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
typedef int ll;
using namespace std;
ll globalflag,oz,l,i,j,k1,k2,dr,n,k,w,m, qt, qh, b[500050], r, md;
ll x,y,x1,x2,y1,y2,h1,h2,a1,a2,t1,t2;
pair <ll,ll> a[500050];
multiset <ll> distances, points;
multiset<ll>::iterator itr;
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
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i].first);
        a[i].second = i+1;
    }
    distances.insert(n);
    ll rr = n;
    points.insert(0);
    points.insert(n+1);

    sort(a,a+n);
    for (i = 0; i < n; i++)
    {
        
        x = a[i].second;
        itr = points.upper_bound(x);
        r = *itr;
        itr--;
        l = *itr;
        points.insert(x);
        //cout << l << " " << r << endl;
        itr = distances.find(r-l-1);
        distances.erase(itr);
        distances.insert(x-l-1);
        distances.insert(r-x-1);
        
        itr = distances.end();
        itr--;
        y = *itr;
        //cout << y << endl;
        while (rr > y)
              b[rr--] = a[i].first;
    }
    for (i = 1; i <= n; i++)
        cout << b[i] << " ";
    return 0;
}