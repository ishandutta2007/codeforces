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
#define INF (1+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 228228
#define eps 1e-12
typedef int ll;
typedef long double ld;
using namespace std;
ll n,m,k,n1,n2,i,j,l, x,coord,p,q;
ll a[1000500], t[400500];
set <ll> f;
vector<pair<ll,ll> > g;
ll Abs(ll x)
{
	return x>0?x:-x;
}
int main()
{
	cin >> n;
	for (i = 0; i < n; i++)
		scanf("%d",&a[i]);
		j = 0;
	for (i = 0; i < n; i++)
	{
		if (f.find(a[i]) == f.end())
			f.insert(a[i]);
		else
		{
			k++;
			g.push_back(mp(j+1, i+1));
			
			j = i+1;
			f.clear();
		}
	}
	if (k == 0)
		cout << -1 << endl;
	else
	{
		cout << k << endl;
		g[k-1].Y = n;
		for (i = 0; i < g.size(); i++)
			printf("%d %d\n",g[i].X,g[i].Y);
	}
    return 0;
}