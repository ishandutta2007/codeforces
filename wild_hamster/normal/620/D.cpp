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
#define eps 1e-12
typedef long long ll;
typedef long double ld;
using namespace std;
ll n,m,k,n1,n2,i,j,l, x,coord,p,q;
ll a[1000500], b[1000500], t[400500];
set <ll> f;
vector<pair<ll,ll> > g;
ll Abs(ll x)
{
	return x>0?x:-x;
}
pair<ll, pair<ll,ll> > posb[4005000];
int main()
{
    //freopen("input.txt","r",stdin);
    long long suma = 0, sumb = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		suma += a[i];
	}
	cin >> m;
	for (i = 0; i < m; i++)
	{
		cin >> b[i];
		sumb += b[i];
	}
	long long ans1 = Abs(suma - sumb);
	long long ans2 = INF*INF;
	ll ans2x, ans2y;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (Abs((suma - a[i] + b[j]) - (sumb - b[j] + a[i])) < ans2)
			{
				ans2 = Abs((suma - a[i] + b[j]) - (sumb - b[j] + a[i]));
				ans2x = i;
				ans2y = j;
			}
	if (min(n,m) < 2)
	{
		if (ans1 < ans2)
		{
			cout << ans1 << endl;
			cout << 0 << endl;
		} else 
		{
			cout << ans2 << endl;
			cout << 1 << endl;
			cout << ans2x+1 << " " << ans2y+1 << endl;
		}
		return 0;
	}
	ll sz = 0;
	for (i = 0; i < m; i++)
		for (j = i+1; j < m; j++)
			posb[sz++] = mp(b[i] + b[j], mp(i,j));
	sort(posb, posb+sz);
	long long ans3 = INF*INF;
	pii ans3f, ans3s;
	for (i = 0; i < n; i++)
		for (j = i+1; j < n; j++)
		{
			ll cura = a[i] + a[j];
			ll y = -(suma - sumb - 2*cura);
			int xx = upper_bound(posb, posb+sz, mp(y/2, mp(INF,INF))) - posb;
			pair<ll, pair<ll,ll> > lft = posb[max(0, xx - 1)];
			pair<ll, pair<ll,ll> > rgt = posb[min((int)sz-1, xx)];
			if (Abs(y - 2LL*lft.X) < ans3)
			{
				ans3 = Abs(y - 2LL*lft.X);
				ans3f = mp(i, lft.Y.X);
				ans3s = mp(j, lft.Y.Y);
			}
			if (Abs(y - 2LL*rgt.X) < ans3)
			{
				ans3 = Abs(y - 2LL*rgt.X);
				ans3f = mp(i, rgt.Y.X);
				ans3s = mp(j, rgt.Y.Y);
			}
		}
	if (ans3 <= ans2 && ans3 <= ans1)
	{
		cout << ans3 << endl;
		cout << 2 << endl;
		cout << ans3f.X+1 << " " << ans3f.Y+1 << endl;
		cout << ans3s.X+1 << " " << ans3s.Y+1 << endl;
	} else
	if (ans2 <= ans3 && ans2 <= ans1)
	{
		cout << ans2 << endl;
			cout << 1 << endl;
			cout << ans2x+1 << " " << ans2y+1 << endl;
	} else
	{
		cout << ans1 << endl;
			cout << 0 << endl;
	}
    return 0;
}