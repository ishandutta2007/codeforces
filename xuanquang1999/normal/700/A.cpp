//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 200005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int m, n, l, v1, v2, k;

bool Check(double x) {
    double curT = 0;
    fto(i, 1, m) {
        //double lenLeft = (l - v1*curT);
        double t = 1.0 * (l - x*v1)/(v2 - v1);
        double exT = 1.0 * (v2-v1)*t/(v1 + v2);

        curT += t;
        if (i < m) curT += exT;

//        debug(t);
//        debug(exT);
//        debug(curT);
        if (curT > x) return false;
    }
    return true;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d%d%d", &n, &l, &v1, &v2, &k);
    m = (n+k-1)/k;
//    debug(Check(4.7142857143));
    double le = 0, ri = (1.0*l)/v1, res = ri;
    fto(i, 0, 100) {
        double mid = (le+ri)/2;
        if (Check(mid)) {
            res = min(res, mid);
            ri = mid;
        }
        else le = mid;
    }

    cout << setprecision(10) << res;

    return 0;
}