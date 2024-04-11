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
#define maxN 1000005
#define maxK 20
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

struct RMQ {
    vector<int> b[maxK];
    RMQ(int a[], int n) {
        int k = log2(n);
        fto(i, 0, k) b[i].resize(n+1);
        fto(j, 1, n) b[0][j] = a[j];
        fto(i, 1, k) {
            fto(j, 1, n-(1<<i)+1) b[i][j] = min(b[i-1][j], b[i-1][j+(1<<(i-1))]);
        }
    }
    int query(int l, int r) {
        int i = log2(r-l+1);
        return min(b[i][l], b[i][r-(1<<i)+1]);
    }
};

int n, dp[3][maxN], p[maxN];
bool isPrime[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    fto(i, 2, maxN-1) {
        if (p[i] == 0) isPrime[i] = true;
        for(int j = i; j < maxN; j += i) {
            if (p[j] == 0) p[j] = i;
        }
    }

    fto(x, 1, maxN-1) dp[0][x] = x;

    fto(i, 1, 2) {
        RMQ r(dp[i-1], maxN-1);
        fto(j, 1, maxN-1) {
            dp[i][j] = oo;
            if (!isPrime[j]) {
                int x = j;
                while (x > 1) {
//                    debug(x);
                    int y = p[x];
                    while (p[x] == y) x /= y;
                    dp[i][j] = r.query(j-y+1, j);
                }
            }
        }
    }
//    fto(i, 0, 2) {
//        fto(j, 1, 10) printf("%d ", dp[i][j]);
//        puts("");
//    }

    int n; scanf("%d", &n);
    printf("%d", dp[2][n]);

    return 0;
}