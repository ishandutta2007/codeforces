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
ll i,j,n,k,k1,k2,k3,m,h,z,l,r,x,y;
string s1,s2,s3,s,t;
pair<pii, ll> a[100500];
int main()
{
	//freopen("input.txt", "r", stdin);
    cin >> n;
    for (i = 0; i < n; i++)
    {
    	scanf("%I64d %I64d", &a[i].X.X, &a[i].X.Y);
    	a[i].Y = i+1;
    }
    sort(a,a+n);
    if ((a[0].X.X-a[1].X.X)*(a[1].X.Y-a[2].X.Y) == (a[0].X.Y-a[1].X.Y)*(a[1].X.X-a[2].X.X))
    {
    	for (i = 3; i < n; i++)
    		if ((a[0].X.X-a[1].X.X)*(a[1].X.Y-a[i].X.Y) != (a[0].X.Y-a[1].X.Y)*(a[1].X.X-a[i].X.X))
    		{
    			cout << a[0].Y << " " << a[1].Y << " " << a[i].Y << endl;
    			return 0;
    		}
    } else
    cout << a[0].Y << " " << a[1].Y << " " << a[2].Y << endl;
	return 0;
}