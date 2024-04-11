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
ll i,j,n, k, q, a[228228],b[228228], x, y,d,h;
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n >> d >> h;
	if (h == 1 && d == 1 && n > 2)
	{
		cout << -1 << endl;
		return 0;
	}
	if (d > 2*h)
	{
		cout << -1 << endl;
		return 0;
	}
	for (i = 1; i <= h; i++)
		cout << i << " " << i+1 << endl;
	if (d > h)
	{
		cout << 1 << " " << h+2 << endl;
	 	for (i = 0; i < d-h-1; i++)
			cout << h+2+i << " " << h+3+i << endl;
 	 }
	for (i = 0; i < n-1-d; i++)
		cout << h << " " << d+i+2 << endl;
	return 0;
}