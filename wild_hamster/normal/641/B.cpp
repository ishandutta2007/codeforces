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
#define SQ 500400
#define CI 43534
#define N 228228
#define eps 1e-9
typedef long long ll;
typedef long double ld;
using namespace std;
ll n, k,j,i,m,q,ii,timer,x1,y,x;
ll min1, max1;
ll a[105][105], a1[100500], a2[100500], a3[100500], a4[100500];
string s;
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n >> m >> q;
	for (i = 0; i < q; i++)
	{
		cin >> a1[i] >> a2[i];
		if (a1[i] == 3)
		{
			cin >> a3[i] >> a4[i];
		}
	}
	for (i = q-1; i >= 0; i--)
	{
		if (a1[i] == 3)
		{
			a[a2[i]][a3[i]] = a4[i];
		}
		if (a1[i] == 2)
		{
			x = a2[i];
			ll tmp = a[n][x];
			for (j = n; j >= 2; j--)
				a[j][x] = a[j-1][x];
			a[1][x] = tmp;
		}
		if (a1[i] == 1)
		{
			x = a2[i];
			ll tmp = a[x][m];
			for (j = m; j >= 2; j--)
				a[x][j] = a[x][j-1];
			a[x][1] = tmp;
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}