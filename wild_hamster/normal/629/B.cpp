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
ll i,j,n,k,k1,k2,k3,m,h,z,l,x,y,r,p,d;
pii a[100500], b[100500];
char c;

int main()
{
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> c;
		if (c == 'F')
		{
		   cin >> a[k1].X >> a[k1].Y;
		   k1++;
		} else
		{
			cin >> b[k2].X >> b[k2].Y;
		   k2++;
		}
	}
	ll ans = 0;
	for (i = 1; i <= 366; i++)
	{
		l = 0; r = 0;
		for (j = 0; j < k1; j++)
			if (i >= a[j].X && i <= a[j].Y)
			   l++;
		for (j = 0; j < k2; j++)
			if (i >= b[j].X && i <= b[j].Y)
			   r++;
		ans = max(ans, min(l,r)*2);
	}
	cout << ans << endl;
	return 0;
}