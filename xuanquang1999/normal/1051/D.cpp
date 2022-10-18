#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
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

const int MAXN = 1005;
const int MOD = 998244353;

int n, k, dp[MAXN][2*MAXN][4];

void add(int &a, int b) {a = (a+b)%MOD;}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(mask, 0, 3) {
        int x1 = (mask&1), x2 = (mask>>1)&1;
        dp[1][1 + (x1 != x2)][mask] = 1;
    }

    fto(i, 1, n-1) {
        fto(j, 1, 2*n) {
            fto(mask, 0, 3) {
                int x1 = (mask&1), x2 = (mask>>1)&1;
                fto(nxt, 0, 3) {
                    int y1 = (nxt&1), y2 = (nxt>>1)&1;
                    int comp = j;
                    if (y1 == y2)
                        comp += (y1 != x1 && y2 != x2);
                    else
                        comp += (y1 != x1) + (y2 != x2);
                    add(dp[i+1][comp][nxt], dp[i][j][mask]);
                }
            }
        }
    }

//    fto(i, 1, n) {
//        debug(i);
//        fto(j, 1, 2*n) {
//            fto(mask, 0, 3) printf("%d ", dp[i][j][mask]);
//            puts("");
//        }
//    }

    int ans = 0;
    fto(mask, 0, 3)
        add(ans, dp[n][k][mask]);
    printf("%d", ans);

    return 0;
}