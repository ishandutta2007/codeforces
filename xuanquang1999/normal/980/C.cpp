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
#define MOD 1000
#define oo 1000000000000000007LL
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

int n, k, gr[256];
vector<ii> p;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fill(begin(gr), end(gr), -1);

    fto(i, 0, 255) p.pb(mp(i, 1));

    fto(in, 1, n) {
        int x; scanf("%d", &x);
        int j = 0;
        fto(i, 0, sz(p)-1) {
            if (p[i].ff >= x) {
                j = i;
                break;
            }
        }

        while (j > 0 && p[j].ss+p[j-1].ss <= k) {
            p[j].ss += p[j-1].ss;
            p.erase(p.begin()+j-1);
            --j;
        }
//        for(ii pa: p) printf("%d %d\n", pa.ff, pa.ss);
        printf("%d ", p[j].ff-p[j].ss+1);
    }

    return 0;
}