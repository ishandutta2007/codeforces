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
#define INF (1+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 118228
typedef unsigned long long ll;
using namespace std;
ll l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,x,y,r,z,max1,tx,flag,timer,start,finita,ans;
ll a[N],b[N],c[N],d[N];
vector <pii> f;
map <pii,ll> used;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> x;
    for (m = 1; m <= 2000000; m++)
    {
        ll tmp = 6LL*x + (m-1)*m*(m+1);
        if (tmp % (3LL*m*(m+1)) == 0)
        {
            ll n = tmp / (3LL*m*(m+1));
            if (m > n)
               continue;
            if (!used[mp(n,m)])
            {
               f.push_back(mp(n,m));
               used[mp(n,m)] = 1;
            }
            if (!used[mp(m,n)])
            {
               f.push_back(mp(m,n));
               used[mp(m,n)] = 1;
            }
        }
    }
    sort(f.begin(),f.end());
    cout << f.size() << endl;
    for (i = 0; i < f.size(); i++)
        cout << f[i].X << " " << f[i].Y << endl;
    return 0;
}