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
#include <unordered_map>
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
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,k,l,m,r,x,y,K,tot,h,H,sz,cur,sum,n,c, maxlvl;
ll a[150500], used[150500];
vector<ll> g[150500],f;
string s;
void dfs(ll v)
{
    if (used[v])
        return;
    used[v] = 1;
    f.push_back(v);
    for (int i = 0; i < g[v].size(); i++)
        dfs(g[v][i]);
}
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
 	cin >> n >> m;
 	for (i = 0; i < m; i++)
    {
        scanf("%d %d",&x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (i = 1; i <= n; i++)
        if (!used[i])
    {
        f.clear();
        dfs(i);
        ll sz = f.size();
        for (j = 0; j < sz; j++)
            if (g[f[j]].size() != sz-1)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}