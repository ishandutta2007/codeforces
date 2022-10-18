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

struct BIT {
    vector<int> t; int n;
    BIT(int n): n(n) {t.assign(n+1, 0);}
    void update(int p, int x) {
        for(int i = p; i < t.size(); i += i&(-i)) t[i] += x;
    }
    int query(int p) {
        int res = 0;
        for(int i = p; i > 0; i -= i&(-i)) res += t[i];
        return res;
    }
};

set<int> pos[256];
string s;
int n, q;
bool avail[maxN];

int get(BIT &t, int i) {
    int lo = 1, hi = n, res = n+1;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        if (t.query(mid) >= i) {
            res = mid;
            hi = mid-1;
        } else lo = mid+1;
    }
    return res;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &q);
    cin >> s;
    fto(i, 0, n-1) pos[s[i]].insert(i+1);

    BIT t(n);
    fto(i, 1, n) t.update(i, 1);

    memset(avail, true, sizeof avail);
    fto(i, 1, q) {
        int l, r; char c[2];
        scanf("%d%d%s", &l, &r, c);

        l = get(t, l); r = get(t, r);
//        printf("%d %d %d %c\n", i, l, r, c[0]);
        while (!pos[c[0]].empty()) {
            set<int>::iterator it = pos[c[0]].lower_bound(l);

            if (it != pos[c[0]].end() && *it <= r) {
//                debug(*it);
                avail[*it] = false;
                t.update(*it, -1);
                pos[c[0]].erase(it);
            } else break;
        }

//        fto(i, 1, n) printf("%d ", t.query(i));
//        puts("");
    }

    string ans;
    fto(i, 1, n) {
        if (avail[i]) ans += s[i-1];
    }

    cout << ans;

    return 0;
}