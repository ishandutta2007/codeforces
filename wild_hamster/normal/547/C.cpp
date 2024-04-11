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
ll globalflag,oz,l,i,j,k1,k2,dr,n,k,w,m, qt, qh, b[500050], r, md, a[500050], used[200500];
ll x,y,x1,x2,y1,y2,h1,h2,a1,a2,t1,t2;
vector <ll> f[200500], primes[200500];
vector <ll> prs;
bool isp(ll x)
{
    for (int i = 2; i < x; i++)
        if (x%i == 0)
           return false;
    return true;
}
int main()
{
    //freopen("kokoko.in","r",stdin);
    //freopen("kokoko.out","w",stdout);
    for (i = 2; i < 1000; i++)
        if (isp(i))
        {
           prs.push_back(i);
        }
    cin >> n >> m;
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]);
    for (i = 0; i < n; i++)
    {
        
        x = a[i];
        
        
        for (j = 0; prs[j]*prs[j] <= a[i]; j++)
            if (x % prs[j] == 0)
            {
                primes[i].push_back(prs[j]);
                while (x%prs[j] == 0)
                      x/=prs[j];
            }
        if (x != 1)
           primes[i].push_back(x);
           ll nn = primes[i].size();
        //cout << nn << endl;
        for (int ii = 1; ii < (1<<nn); ii++)
        {
            ll tt = 1;
            for (j = 0; j < nn; j++)
                if ((ii&(1<<j))!=0)
                {
                   tt *= primes[i][j];
                }
            f[i].push_back(tt);
        }
    }
    ll ans = 0, tmpp = 0;
    for (int tests = 0; tests < m; tests++)
    {
        cin >> x;
        x--;
        ll flag = 0;
        if (!used[x]) flag = 1, tmpp++;
        if (used[x])
        {
            tmpp--;
           used[x] = 0;
           for (j = 0; j < f[x].size(); j++)
               b[f[x][j]]--;
        } 
        ll tmp = 0;
        ll nn = primes[x].size();
        //cout << nn << endl;
        ll bits = 1;
        for (i = 1; i < (1<<nn); i++)
        {
            ll bcount = 0;
            ll tt = 1;
            for (j = 0; j < nn; j++)
                if ((i&(1<<j))!=0)
                {
                   bcount++;
                   tt *= primes[x][j];
                }
            bcount %= 2;
            ll z = -1;
            if (bcount == bits)
               z = 1;
            //cout << b[tt] << endl;
            tmp += z*b[tt];
        }
        if (!flag)
           ans += (ll)tmp;
        else
            ans -= (ll)tmp;
        if (flag)
        {
            used[x] = 1;
            for (j = 0; j < f[x].size(); j++)
               b[f[x][j]]++;
        }
        printf("%I64d\n",((ll)tmpp*(tmpp-1LL))/2LL + (ll)ans);
    }
    return 0;
}