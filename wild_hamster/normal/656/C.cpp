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
#define INF (1LL+(ll)1e+18)
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
ll i,j,n, m,l,r,k, q, x,y, mx, cur;
ll a[100500], b[100500];
string s;
ll to(char c)
{
	if (c >= 'a' && c <= 'z')
	   return c-'a'+1;
	return c - 'A'+1;
}
int main()
{
	cin >> s;
	ll ans = 0;
	ll n = s.size();
	for (i = 0; i < n; i++)
	{
		if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
		   continue;
		if (s[i] > '@' && s[i] < ']')
		{
		   ans += to(s[i]);
	}
		if (s[i] > '`' && s[i] < '{')
		   ans -= to(s[i]);
	}
	cout << ans << endl;
	return 0;
}