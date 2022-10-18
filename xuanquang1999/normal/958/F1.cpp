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

int reduce(int &a, int &b) {
    fto(i, 2, min(a, b))
        while (a%i == 0 && b%i == 0) {
            a /= i;
            b /= i;
        }
}

int n, m, a[maxN], cnt[maxN], k[maxN];


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(i, 1, m) scanf("%d", &k[i]);

    fto(l, 1, n) {
        fto(r, l, n) {
            memset(cnt, 0, sizeof cnt);
            fto(i, l, r) ++cnt[a[i]];
            bool ok = true;
            fto(i, 1, m) {
                if (cnt[i] != k[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                puts("YES");
                return 0;
            }
        }
    }

    puts("NO");

    return 0;
}