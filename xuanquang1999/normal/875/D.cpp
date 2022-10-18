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
#define maxN 200005
#define maxK 20
#define sz(a) (int)a.size()
#define oo 1000000000000000007LL

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

bool cmp(const point &a, const point &b) {
    return a.X < b.X;
}

int n, k, a[maxN], m[maxK][maxN], o[maxK][maxN], l2[maxN];

void buildMax() {
    fto(j, 1, n) m[0][j] = a[j];
    fto(i, 1, k) {
        fto(j, 1, n-(1<<i)+1) m[i][j] = max(m[i-1][j], m[i-1][j+(1<<(i-1))]);
    }
}

int queryMax(int l, int r) {
    int i = l2[r-l+1];
    return max(m[i][l], m[i][r-(1<<i)+1]);
}

void buildOr() {
    fto(j, 1, n) o[0][j] = a[j];
    fto(i, 1, k) {
        fto(j, 1, n-(1<<i)+1) o[i][j] = o[i-1][j] | o[i-1][j+(1<<(i-1))];
    }
}

int queryOr(int l, int r) {
    int i = l2[r-l+1];
    return o[i][l] | o[i][r-(1<<i)+1];
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);

    fto(i, 1, n) l2[i] = log2(i);

    k = l2[n];
    buildMax();
    buildOr();

    ll ans = 0;
    fto(i, 1, n) {
        int l = i;
        while (l <= n) {
            int lo = l, hi = n, res = 0;

            int orIL = queryOr(i, l);
            while (lo <= hi) {
                int mid = (lo+hi)/2;
                if (queryOr(i, mid) <= orIL) {
                    res = mid;
                    lo = mid+1;
                } else hi = mid-1;
            }

            int r = res, orIR = queryOr(i, r);

            lo = l, hi = r, res = l-1;
            while (lo <= hi) {
                int mid = (lo+hi)/2;
                if (queryMax(i, mid) < orIR) {
                    res = mid;
                    lo = mid+1;
                } else hi = mid-1;
            }

            ans += res-l+1;
            l = r+1;
        }
    }

    printf("%lld", ans);

    return 0;
}