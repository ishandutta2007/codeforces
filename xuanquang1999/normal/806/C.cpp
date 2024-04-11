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
#define maxN 100005
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

int n, cnt[40], cntTrash[40];


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        ll x; scanf("%lld", &x);
        ll cur = 1, ansP = -1;
        fto(p, 0, 40) {
            if (cur > x) {
                ansP = p-1;
                break;
            } else cur *= 2;
        }
        if (cur == 2*x) ++cnt[ansP];
        else ++cntTrash[ansP];
    }

    fto(p, 1, 39) {
        cntTrash[p] += max(0, cnt[p]-cnt[p-1]);
        cnt[p] = min(cnt[p], cnt[p-1]);
    }

//    fto(p, 0, 39) printf("%d ", cnt[p]);
//    puts("");
//    fto(p, 0, 39) printf("%d ", cntTrash[p]);
//    puts("");

//    fto(p, 0, 39) printf("%d ", cnt[p]);
//    puts("");
//    debug(trash);

    vector<int> ans;
    fdto(i, cnt[0], 1) {
        int sumRow[40];
        sumRow[39] = cnt[39];
        fto(p, 0, 38) sumRow[p] = cnt[p]-cnt[p+1];

        bool ok = true;
        int sum = 0;
        fdto(p, 39, 0) {
            sum += sumRow[p];
            if (sum < cntTrash[p]) {
                ok = false;
                break;
            }
            sum -= cntTrash[p];
        }
        if (!ok) break;

        fto(p, 0, 39) {
            if (cnt[p] == i) {
                --cnt[p];
                ++cntTrash[p];
            }
        }
        ans.pb(i);
    }

    if (sz(ans) == 0) puts("-1");
    else {
        sort(ans.begin(), ans.end());
        forit(it, ans) printf("%d ", *it);
    }

    return 0;
}