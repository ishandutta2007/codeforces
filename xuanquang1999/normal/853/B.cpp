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
#define maxN 100005
#define maxX 1000005
#define oo 1000000007
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

struct flight {
    int d, u, c;
};

bool incD(const flight &a, const flight &b) {
    return (a.d < b.d);
}

bool decD(const flight &a, const flight &b) {
    return (a.d > b.d);
}

int n, m, k, cntPos;
ll dpL[maxX], dpR[maxX];
int minC[maxN];
vector<flight> f[2];



int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &k);
    fto(i, 1, m) {
        int d, s, e, c;
        scanf("%d%d%d%d", &d, &s, &e, &c);
        int t, u;
        if (e == 0) {
            t = 0; u = s;
        } else {
            t = 1; u = e;
        }
        f[t].pb({d, u, c});
    }

    sort(f[0].begin(), f[0].end(), incD);

    int cntPos = n;
    ll sum = 0;
    fto(i, 1, n) {
        minC[i] = oo;
        sum += minC[i];
    }

    int j = 0;
    fto(i, 1, maxX-1) {
        while (j < sz(f[0]) && f[0][j].d <= i) {
            int u = f[0][j].u, c = f[0][j].c;
            if (c < minC[u]) {
                if (minC[u] == oo) --cntPos;
                sum += c - minC[u];
                minC[u] = c;
            }
            ++j;
        }
        dpL[i] = (cntPos == 0) ? sum : (1LL*oo*oo);
    }

    sort(f[1].begin(), f[1].end(), decD);

    cntPos = n;
    sum = 0;
    fto(i, 1, n) {
        minC[i] = oo;
        sum += minC[i];
    }

    j = 0;
    fdto(i, maxX-1, 1) {
        while (j < sz(f[1]) && f[1][j].d >= i) {
            int u = f[1][j].u, c = f[1][j].c;
            if (c < minC[u]) {
                if (minC[u] == oo) --cntPos;
                sum += c - minC[u];
                minC[u] = c;
            }
            ++j;
        }
        dpR[i] = (cntPos == 0) ? sum : (1LL*oo*oo);
    }

    ll ans = 1LL*oo*oo;
    fto(i, 1, maxX-k-2) {
        ans = min(ans, dpL[i] + dpR[i+k+1]);
    }

    if (ans >= 1LL*oo*oo) ans = -1;
    printf("%lld", ans);

    return 0;
}