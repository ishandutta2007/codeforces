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
#define maxN 100005
#define oo 1000000000000000007LL
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

int n, q, v[maxN], c[maxN], fC[2];
ll dp[maxN], f[2];


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &q);
    fto(i, 1, n) scanf("%d", &v[i]);
    fto(i, 1, n) scanf("%d", &c[i]);

    fto(iq, 1, q) {
        int a, b;
        scanf("%d%d", &a, &b);
//        printf("%d %d\n", a, b);
        fto(i, 1, n) dp[i] = -oo;
        dp[0] = 0;
        fto(j, 0, 1) f[j] = fC[j] = 0;

        fto(i, 1, n) {
            ll valDif = -oo;
            fto(j, 0, 1) {
                if (fC[j] != c[i]) {
                    valDif = f[j] + (ll)b*v[i];
                    break;
                }
            }
            ll valSame = dp[c[i]] + (ll)a*v[i];
            //debug(i);
//            printf("%lld %lld\n", valDif, valSame);
//            printf("%d %d\n", v[i], c[i]);
            if (max(valDif, valSame) > dp[c[i]]) {
                dp[c[i]] = max(valDif, valSame);
                bool found = false;
                fto(j, 0, 1) {
                    if (fC[j] == c[i]) {
                        f[j] = dp[c[i]];
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    if (dp[c[i]] > f[0]) {
                        fC[1] = fC[0]; f[1] = f[0];
                        fC[0] = c[i]; f[0] = dp[c[i]];
                    } else if (dp[c[i]] > f[1]) {
                        fC[1] = c[i]; f[1] = dp[c[i]];
                    }
                } else {
                    if (f[0] < f[1]) {
                        swap(f[0], f[1]);
                        swap(fC[0], fC[1]);
                    }
                }
            }
        }

        printf("%lld\n", *max_element(dp, dp+n+1));
    }


    return 0;
}