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
ll i,j,n,k,k1,k2,k3,m,h,z,l,r;
string s1,s2,s3,s,t;
ll a[1005],dp[1005];
vector <pair<ll,ll> > f;
int main()
{

    cin >> n;
    for (i = 0; i < n; i++)
    	cin >> a[i];
    l = 0;
    r = n-1;
    while (a[l] == 0 && l < n)
    	l++;
    while (a[r] == 0 && r >= 0)
    	r--;
    if (l == n && r == -1)
    	cout << 0 << endl;
    else
    {
    	ll ans = 1;
    	k = 1;
    	for (i = l; i <= r; i++)
    		if (a[i] == 0)
    			k++;
    		else
    			ans *=k, k = 1;
    	cout << ans << endl;
    }
	return 0;
}