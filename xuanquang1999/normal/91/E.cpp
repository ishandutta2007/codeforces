#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
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

struct line {
    int a, b, id;
    ll get(int x) {return 1LL*a*x + b;}
    bool inline operator < (const line &rhs) const {
        return make_tuple(a, b) < make_tuple(rhs.a, rhs.b);
    }
};

double inter(line l1, line l2) {
    return 1.0*(l1.b - l2.b)/(l2.a - l1.a);
}

bool isBad(line l1, line l2) {
    return (l1.a == l2.a && l1.b <= l2.b);
}

bool isBad(line l1, line l2, line l3) {
    return (inter(l3, l1) <= inter(l2, l1));
}

line getMax(line a, line b, int x) {
    return (a.get(x) > b.get(x)) ? a : b;
}

//Assumed that line are added in increasing order of a
void addLine(deque<line> &h, line l) {
    int n;
    while ((n = sz(h)) > 0 && isBad(h[n-1], l))
        h.pop_back();
    while ((n = sz(h)) > 1 && isBad(h[n-2], h[n-1], l))
        h.pop_back();
    h.push_back(l);
}

//Assumed that query is called with increasing x
line bestLine(deque<line> &h, int x) {
    while (sz(h) > 1 && h[0].get(x) < h[1].get(x))
        h.pop_front();
    return h[0];
}

deque<line> combine(deque<line> &h1, deque<line> &h2) {
    deque<line> res;
    int i = 0, j = 0, n = sz(h1), m = sz(h2);
    while (i < n && j < m) {
        if (h1[i] < h2[j]) addLine(res, h1[i++]);
        else addLine(res, h2[j++]);
    }
    while (i < n) addLine(res, h1[i++]);
    while (j < m) addLine(res, h2[j++]);
    return res;
}

struct IT {
private:
    vector<deque<line> > t;
    int n;

    void build(int id, int l, int r, line a[]) {
        if (l == r) {
            addLine(t[id], a[l]);
            return;
        }
        int m = (l+r)/2;
        build(2*id, l, m, a); build(2*id+1, m+1, r, a);
        t[id] = combine(t[2*id], t[2*id+1]);
    }

    line query(int id, int l, int r, int i, int j, int x) {
        if (l > j || r < i) return {0, 0, -1};
        if (i <= l && r <= j) return bestLine(t[id], x);
        int m = (l+r)/2;
        return getMax(query(2*id, l, m, i, j, x), query(2*id+1, m+1, r, i, j, x), x);
    }
public:
    IT(int n, line a[]): n(n) {
        t.assign(4*n+1, deque<line>());
        build(1, 1, n, a);
    }
    int query(int l, int r, int x) {
        return query(1, 1, n, l, r, x).id;
    }
};

struct Query {
    int l, r, t, id;
    bool inline operator < (const Query &rhs) const {
        return t < rhs.t;
    }
};

const int MAXN = 1e5 + 5;

int n, q, ans[MAXN];
line a[MAXN];
Query Q[MAXN];


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &q);
    fto(i, 1, n) {
        scanf("%d%d", &a[i].b, &a[i].a);
        a[i].id = i;
    }

    IT t(n, a);

    fto(i, 1, q) {
        scanf("%d%d%d", &Q[i].l, &Q[i].r, &Q[i].t);
        Q[i].id = i;
    }

    sort(Q+1, Q+q+1);
    fto(i, 1, q)
        ans[Q[i].id] = t.query(Q[i].l, Q[i].r, Q[i].t);

    fto(i, 1, q)
        printf("%d\n", ans[i]);

    return 0;
}