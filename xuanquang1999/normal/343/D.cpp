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
#define maxN 500005
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

struct Node {
    int sum, val;
};

int n, Q, parent[maxN], depth[maxN], heavy[maxN], subCnt[maxN], root[maxN], start[maxN], finish[maxN], dfsCount;
vector<int> ke[maxN];

Node t[4*maxN];

void initIT(int id, int l, int r) {
    t[id].sum = 0; t[id].val = -1;
    if (l == r) return;
    int m = (l+r)/2;
    initIT(2*id, l, m); initIT(2*id+1, m+1, r);
}

void updateIT(int id, int l, int r, int i, int j, int v) {
    if (l > j || r < i) return;
    if (i <= l && r <= j) {
        t[id].sum = (r-l+1)*v;
        t[id].val = v;
        return;
    }
    int m = (l+r)/2;
    if (t[id].val != -1) {
        t[2*id].val = t[id].val;
        t[2*id].sum = (m-l+1)*t[id].val;
        t[2*id+1].val = t[id].val;
        t[2*id+1].sum = (r-m)*t[id].val;
        t[id].val = -1;
    }
    updateIT(2*id, l, m, i, j, v); updateIT(2*id+1, m+1, r, i, j, v);
    t[id].sum = t[2*id].sum + t[2*id+1].sum;
}

int queryIT(int id, int l, int r, int i, int j) {
    if (l > j || r < i) return 0;
    if (i <= l && r <= j) return t[id].sum;
    int m = (l+r)/2;
    if (t[id].val != -1) {
        t[2*id].val = t[id].val;
        t[2*id].sum = (m-l+1)*t[id].val;
        t[2*id+1].val = t[id].val;
        t[2*id+1].sum = (r-m)*t[id].val;
        t[id].val = -1;
    }
    return queryIT(2*id, l, m, i, j) + queryIT(2*id+1, m+1, r, i, j);
}

void DFS(int u) {
    subCnt[u] = 1;
    forit(it, ke[u]) {
        int v = *it;
        if (parent[u] == v) continue;
        parent[v] = u;
        depth[v] = depth[u]+1;
        DFS(v);
        subCnt[u] += subCnt[v];
        if (heavy[u] == 0 || subCnt[heavy[u]] < subCnt[v]) heavy[u] = v;
    }
}

void DFS2(int u) {
    start[u] = ++dfsCount;
    if (heavy[u] != -1) DFS2(heavy[u]);
    forit(it, ke[u]) {
        int v = *it;
        if (start[v]) continue;
        DFS2(v);
    }
    finish[u] = dfsCount;
}


void HLD() {
    fto(u, 1, n) {
        parent[u] = heavy[u] = root[u] = -1;
        depth[u] = start[u] = finish[u] = 0;
    }
    DFS(1);
    fto(u, 1, n) {
        if (root[u] == -1 && (parent[u] == -1 || heavy[parent[u]] != u)) {
            int v = u;
            do {
                root[v] = u;
                v = heavy[v];
            } while (v != -1);
        }
    }
    DFS2(1);
}


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
    }
    HLD();
//    fto(u, 1, n) printf("%d %d %d %d %d %d\n", parent[u], heavy[u], depth[u], root[u], start[u], finish[u]);
    initIT(1, 1, n);
    scanf("%d", &Q);
    fto(i, 1, Q) {
        int t, u;
        scanf("%d%d", &t, &u);
        if (t == 1) {
            updateIT(1, 1, n, start[u], finish[u], 1);
        }
        else if (t == 2) {
            while (u != -1) {
                updateIT(1, 1, n, start[root[u]], start[u], 0);
                u = parent[root[u]];
            }
        }
        else if (t == 3) printf("%d\n", queryIT(1, 1, n, start[u], start[u]));
    }


    return 0;
}