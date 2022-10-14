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
ll i,j,n,m,x,q,y,z,k,x1,y1,was_created,free_left,qq;
ll a[300500], b[300500], after[300500], before[300500];
ll gcd(ll a, ll b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	//ofstream f1("output2.txt");
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &a[i]);
		a[i] = 1 - a[i];
		if (a[i])
		   b[k++] = i;
	}
	q = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] == 0)
		   q++;
		else
		{
			before[i] = q;
			q = 0;
		}
	}
	q = 0;
	for (i = n-1; i >= 0; i--)
	{
		if (a[i] == 0)
		   q++;
		else
		{
			after[i] = q;
			q = 0;
		}
	}
	if (k <= m)
	{
		cout << n << endl;
		for (i = 0; i < n; i++)
			printf("1 ");
		return 0;
	}
	if (m == 0)
	{
		ll max1 = 0;
		for (i = 0; i < n; i++)
			max1 = max(max1, max(before[i], after[i]));
		cout << max1 << endl;
		for (i = 0; i < n; i++)
			printf("%I64d ", 1-a[i]);
		return 0;
	}
	ll max1 = 0;
	for (i = 0; i <= k-m; i++)
	{
		ll tmp = b[i+m-1] - b[i] + after[b[i+m-1]] + before[b[i]] + 1;
		if (tmp > max1)
		{
			max1 = tmp;
			j = i;
		}
	}
	for (i = j; i < j+m; i++)
		a[b[i]] = 0;
	cout << max1 << endl;
	for (i = 0; i < n; i++)
		printf("%I64d ", 1-a[i]);
	return 0;
}