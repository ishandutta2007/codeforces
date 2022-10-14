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
#define INF (1+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 228228
typedef long long ll;
typedef long double ld;
using namespace std;
ll n,m,k,n1,n2,i,j, x,y,l,r, coord,p,q;
ll a[500500], b[500500];
ld dist(ld x1, ld y1, ld x2, ld y2)
{
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
int main()
{
    cin >> n >> x >> y;
    ld min1 = 1e+18, max1 = -1e+18;
    for (i = 0; i < n; i++)
    {
    	ll xx, yy;
    	scanf("%I64d %I64d", &a[i], &b[i]);
    }
    for (i = 0; i < n; i++)
    {
    	long double x1 = a[i], y1 = b[i], x2 = a[(i+1)%n], y2 = b[(i+1)%n];
    	long double xx = x, yy = y;
    	//cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    	for (j = 0; j < 130; j++) {
    		long double midx1 = x1 + (x2-x1)/3;
    		long double midy1 = y1 + (y2-y1)/3;
    		long double midx2 = x2 - (x2-x1)/3;
    		long double midy2 = y2 - (y2-y1)/3;
    		if (dist(midx1, midy1, xx, yy) > dist(midx2, midy2, xx, yy))
    		{
    			x1 = midx1;
    			y1 = midy1;
    		} else 
    		{
    			x2 = midx2;
    			y2 = midy2;
    		}    	
    		//cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    	}
    	min1 = min(min1, dist(xx,yy,x1,y1));
    	max1 = max(max1, dist(xx,yy,(ld)a[i],(ld)b[i]));
    }
    ld ans = PI*(max1-min1);
    cout.precision(25);
    cout << ans << endl;
    return 0;
}