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
#define MOD2 1000000009
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 202100
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,x,y,tot, flag,h,r,ans,koko, x1, y1, x2, y2, xx1, xx2, yy1, yy2;
ll a[1000500];
string s;
ll ask(ll a, ll b, ll c, ll d)
{
	cout << "? " << a << " " << b << " " << c << " " << d << endl;
	fflush(stdout);
	cin >> m;
	return m;
}
void find2(ll xl, ll yl, ll xr, ll yr, ll &x1, ll &y1, ll &x2, ll &y2, ll cnt)
{
	x1 = xl; y1 = yl;
	x2 = xr; y2 = yr;
	ll l, r;
	
	{
	l = x1, r = x2;
	while (l < r)
	{
		ll mid = (l+r-1)/2;
		if (ask(x1, y1, mid, y2) == cnt)
		   r = mid;
		else
			l = mid+1;
	}
	x2 = l;
	}
	
	{
	l = x1, r = x2;
	while (l < r)
	{
		ll mid = (l+r+1)/2;
		if (ask(mid, y1, x2, y2) == cnt)
		   l = mid;
		else
			r = mid-1;
	}
	x1 = l;
	}
	
	{
	l = y1, r = y2;
	while (l < r)
	{
		ll mid = (l+r-1)/2;
		if (ask(x1, y1, x2, mid) == cnt)
		   r = mid;
		else
			l = mid+1;
	}
	y2 = l;
	}

	{
	l = y1, r = y2;
	while (l < r)
	{
		ll mid = (l+r+1)/2;
		if (ask(x1, mid, x2, y2) == cnt)
		   l = mid;
		else
			r = mid-1;
	}
	y1 = l;
	}
}
pair<pii,pii> make_quadruple(ll a, ll b, ll c, ll d)
{
	return mp(mp(a,b),mp(c,d));
}
void print(pair<pii,pii> x)
{
	cout << " " << x.X.X << " " << x.X.Y << " " << x.Y.X << " " << x.Y.Y;
}
set<pair<pii,pii> > f;
set<pair<pii,pii> >::iterator itr;
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n;
	find2(1,1,n,n,x1,y1,x2,y2,2);
	if (x1 != x2 && ask(x1+1,y1,x2,y2) == 1 && ask(x1, y1, x2-1, y2) == 1)
	{
		find2(x1+1, y1, x2, y2, xx1, yy1, xx2, yy2, 1);
		f.insert(make_quadruple(xx1,yy1,xx2,yy2));
		if (xx2 == x2)
		{
			find2(x1, y1, x2-1, y2, xx1, yy1, xx2, yy2, 1);
			f.insert(make_quadruple(xx1,yy1,xx2,yy2));
		} else
		{
			if (yy1 == y1)
			{
				find2(x1, y1+1, x2, y2, xx1, yy1, xx2, yy2, 1);
				f.insert(make_quadruple(xx1,yy1,xx2,yy2));
			} else
			{
				find2(x1, y1, x2, y2-1, xx1, yy1, xx2, yy2, 1);
				f.insert(make_quadruple(xx1,yy1,xx2,yy2));
			}
		}

	} else
	{
		find2(x1, y1+1, x2, y2, xx1, yy1, xx2, yy2, 1);
		f.insert(make_quadruple(xx1,yy1,xx2,yy2));
		find2(x1, y1, x2, y2-1, xx1, yy1, xx2, yy2, 1);
		f.insert(make_quadruple(xx1,yy1,xx2,yy2));
	}

	cout << "!";
	for (itr = f.begin(); itr != f.end(); itr++)
		print(*itr);
	cout << endl;
	fflush(stdout);
	return 0;
}