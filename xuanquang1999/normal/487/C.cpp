//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
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
#define oo 2000000007
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

int power(int x, int n, int MOD) {
    if (n == 0) return 1%MOD;
    if (n&1) return (1LL*x*power(x, n-1, MOD))%MOD;
    int p = power(x, n/2, MOD);
    return (1LL*p*p)%MOD;
}

int n, a[maxN], p[maxN];
bool avail[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    if (n == 4) {
        puts("YES");
        puts("1");
        puts("3");
        puts("2");
        puts("4");
        return 0;
    }

    a[1] = 1;
    fto(i, 2, n-1) a[i] = (1LL*i*power(i-1, n-2, n))%n;
    a[n] = n;

    memset(avail, true, sizeof avail);
    fto(i, 1, n) {
        p[i] = (i > 1) ? (p[i-1]*a[i]) : a[i];
        if (!avail[a[i]]) {
            puts("NO");
            return 0;
        }
        avail[a[i]] = false;
    }

    puts("YES");
    fto(i, 1, n) printf("%d\n", a[i]);

    return 0;
}