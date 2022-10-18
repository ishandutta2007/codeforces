//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
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
#define ll long long
#define maxN 100005
#define maxK 20
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

template <class T>
void read(vector<T> &v) {
    T x;
    cin >> x;
    v.pb(x);
}

struct node {
    int a, val;
};

node t[4*maxN];
int n, x[maxN];

int propagate(int id) {
    if (t[id].val != 0) {
        t[2*id].a += t[id].val;
        t[2*id].val += t[id].val;
        t[2*id+1].a += t[id].val;
        t[2*id+1].val += t[id].val;
        t[id].val = 0;
    }
}

void update(int id, int l, int r, int i, int j, int x) {
    if (i > r || j < l) return;
    if (i <= l && r <= j) {
        t[id].a += x;
        t[id].val += x;
        return;
    }

    propagate(id);

    int m = (l+r)/2;
    update(2*id, l, m, i, j, x); update(2*id+1, m+1, r, i, j, x);
    t[id].a = max(t[2*id].a, t[2*id+1].a);
}

int query(int id, int l, int r, int i, int j) {
    if (i > r || j < l) return -oo;
    if (i <= l && r <= j) return t[id].a;

    propagate(id);

    int m = (l+r)/2;
    return max(query(2*id, l, m, i, j), query(2*id+1, m+1, r, i, j));
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        int p, t;
        scanf("%d%d", &p, &t);
        if (t == 1) scanf("%d", &x[p]);

        update(1, 1, n, 1, p, ((t == 0) ? -1 : 1));

        int l = 1, r = n, res = -1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (query(1, 1, n, mid, n) > 0) {
                res = max(res, mid);
                l = mid+1;
            }
            else r = mid-1;
        }

        if (res != -1) res = x[res];
        printf("%d\n", res);
    }

    return 0;
}