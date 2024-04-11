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
#define N 228228
#define mx 100
#define sqval 1000
#define eps 1e-9
typedef int ll;
typedef long double ld;
using namespace std;
ll n,m,k,x,y,i,xx,yy,q,j, w, l;
ll a[100500], b[100500], c[100500];

int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n >> k;
	for (i = 0; i < 4; i++)
	{
		cin >> x;
		a[i] = x;
		b[x] = 1;
	}
	for (j = 1; j <= n; j++)
	{
		if (!b[j])
		   a[i++] = j;
	}
	if (n == 4 || k < n+1)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << a[0] << " " << a[2] << " ";
	for (i = 4; i < n; i++)
		cout << a[i] << " ";
	cout << a[3] << " " << a[1] << endl;
	
	cout << a[2] << " " << a[0] << " ";
	for (i = 4; i < n; i++)
		cout << a[i] << " ";
	cout << a[1] << " " << a[3] << endl;
	return 0;
}