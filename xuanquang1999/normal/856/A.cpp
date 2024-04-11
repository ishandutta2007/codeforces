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
#define maxN 105
#define maxX 1000005
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

int nTest, n, a[maxN], b[maxN];
bool avail[maxX];


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &nTest);
    fto(iTest, 1, nTest) {
        scanf("%d", &n);
        fto(i, 1, n) scanf("%d", &a[i]);

        memset(avail, true, sizeof avail);
        int k = 0;
        fto(x, 1, 1000000) {
            if (k == n) break;
            if (avail[x]) {
                b[++k] = x;
                fto(i, 1, n) {
                    fto(j, 1, n) {
                        if (x+a[i]-a[j] > 0) avail[x+a[i]-a[j]] = false;
                    }
                }
            }
        }

        if (k < n) puts("NO");
        else {
            puts("YES");
            fto(i, 1, n) printf("%d ", b[i]);
            puts("");
        }
    }

    return 0;
}