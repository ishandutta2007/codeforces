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
ll a[1005][1005],b[5];
ll na,ma,nb,mb;
string s;
set<ll> f;
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (i = 0; i < n ; i++)
        for (j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == '.')
               a[i][j] = 1;
            else
                a[i][j] = 17;
        }
    ll ans = 0;
    k = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (i + 1 < n && j + 1 < m)
            {
                b[0] = a[i][j];
                b[1] = a[i+(1<<k)][j];
                b[2] = a[i][j+(1<<k)];
                b[3] = a[i+(1<<k)][j+(1<<k)];
                ll tmp = 0;
                for (k1 = 0; k1 < 4; k1++)
                    if (b[k1] != 17)
                       tmp += (1<<k1);
                if (tmp != 0)
                a[i][j] = tmp;
                else
                a[i][j] = 17;
            } else
              a[i][j] = 0;
/*  for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }*/
    for (k = 1; k < 10; k++)
    {
     for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (i + (1<<k) < n && j + (1<<k) < m)
            {
                b[0] = a[i][j];
                b[1] = a[i+(1<<k)][j];
                b[2] = a[i][j+(1<<k)];
                b[3] = a[i+(1<<k)][j+(1<<k)];
                
                ll tmp = 0;
                ll val;
                for (k1 = 0; k1 < 4; k1++)
                    if (b[k1] != 17)
                    {
                       tmp += (1<<k1);
                    }
                
                ll flag = 1;
                for (k1 = 0; k1 < 4; k1++)
                    if (b[k1] != 17 && b[k1] != tmp)
                    {
                        flag = 0;
                    }
                if (!flag)
                   a[i][j] = 0;
                else
                if (tmp == 0)
                {
                   a[i][j] = 17;
                   ans++;
                }
                else
                {
                    a[i][j] = tmp;
                    ans++;
                }
            } else
              a[i][j] = 0;
    }
    cout << ans << endl;
    return 0;
}