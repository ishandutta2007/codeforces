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
ll i,j,n,k,k1,k2,k3,m,h,z,l,r,x,y;
ll a[300500], b[1000500];
vector <ll> num[1000500];
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n >> m;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		num[a[i]].push_back(i);
	}
	for (i = 1; i <= 1000000; i++)
	{
		sort(num[i].begin(), num[i].end());
		for (j = 0; j < num[i].size(); j++)
			b[num[i][j]] = j;
	}
	for (i = 0; i < m; i++)
	{
		ll l,r;
		scanf("%d %d %d",&l, &r, &x);
		if (a[l] != x)
		{
			printf("%d\n", l);
			continue;
		}
		if (a[r] != x)
		{
			printf("%d\n", r);
			continue;
		}
		if (b[r] - b[l] == r - l)
		{
			printf("-1\n");
			continue;
		}
		while (l < r)
		{
			ll mid = (l+r-1)/2;
			ll mid1 = b[mid];
			ll l1 = b[l];
			if (mid1 - l1 != mid - l || a[mid] != x || a[l] != x)
				r = mid;
			else
				l = mid+1;
		}
		printf("%d\n", l);
	}
	return 0;
}