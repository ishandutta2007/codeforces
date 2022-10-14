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
ll n, k,j,i,m,q,ii,x,y,z,timer,x1,y1;
ll min1, max1;
ll a[105000], dp[100500], used[100500];
string s;
int main()
{
	//freopen("input.txt","r",stdin);
	//
	cin >> n;
	cin >> s;
	for (i = 0; i < n; i++)
		cin >> a[i];
	x = 0;
	while (1)
	{
		if (used[x])
		{
			cout << "INFINITE" << endl;
			return 0;
		}
		used[x] = 1;
		if (s[x] == '>' && x + a[x] >= n)
		{
			cout << "FINITE" << endl;
			return 0;
		}
		if (s[x] == '<' && x - a[x] < 0)
		{
			cout << "FINITE" << endl;
			return 0;
		}
		if (s[x] == '>')
		   x += a[x];
		else
			x -= a[x];
	}
	return 0;
}