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
#define N 131072
#define SUM 377
#define MAG 33554431
#define RED 0
#define BLUE 1
#define ALP 26
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,nn, hs, ml,cnt;
string s,t,s1;
ll a[300500], used[300500];
vector<ll> g[300500], f;
void dfs(ll v, ll p)
{
    if (used[v])
        return;
    used[v] = 1;
    f.push_back(v);
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i];
        dfs(to, v);
    }
    if (p != -1)
        f.push_back(p);
}
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
 	cin >> n >> m >> k;
 	for (i = 0; i < m; i++)
    {
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, -1);
    h = (2*n-1)/k+1;
    for (i = 0; i < k; i++)
    {
        if (i*h >= f.size())
        {
            cout << 1 << " " << 1 << endl;
        } else
        {
            ll sz = f.size();
            ll cur = min(h, sz-i*h);
            cout << cur;
            for (j = i*h; j < i*h+cur; j++)
                cout << " " << f[j];
            cout << endl;
        }
    }
    return 0;
}