using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define fordit(rit, type, var) for(type::reverse_iterator rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 200005
#define oo 1000000007

double res, x1, __y1, x2, y2, vmax, t, vx, vy, wx, wy;

bool Check(double T) {
    double xS, yS;
    if (T >= t) xS = x1+((T-t)*wx+t*vx), yS = __y1+((T-t)*wy+t*vy);
    else xS = x1+(T*vx), yS = __y1+(T*vy);
    double xT = x2, yT = y2;
//    debug(xS);
//    debug(yS);
//    debug(xT);
//    debug(yT);
    //return (sqrt((xS-xT)*(xS-xT)+(yS-yT)*(yS-yT)) <= vmax*T);
    return (sqrt((xS-xT)*(xS-xT)+(yS-yT)*(yS-yT)) <= vmax*T);
}


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> x1 >> __y1 >> x2 >> y2;
    cin >> vmax >> t;
    cin >> vx >> vy;
    cin >> wx >> wy;

    double l = 0, r = oo, res = r+1;
    while (l <= r) {
        double mid = (l+r)/2;
        if (Check(mid)) {
            if (res > mid) res = mid;
            r = mid-0.0000001;
        }
        else l = mid+0.0000001;
    }

    //debug(Check(3.729935587093555327));

    cout << setprecision(11) << res;

    return 0;
}