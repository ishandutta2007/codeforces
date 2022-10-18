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
#define maxN 1005
#define oo 2000000007
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

int n, m, k, ans[maxN][maxN];
char condH[maxN][maxN], condV[maxN][maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &k);
    fto(i, 0, n-1) {
        scanf("%s", condH[i]);
        if (i < n-1) scanf("%s", condV[i]);
    }

    if (k == 1) {
        int cnt = 0, tot = (n-1)*m + n*(m-1);
        fto(i, 0, n-1) fto(j, 0, m-2) {
            if (condH[i][j] == 'E') ++cnt;
        }
        fto(i, 0, n-2) fto(j, 0, m-1) {
            if (condV[i][j] == 'E') ++cnt;
        }

        if (4*cnt >= 3*tot) {
            puts("YES");
            fto(i, 0, n-1) {
                fto(j, 0, m-1) printf("%d ", 1);
                puts("");
            }
        } else puts("NO");
    } else {
        if (n*(m-1) > (n-1)*m) {
            fto(i, 0, n-1) {
                ans[i][0] = 0;
                fto(j, 1, m-1) ans[i][j] = ans[i][j-1]^(condH[i][j-1] == 'N');

                if (i > 0) {
                    int cnt = 0;
                    fto(j, 0, m-1) {
                        cnt += ((ans[i][j]^ans[i-1][j]) == (condV[i-1][j] == 'N'));
                    }
                    if (2*cnt < m) {
                        fto(j, 0, m-1) ans[i][j] ^= 1;
                    }
                }
            }
        } else {
            fto(j, 0, m-1) {
                ans[0][j] = 0;
                fto(i, 1, n-1) ans[i][j] = ans[i-1][j]^(condV[i-1][j] == 'N');

                if (j > 0) {
                    int cnt = 0;
                    fto(i, 0, n-1) {
                        cnt += ((ans[i][j]^ans[i][j-1]) == (condH[i][j-1] == 'N'));
                    }
                    if (2*cnt < n) {
                        fto(i, 0, n-1) ans[i][j] ^= 1;
                    }
                }
            }
        }

        puts("YES");
        fto(i, 0, n-1) {
            fto(j, 0, m-1) printf("%d ", ans[i][j]+1);
            puts("");
        }
    }



    return 0;
}