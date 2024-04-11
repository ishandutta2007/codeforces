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
#define maxN 400005
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

int k, cnt, last, q, g1[20][maxN], g2[20][maxN], maxG1[20][maxN], h2[maxN];
ll sumG2[20][maxN];



int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &q);
    k = log2(q);
    cnt = 1;
    h2[cnt] = 1;
    maxG1[0][cnt] = 0;
    g1[0][cnt] = 0;

    fto(iq, 1, q) {
        int type; ll p, q;
        scanf("%d%lld%lld", &type, &p, &q);
        if (type == 1) {
            int r = p^last, w = q^last;
//            printf("%d %d %d\n", type, r, w);
            ++cnt;

            g1[0][cnt] = r;
            maxG1[0][cnt] = w;
            fto(i, 1, k) {
                g1[i][cnt] = g1[i-1][g1[i-1][cnt]];
                maxG1[i][cnt] = max(maxG1[i-1][cnt], maxG1[i-1][g1[i-1][cnt]]);
            }
//            puts("g1");
//            fto(i, 0, k) printf("%d %d\n", g1[i][cnt], maxG1[i][cnt]);

            int u = r;
            fdto(i, k, 0) {
                if (maxG1[i][u] < w) u = g1[i][u];
            }
            g2[0][cnt] = u;
            sumG2[0][cnt] = w;
            h2[cnt] = h2[u]+1;
            fto(i, 1, k) {
                g2[i][cnt] = g2[i-1][g2[i-1][cnt]];
                sumG2[i][cnt] = sumG2[i-1][cnt] + sumG2[i-1][g2[i-1][cnt]];
            }
//            puts("g2");
//            fto(i, 0, k) printf("%d %lld\n", g2[i][cnt], sumG2[i][cnt]);
        } else {
            int r = p^last; ll w = q^last;
//            printf("%d %d %lld\n", type, r, w);

            int u = r, ans = 0;
            fdto(i, k, 0) {
                if (sumG2[i][u] <= w) {
                    ans += 1<<i;
                    w -= sumG2[i][u];
                    u = g2[i][u];
                }
            }
            ans = min(ans, h2[r]);
            printf("%d\n", ans);
            last = ans;
        }
    }

    return 0;
}