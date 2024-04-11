#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define pi 3.141592653589793
const int N = 1000001;
using namespace std;
 
vector<int> a[N];
bool st[N], vis1[N];
 
void f(int u) {
    st[u] = true;
    vis1[u] = true;
    for (int v : a[u]) {
        if (st[v]) {
            cout << "Draw";
            exit(0);
        }
        if (!vis1[v]) {
            f(v);
        }
    }
    st[u] = false;
 
}
 
 
int main() {
//    cout << fixed << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
 
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n + 1; i++) {
        int x, v;
        cin >> x;
        while (x--) {
            cin >> v;
            a[i].pb(v);
        }
    }
 
    int x;
    cin >> x;
    queue<pair<int, int>> q;
    bool vis[n + 1][2];
    int par[n + 1][2];
    memset(vis, false, sizeof vis);
    q.push(mp(x, 0));
    vis[x][0] = true;
 
    while (!q.empty()) {
        auto f = q.front();
        q.pop();
        if (a[f.first].empty() && f.second) {
            cout << "Win\n";
            vector<int> ans;
            int v = f.first, typ = f.second;
            while (v != x || typ) {
                ans.pb(v);
                v = par[v][typ];
                typ = 1 - typ;
            }
            cout << x << ' ';
            for (int i = (int) ans.size() - 1; i >= 0; i--) cout << ans[i] << ' ';
            return 0;
        }
        for (int v : a[f.first]) {
            if (!vis[v][1 - f.second]) {
                vis[v][1 - f.second] = true;
                q.push(mp(v, 1 - f.second));
                par[v][1 - f.second] = f.first;
            }
        }
    }
 
    memset(st, false, sizeof st);
    memset(vis1, false, sizeof vis1);
    f(x);
    cout << "Lose";
}