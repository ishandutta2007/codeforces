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
ll gcd(ll a, ll b)
{
	if (b == 0)
	   return a;
	return gcd(b, a%b);
}
string s;
int main()
{
	ll NN = 720720;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n; i++)
		cin >> b[i];
	for (i = 0; i < NN; i++)
	{
		ll flag = 0;
		for (j = 0; j < n; j++)
			if (i % a[j] == b[j])
			   flag = 1;
		k += flag;
	}
	printf("%.9f\n",(float)((ld)k/NN));
	return 0;
}