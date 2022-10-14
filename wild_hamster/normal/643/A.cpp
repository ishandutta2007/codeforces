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
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n; i++)
	{
		for (j = 1; j <= n; j++)
			c[j] = 0;
		ll max1 = -1, x = 0;
		for (j = i; j < n; j++)
		{
			c[a[j]]++;
			if (c[a[j]] > max1 || c[a[j]] == max1 && a[j] < x)
			{
			   b[a[j]]++;
			   max1 = c[a[j]];
			   x = a[j];
			} else
			  b[x]++;
		}
	}
	for (i = 1; i <= n; i++)
		cout << b[i] << " ";
	cout << endl;
	return 0;
}