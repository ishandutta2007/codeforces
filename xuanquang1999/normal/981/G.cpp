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
#define MOD 998244353
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

struct Node {
    int sum;
    int mul;
    int add;
};

int n, q;
Node t[4*maxN];
map<int, int> m[maxN];

int mul(int a, int b) {
    return (1LL*a*b)%MOD;
}

int add(int a, int b) {
    return (a+b)%MOD;
}

void propagate(int id, int l, int r) {
    if (t[id].mul != 1) {
        int x = t[id].mul;
        fto(i, 0, 1) {
            t[2*id+i].mul = mul(t[2*id+i].mul, x);
            t[2*id+i].sum = mul(t[2*id+i].sum, x);
            t[2*id+i].add = mul(t[2*id+i].add, x);
        }
        t[id].mul = 1;
    }
    if (t[id].add != 0) {
        int m = (l+r)/2;
        int x = t[id].add;
        t[2*id].sum = add(t[2*id].sum, mul(x, m-l+1));
        t[2*id+1].sum = add(t[2*id+1].sum, mul(x, r-m));
        fto(i, 0, 1)
            t[2*id+i].add = add(t[2*id+i].add, x);
        t[id].add = 0;
    }
}

void updateAdd(int id, int l, int r, int i, int j, int x) {
    if (r < i || l > j) return;
    if (i <= l && r <= j) {
        t[id].sum = add(t[id].sum, mul(x, r-l+1));
        t[id].add = add(t[id].add, x);
        return;
    }
    propagate(id, l, r);
    int m = (l+r)/2;
    updateAdd(2*id, l, m, i, j, x); updateAdd(2*id+1, m+1, r, i, j, x);
    t[id].sum = add(t[2*id].sum, t[2*id+1].sum);
}

void updateMul(int id, int l, int r, int i, int j, int x) {
    if (r < i || l > j) return;
    if (i <= l && r <= j) {
        t[id].sum = mul(t[id].sum, x);
        t[id].mul = mul(t[id].mul, x);
        t[id].add = mul(t[id].add, x);
        return;
    }
    propagate(id, l, r);
    int m = (l+r)/2;
    updateMul(2*id, l, m, i, j, x); updateMul(2*id+1, m+1, r, i, j, x);
    t[id].sum = add(t[2*id].sum, t[2*id+1].sum);
}

int query(int id, int l, int r, int i, int j) {
    if (r < i || l > j) return 0;
    if (i <= l && r <= j) return t[id].sum;
    propagate(id, l, r);
    int m = (l+r)/2;
    return add(query(2*id, l, m, i, j), query(2*id+1, m+1, r, i, j));
}

void addQuery(int l, int r, int x) {
//    printf("l, r, x: %d %d %d\n", l, r, x);
    int last = l-1;

    vector<ii> upd;
    map<int, int>::iterator it = --m[x].lower_bound(l);
    if (it->ss >= l) {
        int hi = min(r, it->ss);
//        printf("before: %d %d %d\n", l, hi, 1);
        updateAdd(1, 1, n, l, hi, 1);
        last = hi;
        upd.pb(mp(it->ff, l-1));
        if (it->ss > r)
            upd.pb(mp(r+1, it->ss));
    }
    ++it;

    while (it->ff <= r) {
//        printf("%d %d %d\n", last+1, it->ff-1, 2);
        updateMul(1, 1, n, last+1, it->ff-1, 2);
        upd.pb(mp(it->ff, -1));
        int hi = it->ss;
        if (it->ss > r) {
            hi = r;
            upd.pb(mp(r+1, it->ss));
        }
//        printf("%d %d %d\n", it->ff, hi, 1);
        updateAdd(1, 1, n, it->ff, hi, 1);
        last = hi;
        ++it;
    }
//    printf("after: %d %d %d\n", last+1, r, 2);
    updateMul(1, 1, n, last+1, r, 2);

    for(ii p: upd) {
        if (p.ss == -1) m[x].erase(p.ff);
        else m[x][p.ff] = p.ss;
    }
//    for(ii p: m[x]) printf("%d %d\n", p.ff, p.ss);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &q);
    fto(i, 1, 4*n) t[i].mul = 1;
    fto(i, 1, n) {
        m[i][1] = n;
        m[i][n+1] = n+1;
        m[i][0] = 0;
    }

    fto(i, 1, q) {
        int type, l, r, x;
        scanf("%d%d%d", &type, &l, &r);
        if (type == 1) {
            scanf("%d", &x);
            addQuery(l, r, x);
        } else {
            printf("%d\n", query(1, 1, n, l, r));
        }
    }

    return 0;
}