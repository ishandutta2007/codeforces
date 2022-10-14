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
#define N 500000
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,x,y,tot, flag,h,r;
ll a[1005][1005];
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n;
	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 0)
			   x = i, y = j;
		}
	for (i = 0; i < n; i++)
		if (i != x)
		{
			k = i;
			break;
		}
	ll sum = 0;
	for (i = 0; i < n; i++)
		sum += a[k][i];
	ll tmp = 0;
	for (i = 0; i < n; i++)
		tmp += a[x][i];
	a[x][y] = sum - tmp;
	if (a[x][y] <= 0)
	{
		cout << -1 << endl;
		return 0;
	}
	ll flag = 1;

	for (i = 0; i < n; i++)
	{
		ll tmp = 0;
		for (j = 0; j < n; j++)
			tmp += a[i][j];
		if (tmp != sum)
		   flag = 0;
		tmp = 0;
		for (j = 0; j < n; j++)
			tmp += a[j][i];
		if (tmp != sum)
		   flag = 0;
	}
	tmp = 0;
	for (i = 0; i < n; i++)
		tmp += a[i][i];
	if (tmp != sum)
	   flag = 0;
 	tmp = 0;
	for (i = 0; i < n; i++)
		tmp += a[i][n-i-1];
	if (tmp != sum)
	   flag = 0;
	if (!flag)
	{
		cout << -1 << endl;
	} else
	{
		cout << a[x][y] << endl;
	}
	return 0;
}