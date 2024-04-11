#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 (33LL+(ll)1e+17)
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define MAXN 100100
typedef long long ll;
using namespace std;
ll x,y,l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,r,z,max1,tx,pnt,flag;
ll b[200500], t[400500], to_push[400500];
string s;
vector<pii> f;
vector<pii> g;
bool cmp(pii x, pii y)
{
    return (double)x.first/x.second < (double)y.first/y.second;
}
int main()
{
    cin >> n;
    f.push_back(mp(INF*2,1));
    f.push_back(mp(-INF*2,1));
    for (i = 0; i < n; i++)
    {
        ll k,b;
        scanf("%I64d%I64d",&k,&b);
        if (k != 0)
        {
           f.push_back(mp(-b,k));
           g.push_back(mp(k,b));
        }
    }
    sort(f.begin(),f.end(),cmp);
    double angle = 0;
    ll sz = g.size();
    for (i = 0; i < sz; i++)
    {
        j = upper_bound(f.begin(),f.end(),mp(-g[i].second,g[i].first),cmp) - f.begin() - 1;
        //cout << j << endl;
        k = g[i].first;
        if (k > 0)
        {
           b[j] += k;
           b[f.size()-1] -= k;
        }
        else
        {
            b[0] += k;
            b[j] -= k;
        }
    }
    ll ans = g.size();
    /*for (i = 0; i < f.size(); i++)
        cout << b[i] << " ";
    cout << endl;*/
    for (i = 1; i < f.size()-1; i++)
        if (b[i] == 0)
           ans--;
    cout << ans << endl;
    return 0;
}