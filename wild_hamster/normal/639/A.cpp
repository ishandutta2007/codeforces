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
ll i,j,n, k, q, a[228228],b[228228], x, y;
set<pii> f;
set<pii>::iterator itr;
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n >> k >> q;
	for (i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	for (i = 0; i < q; i++)
	{
		scanf("%d %d",&x,&y);
		if (x == 1)
		{
			f.insert(mp(a[y], y));
			continue;
		}
		itr = f.end();
		ll sz = f.size();
		j = k;
		ll flag = 0;
		while (sz && j)
		{
			sz--;
			j--;
			itr--;
			if ((*itr).Y == y)
			   flag = 1;
		}
		if (flag)
		   printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}