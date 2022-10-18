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
#define X real()
#define Y imag()
#define maxN 200005
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

struct BIT {
    vector<int> t;
    BIT(int n) {t.assign(n+1, 0);}
    void update(int p, int x) {
        for(int i = p; i < t.size(); i += i&(-i)) t[i] += x;
    }
    int query(int p) {
        int res = 0;
        for(int i = p; i > 0; i -= i&(-i)) res += t[i];
        return res;
    }
    int query(int l, int r) {
        return query(r+1)-query(l);
    }
};

int n, ans[maxN];
ii a[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) {
        scanf("%d", &a[i].ff);
        a[i].ss = i;
    }

    sort(a, a+n);

    BIT t(n);

    int j = 0;
    fto(i, 0, n-1) {
        while (a[j].ff < a[i].ff) t.update(a[j++].ss+1, 1);
        int p = a[i].ss;
        for(int k = 1; k < n && p*k+1 < n; ++k) {
            int l = p*k+1, r = min(n-1, (p+1)*k);
//            printf("%d %d %d\n", k, l, r);
            ans[k] += t.query(l, r);
        }
    }

    fto(k, 1, n-1) printf("%d ", ans[k]);

    return 0;
}