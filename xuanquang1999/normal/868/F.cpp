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
#define maxN 100005
#define maxK 25
#define oo 1000000000000000007LL
#define sz(a) (int)a.size()
#define next abfiaefiob

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

struct Node {
    int l, r, xmin, xmax;
};

int n, k, a[maxN], cnt[maxN], curL, curR;
ll dp[maxK][maxN], curAns;
vector<Node> cur, next;

void inc(int i) {
    curAns += cnt[a[i]];
    ++cnt[a[i]];
}

void dec(int i) {
    --cnt[a[i]];
    curAns -= cnt[a[i]];
}

ll query(int l, int r) {
    while (curL < l) dec(curL++);
    while (curL > l) inc(--curL);
    while (curR < r) inc(++curR);
    while (curR > r) dec(curR--);
    return curAns;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 1, n) scanf("%d", &a[i]);
    curL = 1; curR = 0;

    dp[0][0] = 0;
    fto(i, 1, n) dp[0][i] = oo;
    fto(j, 1, k) {
        cur.pb({1, n, 1, n});
        while (!cur.empty()) {
            fto(iter, 0, sz(cur)-1) {
                int l = cur[iter].l, r = cur[iter].r, xmin = cur[iter].xmin, xmax = cur[iter].xmax;
                int m = (l+r)/2, best = 0;
                dp[j][m] = oo;
                fto(i, xmin, min(m, xmax)) {
                    ll x = query(i, m);
                    if (x+dp[j-1][i-1] < dp[j][m]) {
                        dp[j][m] = x+dp[j-1][i-1];
                        best = i;
                    }
                }
                if (l < r) {
                    next.pb({l, m, xmin, best});
                    next.pb({m+1, r, best, xmax});
                }
            }
            cur.clear();
            cur.swap(next);
        }
    }

    printf("%lld\n", dp[k][n]);

    return 0;
}