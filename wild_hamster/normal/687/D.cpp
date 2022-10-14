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
#define MOD 1000000009
#define MOD2 1000000009
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 1000000
#define sqval 1000
#define eps 1e-9
#define BLACK 0
#define WHITE 1
#define MAG 12
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,x,y,z,m,k,l,r,flag,timer,glob,sz,q;
string s,t;
pair<pii, pii> a[N+500];
ll g[1005][1005], gsz[1005];
ll p[1005], c[1005];
ll w[N+500], num[N+500], fir[N+500], sec[N+500];
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> m >> q;
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a[i].Y.X, &a[i].Y.Y, &a[i].X.X);
		a[i].X.Y = i+1;
	}
	sort(a, a+m);
	reverse(a, a+m);
	for (j = 0; j < m; j++)
		num[j] = a[j].X.Y;
	for (i = 0; i < q; i++)
	{
		for (j = 1; j <= n; j++)
			p[j] = j, c[j] = -1, w[j] = 1;
		cin >> l >> r;
		ll ans = -1;
		for (j = 0; j < m; j++)
			if (num[j] >= l && num[j] <= r)
			{
				ll x = a[j].Y.X;
				ll y = a[j].Y.Y;
				if (p[x] == p[y])
				{
					if (c[x] == c[y])
					{
						ans = a[j].X.X;
						break;
					}
				} else
				{
					if (c[x] == -1 && c[y] == -1)
					{
						p[x] = p[y];
						c[x] = 0;
						c[y] = 1;
						w[p[x]] = 2;
					} else
					if (c[x] == -1)
					{
						p[x] = p[y];
						c[x] = !c[y];
						w[p[x]]++;
					} else
					if (c[y] == -1)
					{
						p[y] = p[x];
						c[y] = !c[x];
						w[p[y]]++;
					} else
					{
						if (w[p[x]] > w[p[y]])
						   swap(x,y);
						w[p[y]] += w[p[x]];
						ll col = p[x];
						ll to_inv = (c[x] == c[y]);
						for (k = 1; k <= n; k++)
						if (p[k] == col)
						{
						 p[k] = p[y];
						 c[k] ^= to_inv;
						}
					}
				}
			}
		cout << ans << endl;
	}
	return 0;
}