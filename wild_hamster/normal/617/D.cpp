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
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 (33LL+(ll)1e+17)
#define INF (1LL+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 228228
#define eps 1e-9
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,h,z,l,r,x1,y1,x2,y2;
string s1,s2,s3,s,t;
ll x[2005],y[2005];
vector <pair<ll,ll> > f;
int main()
{
	//freopen("input.txt", "r", stdin);
    ll a,b,c,d,e,f;
    pii g[3];
    cin >> g[0].X >> g[0].Y >> g[1].X >> g[1].Y >> g[2].X >> g[2].Y;
    ll ans = 3;
    for (i = 0; i < 10000; i++)
    {
    	random_shuffle(g, g+3);
    	a = g[0].X;
    	b = g[0].Y;
    	c = g[1].X;
    	d = g[1].Y;
    	e = g[2].X;
    	f = g[2].Y;
	    if (b == d && d == f)
	    	ans = min(ans,1);
	    if (b == d && (e >= max(a,c) || e <= min(a,c)))
	    	ans = min(ans,2);
	    swap(a,b); swap(c,d); swap(e,f);
	    if (b == d && d == f)
	    	ans = min(ans,1);
	    if (b == d && (e >= max(a,c) || e <= min(a,c)))
	    	ans = min(ans,2);
	    swap(a,b); swap(c,d); swap(e,f);
    }
    cout << ans << endl;
	return 0;
}