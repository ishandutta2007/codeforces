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

struct cmp {
    bool operator() (const ii &a, const ii &b) {
        return (a.ff > b.ff || (a.ff == b.ff && a.ss < b.ss));
    }
};

int n, a[maxN];
set<ii> s;
set<ii, cmp> len;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%d", &a[i]);

    int last = 0;
    fto(i, 1, n-1) {
        if (a[i] != a[i-1]) {
            s.insert(mp(last, i-last));
            len.insert(mp(i-last, last));
//            printf("%d %d\n", i, last);
            last = i;
        }
    }

    s.insert(mp(last, n-last));
    s.insert(mp(n, 0));
    len.insert(mp(n-last, last));

    int ans = 0;
    while (sz(len) > 0) {
//        puts("s:");
//        for(ii p: s) printf("%d %d\n", p.ff, p.ss);
//        puts("len:");
//        for(ii p: len) printf("%d %d\n", p.ff, p.ss);

        ++ans;
        set<ii>::iterator it = len.begin();
        int p = it->ss, l = it->ff; len.erase(it);

        it = s.find(mp(p, l));
        if (it != s.begin()) {
            int p1 = prev(it)->ff, l1 = prev(it)->ss;
            int p2 = next(it)->ff, l2 = next(it)->ss;
            if (a[p1] == a[p2]) {
                len.erase(mp(l1, p1));
                len.erase(mp(l2, p2));
                s.erase(prev(it), next(it, 2));

                s.insert(mp(p1, l1+l2));
                len.insert(mp(l1+l2, p1));
            } else s.erase(it);
        } else s.erase(it);
    }

    cout << ans;

    return 0;
}