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
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,r,x,y,K,tot;
string s,t,s1;
ll used[100500];
vector<ll> f, g[100500], ans;
void dfs(ll v)
{
    if (used[v])
        return;
    used[v] = tot;
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i];
        if (used[to] == tot)
        {
            cout << -1 << endl;
            exit(0);
        }
        dfs(to);
    }
    ans.push_back(v);
    used[v] = n+2;
}
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> x;
        f.push_back(x);
    }
    for (i = 1; i <= n; i++)
    {
        cin >> k;
        for (j = 0; j < k; j++)
        {
            cin >> x;
            g[i].push_back(x);
        }
    }
    for (j = 0; j < f.size(); j++)
    {
        tot = j+1;
        ll x = f[j];
        dfs(x);
    }
    cout << ans.size() << endl;
    for (i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}