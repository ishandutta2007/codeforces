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

struct IT {
private: vector<int> t; int n;
    void update(int id, int l, int r, int p, int x) {
        if (l > p || r < p) return;
        if (l == p && r == p) {
            t[id] = max(t[id], x);
            return;
        }
        int m = (l+r)/2;
        update(2*id, l, m, p, x); update(2*id+1, m+1, r, p, x);
        t[id] = max(t[2*id], t[2*id+1]);
    }
    int query(int id, int l, int r, int i, int j) {
        if (l > j || r < i) return 0;
        if (i <= l && r <= j) return t[id];
        int m = (l+r)/2;
        return max(query(2*id, l, m, i, j), query(2*id+1, m+1, r, i, j));
    }
public:
    IT(int n): n(n) {t.assign(4*n+1, 0);}
    void update(int p, int x) {update(1, 1, n, p, x);}
    int query(int i, int j) {return query(1, 1, n, i, j);}
};

int n, k, a[maxN], fl[maxN], fr[maxN];

void compress(int a[], int n, int &k) {
    set<int> s; map<int, int> m;
    fto(i, 1, n) {
        s.insert(a[i]);
        s.insert(a[i]+1);
    }

    k = 0;
    for(int x: s) m[x] = ++k;

    fto(i, 1, n) a[i] = m[a[i]];
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        scanf("%d", &a[i]);
        a[i] -= i;
    }

    compress(a, n, k);

    vector<int> v;
    fto(i, 1, n) {
        int p = upper_bound(v.begin(), v.end(), a[i])-v.begin();
        fl[i] = p+1;
        if (p == sz(v)) v.pb(a[i]);
        else v[p] = a[i];
    }

    v.clear();
    fdto(i, n, 1) {
        int p = upper_bound(v.begin(), v.end(), -a[i])-v.begin();
        fr[i] = p+1;
        if (p == sz(v)) v.pb(-a[i]);
        else v[p] = -a[i];
    }

//    fto(i, 1, n) printf("%d ", a[i]);
//    puts("");
//    fto(i, 1, n) printf("%d %d\n", fl[i], fr[i]);

    IT t(k);
    int ans = min(n, *max_element(fl+1, fl+n+1)+1);
    fto(i, 1, n) {
        if (i > 1) t.update(a[i-1], fl[i-1]);
        ans = max(ans, t.query(1, a[i+1]+1)+fr[i+1]+1);
    }

    printf("%d", n-ans);

    return 0;
}