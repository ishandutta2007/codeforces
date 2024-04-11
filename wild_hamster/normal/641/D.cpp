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
typedef int ll;
typedef long double ld;
using namespace std;
ll n, k,j,i,m,q,ii,timer,x1,y;
ll min1, max1;
ld a[100500], b[100500];
ld ansa[100500], ansb[100500];
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n;

	ld suma = 0, sumb = 1;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n; i++)
		cin >> b[i];
	ld cura = 0, curb = 0;
	for (i = 0; i < n-1; i++)
	{
		suma += a[i];
		sumb -= b[i];
		ld A = 1;
		ld B = sumb-suma-1;
		ld C = suma;
		ld D = B*B - 4*A*C;
		ld x1 = (-B+sqrt(D))/(2.*A);
		ld x2 = (-B-sqrt(D))/(2.*A);
		x1 -= cura;
		x2 -= curb;
		ansa[i] = x1;
		ansb[i] = x2;
		cura += x1;
		curb += x2;
	}
	ansa[n-1] = 1-cura;
	ansb[n-1] = 1-curb;
	for (i = 0; i < n; i++)
		printf("%.8f ", (double)ansa[i]);
	cout << endl;
	for (i = 0; i < n; i++)
		printf("%.8f ", (double)ansb[i]);
	return 0;
}