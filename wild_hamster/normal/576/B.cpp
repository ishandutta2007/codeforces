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
ll i,j,n,k,k1,k2,k3,m,x,y,l,r,z;
string s1,s2,s3,s,t;
ll a[100500], used[100500];
vector <ll> f[100500];
vector <ll> g;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (i = 1; i <= n; i++)
        scanf("%I64d",&a[i]);
    ll sz = 0;
    for (i = 1; i <= n; i++)
    if (!used[i])
    {
        g.clear();
        x = i;
        g.push_back(x);
        used[x] = 1;
        while (a[x] != i)
        {
            x = a[x];
            used[x] = 1;
            g.push_back(x);
        }
        f[sz++] = g;
    }
    ll flag = 1;
    ll min1 = INF;
    for (i = 0; i < sz; i++)
        min1 = min(min1,(ll)f[i].size());
    for (i = 0; i < sz; i++)
        if (((ll)f[i].size())%min1 != 0)
           flag = 0;
    if (!flag || min1 > 2)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    if (min1 == 1)
    {
        for (i = 0; i < sz; i++)
            if (f[i].size() == 1)
               k = f[i][0];
        for (i = 1; i <= n; i++)
            if (k != i)
               printf("%I64d %I64d\n",i,k);
            
    } else
    {
        for (i = 0; i < sz; i++)
            if (f[i].size() == 2)
               x = f[i][0], k = f[i][1];
        cout << x << " " << k << endl;
        for (i = 0; i < sz; i++)
            if (f[i][0] != x)
            {
                for (j = 0; j < f[i].size(); j++)
                    if (j%2 == 0)
                       printf("%I64d %I64d\n",f[i][j],x);
                    else
                       printf("%I64d %I64d\n",f[i][j],k);
            }
    }
    return 0;
}