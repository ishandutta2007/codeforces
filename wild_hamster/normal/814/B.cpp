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
ll i,j,k,l,m,r,x,y,K,tot,h,H,sz,cur,sum;
ll n;
int a[100500], used[500005], b[100500];
vector<ll> f,g;
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
        if (a[i] != b[i])
        {
            f.push_back(i);
        } else
            used[a[i]] = 1;
    }
    for (i = 1; i <= n; i++)
        if (!used[i])
            g.push_back(i);
    if (f.size() == 1)
    {
        a[f[0]] = g[0];
        for (i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        return 0;
    }
    x = a[f[0]];
    a[f[0]] = b[f[0]];
    if (a[f[0]] == g[0] && a[f[1]] == g[1] || a[f[1]] == g[0] && a[f[0]] == g[1])
    {
        for (i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        return 0;
    }
    b[f[0]] = x;
    if (b[f[0]] == g[0] && b[f[1]] == g[1] || b[f[1]] == g[0] && b[f[0]] == g[1])
    {
        for (i = 0; i < n; i++)
            cout << b[i] << " ";
        cout << endl;
        return 0;
    }
    return 0;
}