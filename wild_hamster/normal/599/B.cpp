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
typedef int ll;
using namespace std;
ll l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,x,y,r,z,max1,tx,flag,timer,start,finita,ans;
ll a[N],b[N],c[N],d[N],f[N];
set <ll> ff,gg;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> f[i];
        a[f[i]] = i;
        d[f[i]]++;
    }
    for (j = 1; j <= m; j++)
    {
        cin >> b[j];
        if (d[b[j]] == 0)
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    for (j = 1; j <= m; j++)
        if (d[b[j]] > 1)
        {
            cout << "Ambiguity" << endl;
            return 0;
        }
    cout << "Possible" << endl;
    for (j = 1; j <= m; j++)
        cout << a[b[j]] << " ";
    return 0;
}