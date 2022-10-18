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
#define sz(a) (int)a.size()
#define maxN 20
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

int n, m, a[1<<maxN];
ll inv[maxN], rinv[maxN];

vector<int> countInv(int h, int l, int r) {
    if (l == r) return vector<int>(1, a[l]);

    vector<int> a = countInv(h+1, l, (l+r)/2);
    vector<int> b = countInv(h+1, (l+r)/2+1, r);

    int j = 0, k = 0;
    fto(i, 0, sz(a)-1) {
        while (j < sz(b) && b[j] < a[i]) ++j;
        while (k < sz(b) && b[k] <= a[i]) ++k;
        inv[h] += j; rinv[h] += sz(b)-k;
    }

    vector<int> c(r-l+1);
    merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
    return c;
}

ll P2(int x) {return 1LL<<x;}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, P2(n)-1)
        scanf("%d", &a[i]);

    countInv(0, 0, P2(n)-1);

    scanf("%d", &m);
    fto(im, 1, m) {
        int q; scanf("%d", &q);

        fto(i, n-q, n-1)
            swap(inv[i], rinv[i]);

        ll ans = 0;
        fto(i, 0, n-1)
            ans += inv[i];
        printf("%lld\n", ans);
    }


    return 0;
}