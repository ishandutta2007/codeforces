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
ll i,j,n,k,l,m,tot, flag,r,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,c,ans, curL, curR, SQ;
map<pair<ll,set<ll> >,ll> grundy;
set<ll> em;
ll a[565];
ll find_grundy(pair<ll,set<ll> > c)
{
    if (grundy.find(c) != grundy.end())
        return grundy[c];
    if (c.X == 0)
        return 0;
    ll fs = c.X+1;
    ll b[fs];
    for (int i = 0; i < fs; i++)
        b[i] = 0;
    for (int i = 1; i <= c.X; i++)
    {
        if (c.Y.find(i) != c.Y.end())
            continue;
        c.Y.insert(i);
        c.X -= i;
        b[find_grundy(c)] = 1;
        c.Y.erase(i);
        c.X += i;
    }
    for (int i = 0; i < fs; i++)
        if (b[i] == 0)
            return i;
}
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
 	ll cur = 0;
    for (i = 0; i < 15; i++)
    {
        for (j = cur; j < cur+i+1; j++)
            a[j] = i;
        cur += i+1;
    }
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d",&x);
        ans ^= a[x];
    }
    if (ans == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}