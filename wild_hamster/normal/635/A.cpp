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
ll a[15][15];


int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n >> m >> l >> k;
	for (i = 0; i < l; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		a[x][y] = 1;
	}
	ll ans = 0;
	for (i = 0; i < n; i++)
		for (l = i; l < n; l++)
			for (j = 0; j < m; j++)
				for (r = j; r < m; r++)
				{
					ll tmp = 0;
					for (k1 = i; k1 <= l; k1++)
						for (k2 = j; k2 <= r; k2++)
							tmp += a[k1][k2];
					if (tmp >= k)
					   ans++;
				}
	cout << ans << endl;
	return 0;
}