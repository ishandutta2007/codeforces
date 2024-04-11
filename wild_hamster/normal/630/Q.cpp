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
ll dp[1005][1005];
string s;
ll fib[600500];
ll gcd(ll a, ll b)
{
	if (b == 0)
	   return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b)
{
	return a*b/gcd(a,b);
}
vector<pii> f;
int main()
{
	//freopen("input.txt","r",stdin);
	//C(n+2, 3)*C(n+4,5)

	ld l1, l2, l3;
	cin >> l1 >> l2 >> l3;
	ld R1 = l1/(2.*sin(PI/3));
	ld R2 = l2/(2.*sin(PI/4));
	ld R3 = l3/(2.*sin(PI/5));
	ld S1 = 3.*l1*l1/(4.*tan(PI/3));
	ld S2 = 4.*l2*l2/(4.*tan(PI/4));
	ld S3 = 5.*l3*l3/(4.*tan(PI/5));
	ld h1 = sqrt(l1*l1 - R1*R1);
	ld h2 = sqrt(l2*l2 - R2*R2);
	ld h3 = sqrt(l3*l3 - R3*R3);
	ld ans = 1./3.*(S1*h1 + S2*h2 + S3*h3);
	cout.precision(20);
	cout << ans << endl;
	return 0;
}