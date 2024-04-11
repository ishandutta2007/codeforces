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

struct Node {
    int cnt;
    Node *l, *r;
    Node(int cnt, Node *l, Node *r): cnt(cnt), l(l), r(r) {}
};

struct PersistentIT {
private: vector<Node*> t; int n;
    Node *init(int l, int r) {
        if (l == r) return new Node(0, NULL, NULL);
        int m = (l+r)/2;
        return new Node(0, init(l, m), init(m+1, r));
    }
    Node *update(Node *root, int l, int r, int x) {
        if (x < l || x > r) return root;
        if (x == l && x == r) return new Node(root->cnt+1, NULL, NULL);
        int m = (l+r)/2;
        return new Node(root->cnt+1, update(root->l, l, m, x), update(root->r, m+1, r, x));
    }
    int query(Node *root, int l, int r, int x, int y) {
        if (r < x || l > y) return 0;
        if (x <= l && r <= y) return root->cnt;
        int m = (l+r)/2;
        return query(root->l, l, m, x, y)+query(root->r, m+1, r, x, y);
    }
public:
    PersistentIT() {}
    void init(int _n, int a[]) {
        n = _n;
        t.assign(n+1, new Node(0, NULL, NULL));
        t[0] = init(1, n);
        fto(i, 1, n) {
            t[i] = update(t[i-1], 1, n, a[i]);
        }
    }
    int query(int l, int r, int x, int y) {
        if (x > y) return 0;
        int t1 = query(t[r], 1, n, x, y), t2 = query(t[l-1], 1, n, x, y);
//        printf("%d %d %d %d %d %d\n", l, r, x, y, t1, t2);
        return t1-t2;
    }
};

ll tri(ll x) {return x*(x-1)/2;}

int n, q, p[maxN];
PersistentIT t;

ll Solve(int l, int r, int d, int u) {
    if (l > r) return 0;
    int k = (r-l+1), nu = t.query(l, r, u+1, n), nd = t.query(l, r, 1, d-1);
    ll res = tri(k)-tri(nu)-tri(nd);
//    printf("%d %d %d %d %d %d %d %lld\n", l, r, d, u, n, nd, nu, res);
    return res;
}

bool isInt(int l, int r, int x, int y) {
    if (l > r) swap(l, r);
    if (x > y) swap(x, y);
    return (!(l > y && x < r));
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

//    n = 5;
//    srand(time(NULL));
//    fto(i, 1, n) p[i] = i;
//    random_shuffle(p+1, p+n+1);
//    t.init(n, p);
//    while (true) {
//        int l, d, r, u;
//        l = rand()%n+1, r = rand()%n+1, d = rand()%n+1, u = rand()%n+1;
//        if (l > r) swap(l, r);
//        if (d > u) swap(d, u);
//        int ans = 0;
//        fto(i, 1, n) {
//            fto(j, i+1, n) {
//                if (isInt(i, j, l, r) && isInt(p[i], p[j], d, u)) ++ans;
//            }
//        }
//        if (ans != Solve(1, n, d, u)-(Solve(1, l-1, d, u)+Solve(r+1, n, d, u))) {
//            fto(i, 1, n) printf("%d ", p[i]);
//            puts("");
//            printf("%d %d %d %d\n", l, d, r, u);
//            return 0;
//        }
//    }

    scanf("%d%d", &n, &q);
    fto(i, 1, n) scanf("%d", &p[i]);
    t.init(n, p);

    fto(i, 1, q) {
        int l, d, r, u;
        scanf("%d%d%d%d", &l, &d, &r, &u);
        printf("%lld\n", Solve(1, n, d, u)-(Solve(1, l-1, d, u)+Solve(r+1, n, d, u)));
    }

    return 0;
}