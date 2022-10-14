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
#include <list>
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
#define N 1000000
#define SUM 377
#define MAG 33554431
#define RED 0
#define BLUE 1
#define ALP 26
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,k,l,m,r,x,y,K,tot,h,H,sz,cur,sum,n,c, maxlvl,ans;
ll w[200500][6], cur_w[6], W[200500];
vector<ll> g[200500];
void dfs(ll v, ll d, ll p = -1)
{
    w[v][0]++;
    W[v] = 1;
    tot += d;
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i];
        if (to != p)
        {
            dfs(to, d+1, v);
            for (int j = 0; j < k; j++)
                w[v][j] += w[to][(j-1+k)%k];
            W[v] += W[to];
        }
    }
}
ll fin(ll x)
{
    if (x == 0)
        return x;
    return k-x;
}
void dfs2(ll v, ll p = -1)
{
    ll local_w[6], local_tot;
    for (int j = 0; j < k; j++)
        local_w[j] = cur_w[j];
    local_tot = tot;
    ll tmp = 0;
    for (int j = 0; j < k; j++)
    {
        tmp += fin(j)*cur_w[j];
    }
    ans += (tot+tmp)/k;
    /*cout << tot+tmp << " " << v << " " << ans << " " << tot << " " << W[v] << endl;
    for (j = 0; j < k; j++)
        cout << cur_w[j] << " ";
    cout << endl;*/
    /*for (j = 0; j < k; j++)
        cout << w[v][j] << " ";
    cout << endl;*/
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i];
        if (to != p)
        {
            tot += n - 2*W[to];
            ll tor = cur_w[0];
            for (int j = 0; j+1 < k; j++)
                cur_w[j] = cur_w[j+1];
            cur_w[k-1] = tor;
            ll tutu[6];
            for (int j = 0; j < k; j++)
            {
                tutu[j] = cur_w[j] - w[to][j];
                cur_w[j] = w[to][j];
            }
            for (int j = 0; j < k; j++)
            {
                cur_w[(j+2)%k] += tutu[j];
            }
            dfs2(to, v);
            tot = local_tot;
            for (int j = 0; j < k; j++)
                cur_w[j] = local_w[j];
        }
    }
}
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("input.txt","w",stdout);
    cin >> n >> k;
    for (i = 0; i < n-1; i++)
    {
        scanf("%I64d %I64d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    for (j = 0; j < k; j++)
        cur_w[j] = w[1][j];
    dfs2(1);
    cout << ans/2 << endl;
    return 0;
}