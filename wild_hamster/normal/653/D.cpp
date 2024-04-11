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
typedef long long ll;
typedef long double ld;
using namespace std;
ll k,i,j,n,m,x,y,w,dw,l;
ll a[400500], b[400500], b1[400500];
const int MAXN = 55;

ll c[MAXN][MAXN], f[MAXN][MAXN], s, t, d[MAXN], ptr[MAXN], q[MAXN];

bool bfs() {
	ll qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, n * sizeof d[0]);
	d[s] = 0;
	while (qh < qt) {
		ll v = q[qh++];
		for (ll to=0; to<n; ++to)
			if (d[to] == -1 && f[v][to] < c[v][to]) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
	}
	return d[t] != -1;
}

ll dfs (ll v, ll flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (ll & to=ptr[v]; to<n; ++to) {
		if (d[to] != d[v] + 1)  continue;
		ll pushed = dfs (to, min (flow, c[v][to] - f[v][to]));
		if (pushed) {
			f[v][to] += pushed;
			f[to][v] -= pushed;
			return pushed;
		}
	}
	return 0;
}

ll dinic() {
	ll flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, n * sizeof ptr[0]);
		while (ll pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n >> m >> k;
	for (i = 0; i < m; i++)
	{
		cin >> a[i] >> b[i] >> b1[i];
		a[i]--;
		b[i]--;
	}
	s = 0; t = n-1;
	ld l = 0, r = 1e+8;
	while (r-l > 1e-13)
	{
		//cout << l << " " << r << endl;
		ld mid = (l+r)/2;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				f[i][j] = c[i][j] = 0;
			}
		for (i = 0; i < m; i++)
			c[a[i]][b[i]] = b1[i]/mid;
		ll tmp = dinic();
		if (tmp >= k)
		   l = mid;
		else
			r = mid;
	}
	printf("%.9f\n",(double)(l*k));
	return 0;
}