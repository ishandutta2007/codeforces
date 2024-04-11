//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 105
#define oo 1000000000007LL

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, m, p, c[maxN], a[maxN][maxN];
ll f[maxN][maxN][maxN], minL[maxN][maxN][maxN];

void mini(ll &a, ll b) {
    a = min(a, b);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &p);
    fto(i, 1, n) scanf("%d", &c[i]);
    fto(i, 1, n) {
        fto(j, 1, m) scanf("%d", &a[i][j]);
    }

    ll ans = oo;
    fto(j, 1, m) {
        fto(k, 1, p) {
            if (k == 1 && (c[1] == 0 || j == c[1])) f[1][j][k] = a[1][j]*(c[1] == 0);
            else f[1][j][k] = oo;
        }
    }

    fto(i, 2, n) {
        //debug(i);
        fto(j, 1, m) {
            fto(k, 1, p) {
                f[i][j][k] = oo;
                if (c[i] == 0 || j == c[i]) {
                    fto(pj, 1, m) {
                        if ((k > (pj != j)) && (c[i-1] == 0 || pj == c[i-1])) {
//                            printf("%d %d %d %lld %d\n", i, j, k, f[i-1][pj][k-(pj != j)], a[i][j]);
                            mini(f[i][j][k], f[i-1][pj][k-(pj != j)]+a[i][j]*(c[i] == 0));
                        }
                    }
                }

            }
        }
    }
//    fto(i, 1, n) {
//        debug(i);
//        fto(j, 1, m) {
//            fto(k, 1, p) {
//                printf("%lld ", f[i][j][k]);
//            }
//            puts("");
//        }
//    }

    fto(j, 1, m) mini(ans, f[n][j][p]);
    if (ans == oo) ans = -1;
    cout << ans;

    return 0;
}