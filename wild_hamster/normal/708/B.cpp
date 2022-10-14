#include <iostream>
//#include <cmath>
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
ll i,j,n,k,m,x,y;
ll a[100500];
ll a00, a01, a10, a11, x0, x1;
string s;
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> a00 >> a01 >> a10 >> a11;
	n = a00 + a01 + a10 + a11;
	if (n == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	k = -1;
	for (i = 1; i <= 200000; i++)
		if (i*(i-1)/2 == n)
		{
			k = i;
			break;
		}
	if (k == -1)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	if (a00 == 0 && a11 == 0)
	{
		if (a01 + a10 != 1)
		   cout << "Impossible" << endl;
		else
		if (a01 == 1)
		   cout << "01" << endl;
		else
			cout << "10" << endl;
		return 0;
	}
	if (a00 == 0)
	{
		if (a11 == n)
		{
			for (j = 0; j < k; j++)
				cout << 1;
			cout << endl;
		} else
		if (a01 + a10 == k-1)
		{
			for (j = 0; j < a10; j++)
				cout << 1;
			cout << 0;
			for (j = 0; j < a01; j++)
				cout << 1;
			cout << endl;
		} else
		cout << "Impossible" << endl;
		return 0;
	}
	if (a11 == 0)
	{
		if (a00 == n)
		{
			for (j = 0; j < k; j++)
				cout << 0;
			cout << endl;
		} else
		if (a01 + a10 == k -1)
		{
			for (j = 0; j < a01; j++)
				cout << 0;
			cout << 1;
			for (j = 0; j < a10; j++)
				cout << 0;
			cout << endl;
		} else
		cout << "Impossible" << endl;
		return 0;
	}
	x0 = x1 = -1;
	for (i = 1; i <= 200000; i++)
		if (i*(i-1)/2 == a00)
		{
		   x0 = i;
		   break;
		}
	for (i = 1; i <= 200000; i++)
		if (i*(i-1)/2 == a11)
		{
		   x1 = i;
		   break;
		}
	if (x0 == -1 || x1 == -1 || x0 + x1 != k)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	ll tmp = a01 / x1;
	ll tmp2 = x1 - (a01 - tmp*x1);
//	cout << tmp << " " << tmp2 << endl;
	for (i = 0; i < tmp; i++)
		cout << 0;
	for (i = 0; i < tmp2; i++)
		cout << 1;
	if (tmp != x0)
	   cout << 0;
	for (i = 0; i < x1 - tmp2; i++)
		cout << 1;
	for (i = 0; i < x0-1-tmp; i++)
		cout << 0;
	cout << endl;
	return 0;
}