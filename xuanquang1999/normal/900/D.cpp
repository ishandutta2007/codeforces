//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define maxN 105
#define oo 2000000007
#define MOD 1000000007
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int power(int x, int n) {
    if (n == 0) return 1;
    if (n&1) return (1LL*x*power(x, n-1))%MOD;
    int p = power(x, n/2);
    return (1LL*p*p)%MOD;
}

int Solve(int n) {
    int x = n;
    vector<int> p;
    fto(i, 2, sqrt(n)) {
        if (n%i == 0) {
            while (n%i == 0) n /= i;
            p.pb(i);
        }
    }
    if (n > 1) p.pb(n);
    n = x;

    int res = 0;
    fto(b, 0, (1<<sz(p))-1) {
        int a = 1, sign = 1;
        fto(i, 0, sz(p)-1) {
            if ((b>>i)&1) a *= p[i], sign *= -1;
        }
        //printf("%d %d\n", a, sign);
        res = ((res+sign*power(2, n/a-1))%MOD + MOD)%MOD;
    }

    return res;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

//    d[0][0] = 1;
//    fto(i, 0, maxN-1) {
//        fto(j, 0, maxN-1) {
//            fto(x, 1, maxN-i)
//                d[i+x][GCD(j, x)] += d[i][j];
//        }
//    }
//
//    fto(i, 0, 10) {
//        fto(j, 0, i) printf("%d ", d[i][j]);
//        puts("");
//    }
//
//    fto(i, 1, 10) {
//        int ans = d[i][1];
//        printf("%d ", ans);
//    }
//
//    fto(i, 1, 30) debug(Solve(i));

    int x, y;
    scanf("%d%d", &x, &y);
    if (y%x == 0) printf("%d", Solve(y/x));
    else puts("0");

    return 0;
}