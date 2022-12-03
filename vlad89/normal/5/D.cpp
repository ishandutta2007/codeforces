#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
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

double get_time (double v0, double vmax, double dist, double a)
{
//    cout << v0 << ' ' << vmax << ' ' << dist << ' ' << a << endl;
    double tmax = (vmax - v0) / a;
    double smax = a * tmax * tmax / 2 + v0 * tmax;
//    cout << smax << endl;
    if (smax > dist)
    {
        double b1 = 0;
        double b2 = tmax;
        REP (it, 100)
        {
            double mid = (b1 + b2) / 2;
            double s = a * mid * mid / 2 + v0 * mid;
            if (s > dist)
                b2 = mid;
            else
                b1 = mid;
        }
//        cout << (b1+b2)/2 << endl;
        return (b1+b2)/2;
    } else
    {
        return tmax + (dist - smax) / vmax;
    }
}

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    double a, v, l, d, w;
    cin >> a >> v >> l >> d >> w;
    
    double T = sqrt (2 * d / a);
    double V = a * T;
    
    w = min (w, v);
    double res;
    if (V <= w)
    {
        res = T + get_time (V, v, l-d, a);
    } else
    {
        double b1 = 0;
        double b2 = d;
        REP (it, 100)
        {
            double mid = (b1 + b2) / 2;
            double time_here = sqrt (2 * mid / a);
            double speed_here = time_here * a;
            speed_here = min (speed_here, v);
            double time_to_w = (speed_here - w) / a;
            double path_to_w = speed_here * time_to_w - a * time_to_w * time_to_w / 2;
//            cout << mid << ' ' << time_here << ' ' << speed_here << ' ' << time_to_w << ' ' << path_to_w << endl;            
            if (path_to_w > d - mid)
                b2 = mid;
            else
                b1 = mid;
        }
        double mid = (b1 + b2) / 2;
        double time_here = sqrt (2 * mid / a);
        double speed_here = time_here * a;
        speed_here = min (speed_here, v);
        double time_to_w = (speed_here - w) / a;
//        cout << mid << ' ' << time_here << ' ' << speed_here << ' ' << time_to_w << endl;            
        res = get_time (0, v, mid, a) + time_to_w + get_time (w, v, l-d, a);
    }
    printf ("%.13lf\n", res);
	return 0;
}