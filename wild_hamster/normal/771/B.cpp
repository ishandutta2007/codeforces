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
ll a[150500], used[150500], b[150000];
string pattern = "abcdefghijklmnopqrstuvwxyz";
string s;
string get_name(ll x)
{
    string s = "Aa";
    if (x >= 26)
        s[0] = 'B';
    s[1] = 'a' + x%26;
    return s;
}
vector<ll> g[105];
void dfs(ll v, ll col)
{
    if (used[v])
        return;
    used[v] = 1;
    a[v] = col;
    for (int i = 0; i < g[v].size(); i++)
    {
        dfs(g[v][i], col);
    }
}
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("input.txt","w",stdout);
    cin >> n >> m;
    for (i = 0; i < n-m+1; i++)
    {
        cin >> s;
        if (s[0] == 'Y')
            b[i] = 1;
        k += b[i];
    }
    if (k == 0)
    {
        for (i = 0; i < n; i++)
            cout << "A ";
        cout << endl;
        return 0;
    }

    if (k == n-m+1)
    {
        for (i = 0; i < n; i++)
            cout << get_name(i) << " ";
        cout << endl;
        return 0;
    }
    ll cnt = 0;
    for (i = 0; i < m; i++)
        a[i] = cnt++;
    if (b[0] == 0)
        a[0] = a[1];
    for (i = 1; i < n-m+1; i++)
        if (b[i] == 0)
        {
            a[i+m-1] = a[i];
        } else
            a[i+m-1] = cnt++;
    for (i = 0; i < n; i++)
        cout << get_name(a[i]) << " ";
    return 0;
}