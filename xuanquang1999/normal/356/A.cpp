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
#define maxN 300005
#define oo 3000000000000000000LL

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
    int val;
};

node t[4*maxN];

void initIT(int id, int l, int r) {
    t[id].val = -1;
    if (l == r) return;
    int mid = (l+r)/2;
    initIT(2*id, l, mid); initIT(2*id+1, mid+1, r);
}

void updateIT(int id, int l, int r, int i, int j, int x) {
    if (l > j || r < i) return;
    if (i <= l && r <= j) {t[id].val = x; return;}

    if (t[id].val != -1) {
        t[2*id+1].val = t[2*id].val = t[id].val;
        t[id].val = -1;
    }

    int mid = (l+r)/2;
    updateIT(2*id, l, mid, i, j, x); updateIT(2*id+1, mid+1, r, i, j, x);
}

void printIT(int id, int l, int r) {
    if (l == r) {printf("%d ", t[id].val); return;}
    if (t[id].val != -1) {
        t[2*id+1].val = t[2*id].val = t[id].val;
        t[id].val = -1;
    }
    int mid = (l+r)/2;
    printIT(2*id, l, mid); printIT(2*id+1, mid+1, r);
}

int n, q, l[maxN], r[maxN], x[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &q);
    fto(i, 1, q) scanf("%d%d%d", &l[i], &r[i], &x[i]);

    fdto(i, q, 1) {
        updateIT(1, 1, n, l[i], x[i]-1, x[i]);
        updateIT(1, 1, n, x[i]+1, r[i], x[i]);
    }
    printIT(1, 1, n);


    return 0;
}