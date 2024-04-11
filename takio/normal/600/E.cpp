#include <bits/stdc++.h>
#define xx first
#define yy second
#define LL long long
using namespace std;

const int N = 200100;
int c[N], mx[N], vis[N];
LL sum[N], res[N];

map <int, int> st[N];
map <int, int> :: iterator it;
vector <int> g[N];

int dfs (int u, int fa) {
//    cout << u << ' ' << fa << endl;
//    printf ("%d %d\n", u, fa);
    vis[u] = 1;
    int now = u;
    mx[u] = 1;
    sum[u] = c[u];
    st[now][c[u]] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (vis[v]) continue;
        int tmp = dfs (v, u);
        if (st[now].size() < st[tmp].size()) {
            swap (now, tmp);
        }
//        if (st[now].size() > st[tmp].size()) {
            for (it = st[tmp].begin(); it != st[tmp].end(); it++) {
                int c = (*it).xx;
                int cc = (st[now][c] += (*it).yy);
//                cout << "1    " << c << ' ' << cc << endl;
                if (mx[now] < cc) mx[now] = cc, sum[now] = 0;
                if (mx[now] == cc) sum[now] += c;
            }
//        } else {
////            mx[now] = mx[tmp];
////            sum[now] = sum[tmp];
//            for (it = st[now].begin(); it != st[now].end(); it++) {
//                int c = (*it);
//                st[tmp].insert (c);
//                int cc = st[tmp].count(c);
////                cout << "2    " << c << ' ' << cc << endl;
//                if (mx[tmp] < cc) mx[tmp] = cc, sum[tmp] = 0;
//                if (mx[tmp] == cc) sum[tmp] += c;
//            }
//            now = tmp;
//        }
//        cout << u << ' ' << mx[now] << ' ' << sum[now] << endl;
    }
    res[u] = sum[now];
    return now;
}

int main () {
//    freopen ("in.txt", "r", stdin);
//    freopen ("out.txt", "w", stdout);
//    freopen ("in.txt", "w", stdout);
//    cout << 30000 << endl;
//    for (int i = 1; i <= 30000; i++) cout << i << ' ';
//    for (int i = 1; i < 30000; i++) cout << i << ' ' << i + 1 << ' '; return 0;
    int n;
    cin >> n;
//    st[0].insert(1);
//    st[0].insert(1);
//    cout << st[0].count(1) << endl;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &c[i]);
    }
    int u, v;
    for (int i = 1; i < n; i++) {
        scanf ("%d%d", &u, &v);
        g[u].push_back (v);
        g[v].push_back (u);
    }
    dfs (1, 0);
    for (int i = 1; i <= n; i++) printf ("%I64d ", res[i]);
}