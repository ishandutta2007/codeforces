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
ll i,j,n,k,k1,k2,k3,m,h,z,l,x,y,r;
ll pre[200500], b[1005][1005];
ll a[200005];
string s;
int main()
{
	//freopen("input.txt","r",stdin);
	ll n, b, p;
	cin >> n >> b >> p;
	ll ans1 = n*p;
	ll ans = 0;
	while (n > 1)
	{
		for (i = 1; i <= n; i*=2)
		{
			
		}
		i /= 2;
		ans += i/2*(b*2+1);
		n -= i/2;
	}
	cout << ans << " " << ans1 << endl;
	return 0;
}