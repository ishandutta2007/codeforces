#include <iostream>
#include <memory.h>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),a.end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) SORT(a),(a).resize(unique(ALL(a))-a.begin())
#define SZ(a) ((int) a.size())
#define pb push_back

#define VAR(a,b) __typeof(b) a=(b)
#define FORE(it,a) for(VAR(it,(a).begin());it!=(a).end();it++)
#define X first
#define Y second
#define DEBUG(x) cout << #x << " = " << x << endl;

#define INF 1000000000

typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long ll;

double d[128];
double p[128];
double prob[128][128];

int main() {
    #ifdef LocalHost
    freopen ("input.txt", "r", stdin);
    #endif
    int n;    
    cin >> n;
    int k;
    double eps;
    cin >> k >> eps;
    eps /= 1000;
    double r1 = 0, r2 = 1e8;
    double xx, yy;
    cin >> xx >> yy;
    double xs, ys;
    REP (i, n) {
	cin >> xs >> ys;
	d[i] = sqrt((xs-xx)*(xs-xx)+(ys-yy)*(ys-yy));
    }
    REP (it, 1000) {
	double r = (r1 + r2) / 2;
	REP (i, n)
	    if (d[i] <= r)
		p[i] = 1;
	    else
		p[i] = exp(1-d[i]*d[i]/r/r);
	memset(prob, 0, sizeof (prob));
	prob[0][0] = 1;
	REP (i, n) {
	    REP (j, i+1) {
		prob[i+1][j+1] += prob[i][j] * p[i];
		prob[i+1][j] += prob[i][j] * (1-p[i]);
	    }
	}	    
	double f = 0;
	for (int i = k; i <= n; ++i)
	    f += prob[n][i];
	if (f < 1-eps)
	    r1 = r;
	else
	    r2 = r;
    }
    printf ("%.13lf\n", (r1+r2)/2);
    return 0;
}