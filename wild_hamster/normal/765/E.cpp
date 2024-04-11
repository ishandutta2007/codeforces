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
#include <assert.h>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 1000000009
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 131072
#define SUM 377
#define MAG 33554431
#define RED 0
#define BLUE 1
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,c,ans;
string s,t;
ll w[200500];
vector<ll> needed[200500], g[200500];
set<ll> used[200500];
set<ll> f;
set<ll>::iterator itr;
vector<pii> res;
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
    cin >> n;
    for (i = 0; i < n-1; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        w[x]++;
        w[y]++;
    }
    for (i = 1; i <= n; i++)
    {
        if (w[i] == 1)
        {
            needed[0].push_back(i);
        }
    }
    i = 0;
    while (!needed[i].empty())
    {
        f.clear();
        q += needed[i].size();
        if (q == n && needed[i].size() == 2)
        {
            if (res.empty())
                cout << 2*i+1 << endl;
            else
                cout << -1 << endl;
            return 0;
        }
        for (j = 0; j < needed[i].size(); j++)
        {
            ll v = needed[i][j];
            for (k = 0; k < g[v].size(); k++)
            {
                ll to = g[v][k];
                if (used[v].find(to) == used[v].end())
                {
                    w[to]--;
                    f.insert(to);
                    used[to].insert(v);
                }
            }
        }
        for (itr = f.begin(); itr != f.end(); itr++)
        {
            ll to = *itr;
            if (w[to] != 1)
            {
                res.push_back(mp(to, i+1));
            } else
                needed[i+1].push_back(to);
        }
        i++;
    }
    if (res.size() > 2)
        cout << -1 << endl;
    else
    if (res.size() == 2)
    {
        if (res[0].X != res[1].X)
            cout << -1 << endl;
        else
        {
            ll x = res[0].Y + res[1].Y;
            while (x%2 == 0)
                x /= 2;
            cout << x << endl;
        }
    } else
    {
        ll x = res[0].Y;
        while (x%2 == 0)
            x /= 2;
        cout << x << endl;
    }
    return 0;
}