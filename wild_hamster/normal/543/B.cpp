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
#define MOD 1000000009
typedef long long ll;
using namespace std;
ll cur,k,oz,w,l,r,i,j,k1,k2,dr,n,m, t, qt, qh, md, q[5005], d[5005], used[5005], x, y;
ll a[100500], dist[3005][3005];
vector <ll> g[3005];
ll s1,t1,l1,s2,t2,l2;
void bfs(ll v)
{
    dist[cur][v] = 0;
    qt = 0;
    q[qt++] = v;
    d[v] = 0;
    qh = 0;
    used[v] = 1;
    while (qh < qt)
    {
        for (int i = 0; i < g[q[qh]].size(); i++)
            if (!used[g[q[qh]][i]])
            {
                used[g[q[qh]][i]] = 1;
                q[qt++] = g[q[qh]][i];
                d[g[q[qh]][i]] = d[q[qh]] + 1;
                dist[cur][g[q[qh]][i]] = d[q[qh]] + 1;
            }
        qh++;
    }
}
ll f(ll x, ll y)
{
    return dist[x][y];
}
string s;
int main()
{
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (cur = 1; cur <= n; cur++)
    {
        for (i = 1; i <= n; i++)
            d[i] = q[i] = used[i] = 0;

        bfs(cur);
    }
    /*for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }*/
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
    if (dist[s1][t1] > l1 || dist[s2][t2] > l2)
    {
        cout << -1 << endl;
        return 0;
    }
    ll ans = dist[s1][t1] + dist[s2][t2];
    if (s1 > t1) swap(s1,t1);
    if (s2 > t2) swap(s2,t2);
    for (x = 1; x <= n; x++)
        for (y = 1; y <= n; y++)
        {
            if (f(s1,x)+f(x,y)+f(y,t1) <= l1 && f(s2,x)+f(x,y)+f(y,t2) <= l2)
               ans = min(ans,f(s1,x)+f(x,y)+f(y,t1)+f(s2,x)+f(y,t2));
        }
    swap(s1,t1);
    for (x = 1; x <= n; x++)
        for (y = 1; y <= n; y++)
        {
            if (f(s1,x)+f(x,y)+f(y,t1) <= l1 && f(s2,x)+f(x,y)+f(y,t2) <= l2)
               ans = min(ans,f(s1,x)+f(x,y)+f(y,t1)+f(s2,x)+f(y,t2));
        }
    swap(s2,t2);
    for (x = 1; x <= n; x++)
        for (y = 1; y <= n; y++)
        {
            if (f(s1,x)+f(x,y)+f(y,t1) <= l1 && f(s2,x)+f(x,y)+f(y,t2) <= l2)
               ans = min(ans,f(s1,x)+f(x,y)+f(y,t1)+f(s2,x)+f(y,t2));
        }
    swap(s1,t1);
    for (x = 1; x <= n; x++)
        for (y = 1; y <= n; y++)
        {
            if (f(s1,x)+f(x,y)+f(y,t1) <= l1 && f(s2,x)+f(x,y)+f(y,t2) <= l2)
               ans = min(ans,f(s1,x)+f(x,y)+f(y,t1)+f(s2,x)+f(y,t2));
        }
    cout << m-ans << endl;
    return 0;
}