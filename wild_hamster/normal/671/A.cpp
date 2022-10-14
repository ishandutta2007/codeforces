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
#define INF (1LL+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 228228
#define mx 100
#define sqval 1000
#define eps 1e-9
#define BLACK 0
#define WHITE 1
typedef long long ll;
typedef long double ld;
using namespace std;
ll n,m,k,i,xx,yy,q,j, w, l;
ll a[100500], x[100500], y[100500];
ll dst(ll x1, ll y1, ll x2, ll y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
ld dst1(ll x1, ll y1, ll x2, ll y2)
{
	return sqrt(dst(x1, y1, x2, y2));
}
vector <pair<ld,ll> > va, vb;
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ll ax,ay,bx,by,tx,ty;
	cin >> ax >> ay >> bx >> by >> tx >> ty;
	cin >> n;
	ld sum = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%I64d %I64d",&x[i], &y[i]);
		sum += 2.*sqrt(dst(x[i],y[i],tx,ty));
		va.push_back(mp(-dst1(x[i],y[i],tx,ty) + dst1(x[i],y[i],ax,ay), i));
		vb.push_back(mp(-dst1(x[i],y[i],tx,ty) + dst1(x[i],y[i],bx,by), i));
	}
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());
	ld ans = 1e+18;
	ll a1 = va[0].Y, b1 = vb[0].Y;
	ans = min(ans, sum + va[0].X);
	ans = min(ans, sum + vb[0].X);
	if (n > 1)
	{
		ll a2 = va[1].Y, b2 = vb[1].Y;
		if (a1 != b1)
		   ans = min(ans, sum + va[0].X + vb[0].X);
		else
			ans = min(ans, sum + min(va[0].X+vb[1].X, vb[0].X+va[1].X));
	}
	printf("%.9f\n",(double)ans);
	return 0;
}