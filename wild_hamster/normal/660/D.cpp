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
map <pii, ll> f;
map <pii, ll>::iterator itr;
ll gcd(ll a, ll b)
{
	return b==0?a:gcd(b,a%b);
}
ll Abs(ll x)
{
	return x>0?x:-x;
}
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	//ofstream f1("output2.txt");
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	for (i = 0; i < n; i++)
		for (j = i+1; j < n; j++)
		{
			ll difx = a[i] - a[j];
			ll dify = b[i] - b[j];
			if (difx < 0)
			{
				difx *= -1;
				dify *= -1;
			}
			if (difx == 0 && dify < 0)
			   dify *= -1;
			f[mp(difx, dify)]++;
		}
	ll ans = 0;
	for (itr = f.begin(); itr != f.end(); itr++)
	{
		ll tmp = (*itr).Y;
		ans += tmp*(tmp-1)/2;
	}
	ans /= 2;
	cout << ans << endl;
	return 0;
}