#include <bits/stdc++.h>
#define pii pair <int, int>
#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 300010, C = 26;

char s[N];
int tot, c[N];
int nx[N * 2][C], sz[N * 2];
//int rt[N];
stack <int> st;
vector <int> g[N];

int newnode () {
    if (!st.empty ()) {
        int now = st.top();
        st.pop();
        memset (nx[now], -1, sizeof nx[now]);
        sz[now] = 1;
        return now;
    }
    memset (nx[tot], -1, sizeof nx[tot]);
    sz[tot] = 1;
    return tot++;
}

void merge (int now, int tmp) {
    sz[now] = 1;
    for (int i = 0; i < C; i++) {
        if (nx[tmp][i] != -1) {
            if (nx[now][i] == -1) {
                nx[now][i] = newnode ();
//                sz[now] += sz[nx[tmp][i]];
            }
//            nx[now][i] = nx[tmp][i];
            merge (nx[now][i], nx[tmp][i]);
        }
        if (nx[now][i] != -1) sz[now] += sz[nx[now][i]];
    }
}

void clear (int u) {
    st.push (u);
    for (int i = 0; i < C; i++) if (nx[u][i] != -1) {
        clear(nx[u][i]);
    }
}

int mx, res;

int dfs (int u, int fa) {
//    cout << u << endl;
    int now = newnode ();
    for (int i = 0; i < g[u].size (); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        int tmp = newnode ();
        nx[tmp][s[v]] = dfs (v, u);
        sz[tmp] += sz[nx[tmp][s[v]]];
        if (sz[now] > sz[tmp]) {
            merge (now, tmp);
            clear(tmp);
//            cout << "11111" << u << endl;
        } else {
            merge (tmp, now);
            clear(now);
//            cout << "    " << u << ' ' << sz[nx[tmp][s[v]]] << endl;
            now = tmp;
        }
//        cout << u << ' ' << v << ' ' << sz[now] << endl;
    }
    if (mx < sz[now] + c[u]) mx = sz[now] + c[u], res = 0;
    if (mx == sz[now] + c[u]) res++;
//    cout << u << ' ' << sz[now] << endl;
    return now;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf ("%d", &c[i]);
    scanf ("%s", s + 1);
    for (int i = 1; s[i]; i++) s[i] -= 'a';
    int u, v;
    for (int i = 1; i < n; i++) {
        scanf ("%d%d", &u, &v);
//        cout << u << ' ' << v << endl;
        g[u].push_back (v);
        g[v].push_back (u);
    }
    tot = 1;
    dfs (1, 0);
//    cout << "x";
//    for (int i = 1; i <= n; i++) {
//
//    }
    cout << mx << endl << res << endl;
}