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
#define maxN 200005
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

struct prob {
    int t, a, id;
    bool inline operator < (const prob &o) const {
        return t < o.t;
    }
};

int n, T, res;
prob p[maxN];
vector<int> ans;

bool Check(int x) {
    int cnt = 0, time = 0;
    vector<int> pos;
    fto(i, 1, n) {
        if (p[i].a >= x) {
            ++cnt;
            time += p[i].t;
            pos.pb(p[i].id);
        }
        if (time > T) return false;
        if (cnt == x) {
            if (x > res) {
                res = x;
                ans.assign(pos.begin(), pos.end());
            }
            return true;
        }
    }

    return false;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &T);
    fto(i, 1, n) {
        scanf("%d%d", &p[i].a, &p[i].t);
        p[i].id = i;
    }

    sort(p+1, p+n+1);

    int lo = 1, hi = n; res = 0;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        if (Check(mid)) {
            res = mid;
            lo = mid+1;
        } else hi = mid-1;
    }

    printf("%d\n", res);
    printf("%d\n", res);
    for(int x: ans) printf("%d ", x);

    return 0;
}