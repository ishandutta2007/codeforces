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
#define maxN 100005
#define oo 2000000007
#define EPS 1e-9
#define sz(a) (int)a.size()
#define BASE 316

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

int n, k, q, a[maxN], b[maxN], last;
vector<int> pos[maxN];

struct Node {
    int cnt;
    Node *l, *r;
    Node(int cnt, Node *l, Node *r): cnt(cnt), l(l), r(r) {}
};

struct PersistentIT {
private: vector<Node*> t; int n;
    Node *init(int l, int r) {
//        printf("%d %d\n", l, r);
        if (l == r) return new Node(0, NULL, NULL);
        int m = (l+r)/2;
        return new Node(0, init(l, m), init(m+1, r));
    }
    Node *update(Node *root, int l, int r, int x) {
//        printf("%d %d %d %d\n", l, r, x, root->cnt);
        if (x < l || x > r) return root;
        if (x == l && x == r) return new Node(root->cnt+1, NULL, NULL);
        int m = (l+r)/2;
        return new Node(root->cnt+1, update(root->l, l, m, x), update(root->r, m+1, r, x));
    }
    int query(Node *root, int l, int r, int x) {
//        printf("%d %d %d %d\n", l, r, x, root->cnt);
        if (r <= x) return 0;
        if (l > x) return root->cnt;
        int m = (l+r)/2;
        return query(root->l, l, m, x)+query(root->r, m+1, r, x);
    }
public:
    PersistentIT(int n, int a[]): n(n) {
//        fto(i, 1, n) printf("%d ", a[i]);
//        puts("");
        t.assign(n+1, new Node(0, NULL, NULL));
        t[0] = init(1, n+1);
        fto(i, 1, n) {
//            debug(i);
            t[i] = update(t[i-1], 1, n+1, a[i]);
        }
//        exit(0);
    }
    int query(int l, int r, int x) {
//        printf("%d %d %d\n", l, r, x);
        return query(t[r], 1, n+1, x)-query(t[l-1], 1, n+1, x);
    }
};


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 1, n) scanf("%d", &a[i]);

    fdto(i, n, 1) {
        if (sz(pos[a[i]]) < k) b[i] = n+1;
        else b[i] = pos[a[i]][sz(pos[a[i]])-k];
        pos[a[i]].pb(i);
    }

//    fto(i, 1, n) printf("%d ", b[i]);
//    puts("");

    PersistentIT t(n, b);

//    fto(l, 1, n) {
//        fto(r, l, n) {
//            printf("%d %d %d\n", l, r, t.query(l, r, 2));
//        }
//    }

    //return 0;

    scanf("%d", &q);
    fto(i, 1, q) {
        int l, r;
        scanf("%d%d", &l, &r);
        l = ((l+last)%n)+1;
        r = ((r+last)%n)+1;
        if (l > r) swap(l, r);

//        printf("%d %d\n", l, r);
        int ans = t.query(l, r, r);

        printf("%d\n", ans);
        last = ans;
    }

    return 0;
}