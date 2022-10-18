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
#define maxN 300005
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

int n, a[maxN], p[maxN];

struct Node {
    Node *next[2];
    int cnt;
    Node() {
        fto(b, 0, 1) next[b] = NULL;
        cnt = 0;
    }
};

void add(Node *r, int x, int i) {
    if (i == -1) {
        ++r->cnt;
        return;
    }

    int b = ((x>>i)&1);
    if (r->next[b] == NULL) r->next[b] = new Node();
    add(r->next[b], x, i-1);
}

int query(Node *r, int x, int i) {
    if (i == -1) return 0;

    int b = ((x>>i)&1);
    if (r->next[b]) return query(r->next[b], x, i-1);
//    printf("%d %d %d\n", x, i, b);
    return (1<<i)+query(r->next[b^1], x, i-1);
}

void del(Node *&r, int x, int i) {
    if (i == -1) {
        --r->cnt;
        if (r->cnt == 0) r = NULL;
        return;
    }

    int b = ((x>>i)&1);
//    printf("%d %d %d\n", x, i, b);
    del(r->next[b], x, i-1);
    if (r->next[0] == NULL && r->next[1] == NULL) r = NULL;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(i, 1, n) scanf("%d", &p[i]);

    Node *root = new Node();
    fto(i, 1, n) add(root, p[i], 29);

    fto(i, 1, n) {
//        debug(i);
        int x = query(root, a[i], 29);
        printf("%d ", x);
//        debug(x);
        del(root, x^a[i], 29);
    }

    return 0;
}