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
#define maxN 400005
#define oo 3000000000000000000LL

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, m, low[maxN], num[maxN], parent[maxN], cnt, s, maxCnt = 0;
vector<int> ke[maxN];
vector<ii> bridge;
map<ii, int> id;
ii ans[maxN];

void DFS(int u) {
    num[u] = low[u] = ++cnt;
    forit(it, ke[u]) {
        int v = *it;
        if (v == parent[u]) continue;
        if (!num[v]) {
            parent[v] = u;
            DFS(v);
            if (low[v] > num[u]) {
                bridge.pb(mp(u, v));
                bridge.pb(mp(v, u));
            }
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }
}

template<class T> bool find(vector<T> &v, const T &x) {
    return binary_search(v.begin(), v.end(), x);
}

void DFS1(int u) {
    num[u] = 1;
    ++cnt;
    forit(it, ke[u]) {
        int v = *it;
        if (!num[v] && !find(bridge, mp(u, v))) DFS1(v);
    }
}

void DFS2(int u) {
    num[u] = 1;
    forit(it, ke[u]) {
        int v = *it;
        if (v == parent[u]) continue;

        int i = id[mp(u, v)];
        if (ans[i] == mp(0, 0)) ans[i] = (find(bridge, mp(u, v))) ? mp(v, u) : mp(u, v);

        if (!num[v]) {
            parent[v] = u;
            DFS2(v);
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
        id[mp(u, v)] = id[mp(v, u)] = i;
    }
    DFS(1);
    sort(bridge.begin(), bridge.end());

    memset(num, 0, sizeof num);
    fto(u, 1, n) {
        if (!num[u]) {
            cnt = 0;
            DFS1(u);
            if (cnt > maxCnt) {
                maxCnt = cnt;
                s = u;
            }
        }
    }

    memset(num, 0, sizeof num);
    memset(parent, 0, sizeof parent);
    DFS2(s);

    printf("%d\n", maxCnt);
    fto(i, 1, m) printf("%d %d\n", ans[i].ff, ans[i].ss);

    return 0;
}