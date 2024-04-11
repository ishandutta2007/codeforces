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
#define maxN 3005
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

struct Voter {
    int p, c;
    bool inline operator < (const Voter &rhs) const {
        return c < rhs.c;
    }
};

int n, m;
vector<int> a[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) {
        int p, c;
        scanf("%d%d", &p, &c);
        a[p].pb(c);
    }
    fto(p, 1, m)
        sort(a[p].begin(), a[p].end());

    ll ans = oo;
    fto(x, sz(a[1]), n) {
        ll sum = 0;
        int cur = sz(a[1]);

        vector<int> cand;
        fto(p, 2, m) {
            int tmp = sz(a[p]);
            for(int c: a[p]) {
                if (tmp >= x) {
                    --tmp;
                    sum += c;
                    ++cur;
                } else
                    cand.pb(c);
            }
        }

        sort(cand.begin(), cand.end());
        for(int c: cand) {
            if (cur < x) {
                ++cur;
                sum += c;
            }
        }
        if (cur >= x)
            ans = min(ans, sum);
    }

    printf("%lld", ans);

    return 0;
}