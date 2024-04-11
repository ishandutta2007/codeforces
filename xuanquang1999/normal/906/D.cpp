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
#define X real()
#define Y imag()
#define maxN 100005
#define oo 1000000007LL
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

int mul(ll a, ll b, int MOD) {return (a*b >= MOD) ? (a*b)%MOD + MOD : a*b;}

int power(int x, int n, int MOD) {
    if (n == 0) return 1;
    if (n&1) return mul(x, power(x, n-1, MOD), MOD);
    int p = power(x, n/2, MOD);
    return mul(p, p, MOD);
}

int power(int x, int n) {
    if (n == 0) return 1;
    if (n&1) return min(oo, 1LL*x*power(x, n-1));
    int p = power(x, n/2);
    return min(oo, 1LL*p*p);
}

int n, q, MOD, w[maxN];
unordered_map<int, int> mem;

int phi(int x) {
    if (mem[x]) return mem[x];
    int save = x;

    int res = 1;
    fto(i, 2, sqrt(x)) {
        if (x%i == 0) {
            int cur = 1;
            while (x%i == 0) {
                cur *= i;
                x /= i;
            }
//            debug(cur);
            res *= (cur-cur/i);
        }
    }
    if (x > 1) res *= x-1;

    return mem[save] = res;
}

//pair of MOD-ed value and min(actual value, 1e9+7)
int query(int l, int r, int MOD) {
    if (l == r || MOD == 1) return mul(1, w[l], MOD);
    int x = power(w[l], query(l+1, r, phi(MOD)), MOD);
//    printf("%d %d %d %d\n", l, r, MOD, x);
    return x;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

//    debug(power(6, 17, 12));
//    debug(power(6, 5, 12));
//    debug(power(6, 1, 12));
//
//    fto(i, 1, 36) {
//        fto(j, 1, 36) printf("%d ", power(i, j, 36));
//        puts("");
//    }

    scanf("%d%d", &n, &MOD);
    fto(i, 1, n) scanf("%d", &w[i]);

    scanf("%d", &q);
    fto(i, 1, q) {
        int l, r; scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r, MOD)%MOD);
    }

    return 0;
}