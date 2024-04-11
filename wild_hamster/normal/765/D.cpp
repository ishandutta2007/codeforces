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
ll i,j,n,k,l,m,tot, flag,r,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,c;
string s,t;
ll used[100500];
ll a[100500];
ll H[100500], G[100500], pos[100500];
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
 	cin >> n;
 	sz = 1;
 	for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (used[a[i]] != 1)
        {
            used[a[i]] = 1;
            H[sz] = a[i];
            pos[a[i]] = sz;
            sz++;
        }
    }
    for (i = 1; i <= n; i++)
        G[i] = pos[a[i]];
    for (i = 1; i <= n; i++)
        if (H[G[i]] != a[i])
        {
            cout << -1 << endl;
            return 0;
        }
    for (i = 1; i <= sz-1; i++)
        if (G[H[i]] != i)
        {
            cout << -1 << endl;
            return 0;
        }
    cout << sz-1 << endl;
    for (i = 1; i <= n; i++)
        cout << G[i] << " ";
    cout << endl;
    for (i = 1; i < sz; i++)
        cout << H[i] << " ";
    cout << endl;
    return 0;
}