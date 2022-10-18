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
#define maxN 200005
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

int n, a[maxN], start[maxN], stop[maxN], dfsCnt;
vector<ii> ke[maxN];
vector<ll> t[4*maxN];
ll d[maxN], tmp[maxN];

void _merge(vector<ll> &a, const vector<ll> &b, const vector<ll> &c) {
    a.resize(b.size()+c.size());
    merge(b.begin(), b.end(), c.begin(), c.end(), a.begin());
}

void initIT(int id, int l, int r) {
    if (l == r) {
        t[id].pb(tmp[l]);
        return;
    }
    int mid = (l+r)/2;
    initIT(2*id, l, mid); initIT(2*id+1, mid+1, r);
    _merge(t[id], t[2*id], t[2*id+1]);
}

void DFS(int u) {
    start[u] = ++dfsCnt;
    forit(it, ke[u]) {
        int v = it->ff, e = it->ss;
        d[v] = d[u]+e;
        DFS(v);
    }
    stop[u] = dfsCnt;
}

int query(int id, int l, int r, int i, int j, ll x) {
    if (i > r || j < l) return 0;
    if (i <= l && r <= j) return upper_bound(t[id].begin(), t[id].end(), x)-t[id].begin();
    int mid = (l+r)/2;
    return query(2*id, l, mid, i, j, x) + query(2*id+1, mid+1, r, i, j, x);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(u, 1, n) scanf("%d", &a[u]);

    fto(u, 2, n) {
        int p, e;
        scanf("%d%d", &p, &e);
        ke[p].pb(mp(u, e));
    }

    DFS(1);
    fto(u, 1, n) tmp[start[u]] = d[u]-a[u];
//    fto(u, 1, n) printf("%d %d %lld\n", start[u], stop[u], d[u]);

    initIT(1, 1, n);

    fto(u, 1, n) {
        printf("%d ", query(1, 1, n, start[u], stop[u], d[u])-1);
    }

    return 0;
}