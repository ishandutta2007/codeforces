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
#define N 500500
#define SUM 23423
#define MAG 333
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,x,y,tot, flag,h,r,ans,koko,z,nl,nr,maxx,maxy,minx,miny;
ll a[N], b[N], dp[N], pa[N];
vector<pii> f;
pii ip[200500];
pii find_intersection(pii x1, pii x2)
{
	ll p = x2.Y-x1.Y;
	ll q = x1.X-x2.X;
	if (q < 0)
	   q = -q, p = -p;
	return mp(p,q);
}
bool cmp(pii x, pii y)
{
	return (double)x.X*y.Y < (double)x.Y*y.X;
}
ll query(ll k, ll b)
{
	pii cur = mp(k, b);
	int n = f.size();
	int pos = lower_bound(ip, ip+n-1, cur, cmp) - ip;
	return k*f[pos].X + f[pos].Y;
}
void addLine(ll k, ll b)
{
	pii cur = mp(k,b);
	if (f.size() == 1)
	{
		f.push_back(cur);
	} else	{
		
		while (1)
		{
		 int n = f.size();
		 if (n < 2)
			break;
		 pii l1 = f[n-2];
		 pii l2 = f[n-1];
		 if (cmp(find_intersection(l1,cur), find_intersection(l1, l2)))
			f.pop_back();
		 else
			 break;
		}
		f.push_back(cur);
	}
	int n = f.size();
	ip[n-2] = find_intersection(f[n-2], f[n-1]);
}
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		pa[i+1] = pa[i] + a[i];
	}
	for (i = 1; i < n; i++)
		dp[i] = INF;
	for (i = 0; i < n; i++)
		cin >> b[i];
	f.push_back(mp(b[0], dp[0]));
	for (i = 1; i < n; i++)
	{
	 	dp[i] = query(a[i], 1LL);
		addLine(b[i], dp[i]);
	}
	/*for (i = 0; i < n; i++)
		cout << dp[i] << endl;
	for (i = 0; i < f.size(); i++)
		cout << f[i].X << " " << f[i].Y << endl;*/
	/*if (n > 20000)
	{
		for (i = 0; i < min(10, (int)f.size()); i++)
			cout << ip[i].X << " " << ip[i].Y << endl;
		for (i = 0; i < min(10, (int)f.size()); i++)
			cout << f[i].X << " " << f[i].Y << endl;
	}*/
	cout << dp[n-1] << endl;
	return 0;
}