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
#define eps 1e-7
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,ans, curL, curR, SQ, P, Q, bad;
string s, t, s1, t1;
ll a[500500], b[500500], used[500500], used_switch[500500], col[500500];
vector<ll> f[100500], g[100500];
vector<ll> component, comp_switch;
void dfs_for_comp(ll v)
{
    if (used[v])
        return;
    used[v] = 1;
    component.push_back(v);
    ll x1 = f[v][0];
    if (!used_switch[x1])
    {
        used_switch[x1] = 1;
        comp_switch.push_back(x1);
        for (int i = 0; i < g[x1].size(); i++)
            dfs_for_comp(g[x1][i]);
    }
    ll x2 = f[v][1];
    if (!used_switch[x2])
    {
        used_switch[x2] = 1;
        comp_switch.push_back(x2);
        for (int i = 0; i < g[x2].size(); i++)
            dfs_for_comp(g[x2][i]);
    }
}
void dfs(ll v, ll switched)
{
    if (used_switch[v])
    {
        if (switched != col[v])
            bad = 1;
        return;
    }
    used_switch[v] = 1;
    col[v] = switched;
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i];
        if (f[to][0] == v)
            dfs(f[to][1], (switched^a[to]));
        else
            dfs(f[to][0], (switched^a[to]));
    }
}
void cl()
{
        for (j = 0; j < comp_switch.size(); j++)
        {
            used_switch[comp_switch[j]] = 0;
        }
}
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i]^=1;
    }
    for (i = 0; i < m; i++)
    {
        cin >> k;
        for (j = 0; j < k; j++)
        {
            cin >> x;
            f[x].push_back(i);
            g[i].push_back(x);
        }
    }
    for (i = 1; i <= n; i++)
    if (!used[i])
    {
        component.clear();
        comp_switch.clear();
        dfs_for_comp(i);
        ll sum = 0;
        for (j = 0; j < component.size(); j++)
            sum += a[component[j]];
        if (sum == 0)
            continue;
        cl();
        if (a[i] == 0)
        {
            bad = 0;
            dfs(f[i][0], 0);
            if (!bad)
                continue;
            cl();
            bad = 0;
            dfs(f[i][0], 1);
            if (!bad)
                continue;
        } else
        {
            bad = 0;
            dfs(f[i][0], 0);
            if (!bad)
                continue;
            cl();
            bad = 0;
            dfs(f[i][0], 1);
            if (!bad)
                continue;
        }
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}