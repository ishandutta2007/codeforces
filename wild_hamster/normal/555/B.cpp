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
ll x[200500],i,j,n,k,k1,k2,m,d,v,y[200500],z;
 pair<pair<ll,ll>,ll> b[200500];
 pair<ll,ll> a[200500];
ll ans[200500];
set<pair<ll,ll> > f;
set<pair<ll,ll> >::iterator itr;
int main()
{
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        scanf("%I64d%I64d",&x[i],&y[i]);
    }
    for (i = 1; i < n; i++)
    {
        b[i] = mp(mp(x[i+1]-y[i],y[i+1]-x[i]),i);
    }
    sort(b+1,b+n);
    for (i = 0; i < m; i++)
    {
        cin >> z;
        a[i] = mp(z,i+1);
    }
    sort(a,a+m);
    ll pnt = 1;
    /*for (i = 0; i < m; i++)
        cout << a[i].first << " " << a[i].second << endl;
    cout << endl;
    for (i = 1; i < n; i++)
        cout << b[i].first.first << " " << b[i].first.second << " " << b[i].second << endl;*/
 ll gav = 0;
    for (i = 0; i < m; i++)
    {
        while (pnt < n && b[pnt].first.first <= a[i].first)
        {
            f.insert(mp(b[pnt].first.second,b[pnt].second));
              pnt++;
        }
        while (f.size()!=0 && (*f.begin()).first < a[i].first)
        {
            f.erase(*f.begin());
        }
        if (f.size() != 0)
        {
        //  cout << (*f.begin()).second << " " << a[i].second << endl;
           ans[(*f.begin()).second] = a[i].second;
           f.erase(*f.begin());
           gav++;
           }
        else
            continue;
    }
    if (gav != n -1)
       cout << "No" << endl;
    else
    {
        cout << "Yes" << endl;
        for (i = 1; i < n; i++)
            cout << ans[i] << " ";
    }
    return 0;
}