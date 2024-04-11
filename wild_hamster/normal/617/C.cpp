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
ll i,j,n,k,k1,k2,k3,m,h,z,l,r,x1,y1,x2,y2;
string s1,s2,s3,s,t;
ll x[2005],y[2005];
vector <pair<ll,ll> > f;
int main()
{
	//freopen("input.txt", "r", stdin);
    cin >> n >> x1 >> y1 >> x2 >> y2;
    for (i = 0; i < n; i++)
    	cin >> x[i] >> y[i];
    k = (ll)1e+18;
    for (i = 0; i < n; i++)
    {
    	ll r1 = (x1-x[i])*(x1-x[i]) + (y1-y[i])*(y1-y[i]);
    	ll r2 = 0;
    	for (j = 0; j < n; j++)
    		if ((x1-x[j])*(x1-x[j]) + (y1-y[j])*(y1-y[j]) > r1)
    			r2 = max(r2, (x2-x[j])*(x2-x[j]) + (y2-y[j])*(y2-y[j]));
    	k = min(k, r1+r2);
    	//cout << r1 << " " << r2 << endl;
    }
    ll r1 = 0;
    ll r2 = 0;
    	for (j = 0; j < n; j++)
    		if ((x1-x[j])*(x1-x[j]) + (y1-y[j])*(y1-y[j]) > r1)
    			r2 = max(r2, (x2-x[j])*(x2-x[j]) + (y2-y[j])*(y2-y[j]));
    	k = min(k, r1+r2);
    cout << k << endl;
	return 0;
}