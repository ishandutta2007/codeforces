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
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll cur,k,oz,w,l,r,i,j,k1,k2,dr,n,m, t, qt, qh, md, a[500005], b[500005], p[500005], used[500005], x, y;
vector <ll> g[300005];
ll binpow(ll x, ll y)
{
    if (y == 0)
       return 1;
    ll tmp = binpow(x,y/2);
    if (y%2 == 0)
       return (tmp*tmp)%MOD;
    else
        return (((tmp*tmp)%MOD)*x)%MOD;
}
ll inv(ll x)
{
    return binpow(x,MOD-2);
}
void dfs(ll v)
{
    used[v] = 1;
    ll cnt = 0;
    a[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
        if (!used[g[v][i]])
        {
            cnt++;
            dfs(g[v][i]);
            a[v] = (a[v]*(a[g[v][i]]+1))%MOD;
        }
    return;
}

void dfs2(ll v)
{
    used[v] = 1;
    ll cnt = 0;
    ll pp = 1, ppp = 1;
    b[v] = (a[v]*p[v])%MOD;
    for (int i = 0; i < g[v].size(); i++)
        if (!used[g[v][i]])
        {
            pp = (pp*(a[g[v][i]]+1))%MOD;
            if ((a[g[v][i]] + 1) % MOD == 0)
            {
               cnt++;
           } else
           ppp = (ppp*(a[g[v][i]]+1))%MOD;
        }
    for (int i = 0; i < g[v].size(); i++)
        if (!used[g[v][i]])
        {
            if (a[g[v][i]] + 1!= MOD || cnt > 1)
            p[g[v][i]] = (((pp*inv(a[g[v][i]]+1))%MOD)*p[v])%MOD+1;
            else
            p[g[v][i]] = (((ppp)%MOD)*p[v])%MOD+1;
            dfs2(g[v][i]);
        }
    return;
}
int main()
{
    cin >> n;
    for (i = 0; i < n-1; i++)
    {
        cin >> x;
        g[x].push_back(i+2);
        g[i+2].push_back(x);
    }
    dfs(1);
    for (i = 1; i <= n; i++)
        used[i] = 0;
    p[1] = 1;
    dfs2(1);
    for (i = 1; i <= n; i++)
        cout << b[i]%MOD << " ";
    return 0;
}