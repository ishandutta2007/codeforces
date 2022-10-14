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
ll i,j,n, k, q, a[228228],b[228228], x, y,d,h;
ll Abs(ll x)
{
	return x>0?x:-x;
}
int main()
{
	//freopen("input.txt","r",stdin);
	cin >> n >> x;
	for (i = 0; i <= n; i++)
	{
		scanf("%I64d",&a[i]);
		b[i] = a[i];
	}
	for (i = 0; i < n; i++)
	{
		if (b[i] % 2 != 0)
		   break;
		b[i+1] += b[i]/2;
	}
	k = i;
	ll val = 0;
	for (i = n; i >= k; i--)
	{
		val = val*2 + b[i];
		if (Abs(val) > 2*x)
		{
			cout << 0 << endl;
			return 0;
		}
	}
	while (Abs(val) <= 2*x && k > 0)
	{
		k--;
		val *= 2;
	}
	ll ans = 0;
	for (i = k; i <= n; i++)
	{
		if (i == n && a[i] - val == 0)
		   break;
		if (Abs(a[i] - val) <= x)
		{
		   ans++;
		   //cout << a[i]-val << endl;
		   }
		if (val % 2 != 0)
		   break;
		val /= 2;
	}
	cout << ans << endl;
	return 0;
}