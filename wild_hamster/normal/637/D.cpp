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
ll i,j,n,m,s,d,cur;
ll a[1005605], fac[1005000];
vector<pii> f;
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n >> m >> s >> d;
	for (i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	sort(a,a+n);
	if (a[0] <= s)
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	ll RUN = 0, JUMP = 1;
	cur = a[0];
	f.push_back(mp(a[0]-1, RUN));
	for (i = 0; i < n-1; i++)
	{
		if (a[i+1] - a[i] - 1 <= s)
		   continue;
		if (a[i] - cur >= d-1)
		{
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}

		f.push_back(mp(a[i]-cur+2, JUMP));
		f.push_back(mp(a[i+1]-a[i]-2, RUN));
		cur = a[i+1];
	}
	if (a[n-1] - cur >= d-1)
 	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	f.push_back(mp(a[i]-cur+2, JUMP));
	if (m - a[i] - 1 > 0)
	{
		f.push_back(mp(m-a[i]-1, RUN));
	}
	for (i = 0; i < f.size(); i++)
	{
		if (f[i].Y == RUN)
		   printf("RUN %I64d\n", f[i].X);
		else
			printf("JUMP %I64d\n", f[i].X);
	}
	return 0;
}