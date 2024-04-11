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
#define EPS 1e-9

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

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int x = 0;
    fto(i, 0, 3) {
        int p; scanf("%d", &p);
        x = x*2 + p;
    }

    if (x == 6) puts("0");
    if (x == 0) puts("0");
    if (x == 8) puts("1");
    if (x == 4) puts("0");
    if (x == 12) puts("1");
    if (x == 2) puts("0");
    if (x == 10) puts("0");
    if (x == 14) puts("1");
    if (x == 1) puts("1");
    if (x == 9) puts("1");
    if (x == 5) puts("0");
    if (x == 13) puts("0");
    if (x == 3) puts("1");
    if (x == 11) puts("1");
    if (x == 7) puts("0");
    if (x == 15) puts("1");

    return 0;
}