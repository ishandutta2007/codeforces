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
#define BASE 316
#define oo 2000000007
#define EPS 1e-9
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

int n, m, q, common[BASE][maxN], posLarge[maxN];
ll sum[maxN], a[maxN], prep[maxN];
vector<int> s[maxN], large, small, save;
bool avail[maxN];


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &q);
    fto(i, 0, n-1) scanf("%lld", &a[i]);

    fto(i, 0, m-1) {
        int p; scanf("%d", &p);
        s[i].resize(p);
        fto(j, 0, p-1) {
            scanf("%d", &s[i][j]); --s[i][j];
            if (p > BASE) prep[i] += a[s[i][j]];
        }

        if (p > BASE) {
            posLarge[i] = sz(large);
            large.pb(i);
        } else {
            small.pb(i);
        }
    }

    fto(i, 0, sz(large)-1) {
        forit(it, s[large[i]]) avail[*it] = true, save.pb(*it);

        fto(j, 0, m-1) {
            forit(it, s[j]) {
                if (avail[*it]) ++common[i][j];
            }
        }

        forit(it, save) avail[*it] = false;
        save.clear();
    }

//    fto(i, 0, m-1) {
//        debug(i);
//        forit(it, s[i]) printf("%d ", *it);
//        puts("");
//    }
//    puts("");
//
//    fto(i, 0, sz(large)-1) {
//        fto(j, 0, m-1) printf("%d ", common[i][j]);
//        puts("");
//    }
//    puts("");
//
//    fto(i, 0, m-1) printf("%lld ", prep[i]);
//    puts("");
//    puts("");
//
//    fto(i, 0, m-1) printf("%lld ", sum[i]);
//    puts("");
//    puts("");


    fto(iq, 1, q) {
//        debug(iq);
        char c[2]; int k;
        scanf("%s%d", c, &k); --k;

        if (c[0] == '?') {
//            forit(it, s[k]) printf("%d ", *it);
//            puts("");
            ll ans = prep[k];
            fto(i, 0, sz(large)-1) ans += common[i][k]*sum[large[i]];
            if (sz(s[k]) <= BASE) {
                fto(i, 0, sz(s[k])-1) ans += a[s[k][i]];
            }
            printf("%lld\n", ans);
        } else if (c[0] == '+') {
            int x; scanf("%d", &x);
            sum[k] += x;
            if (sz(s[k]) <= BASE) {
                fto(i, 0, sz(s[k])-1) a[s[k][i]] += x;
                fto(i, 0, sz(large)-1) prep[large[i]] += (ll)common[i][k]*x;
            }
        }
//        fto(i, 0, n-1) printf("%lld ", a[i]);
//        puts("");
//
//        fto(i, 0, m-1) printf("%lld ", prep[i]);
//        puts("");
//
//        fto(i, 0, m-1) printf("%lld ", sum[i]);
//        puts("");
    }

    return 0;
}