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
#include <assert.h>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 1000000009
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 131072
#define SUM 377
#define MAG 33554431
#define RED 0
#define BLUE 1
#define eps 1e-7
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,ans, curL, curR, SQ, P, Q, bad;
string s, t, s1, t1;
ll a[500500], b[500500], used[500500], used_switch[500500], col[500500];
ll gcd(ll a, ll b)
{
    return b==0?a:gcd(b,a%b);
}
ll phi (ll n) {
	ll result = n;
	for (ll i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
 	cin >> n >> k;
    for (i = 0; i < (k+1)/2; i++)
    {
        n = phi(n);
        if (n == 1)
            break;
    }
    cout << n%MOD << endl;
    return 0;
}