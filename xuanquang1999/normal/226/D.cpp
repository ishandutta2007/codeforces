//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

int n, m, a[maxN][maxN], dr[maxN], dc[maxN], sr[maxN], sc[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) fto(j, 1, m) scanf("%d", &a[i][j]);

    fto(i, 1, n) {
        sr[i] = 1;
        fto(j, 1, m) dr[i] += a[i][j];
    }
    fto(j, 1, m) {
        sc[j] = 1;
        fto(i, 1, n) dc[j] += a[i][j];
    }

    while (true) {
//        fto(i, 1, n) printf("%d ", dr[i]);
//        puts("");
//        fto(i, 1, m) printf("%d ", dc[i]);
//        puts("");
        bool stop = true;
        fto(i, 1, n) {
            if (dr[i] < 0) {
                stop = false;
                fto(j, 1, m) dc[j] -= 2*a[i][j]*sr[i]*sc[j];
                dr[i] *= -1;
                sr[i] *= -1;
                break;
            }
        }
        if (!stop) continue;
        fto(j, 1, m) {
            if (dc[j] < 0) {
                stop = false;
                fto(i, 1, n) dr[i] -= 2*a[i][j]*sr[i]*sc[j];
                dc[j] *= -1;
                sc[j] *= -1;
                break;
            }
        }
        if (stop) break;
    }

    vector<int> ansR, ansC;
    fto(i, 1, n) {
        if (sr[i] == 1) ansR.pb(i);
    }
    fto(j, 1, m) {
        if (sc[j] == 1) ansC.pb(j);
    }

    printf("%d", sz(ansR));
    for(int x: ansR) printf(" %d", x);
    puts("");

    printf("%d", sz(ansC));
    for(int x: ansC) printf(" %d", x);
    puts("");

    return 0;
}