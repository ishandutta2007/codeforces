#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

bool al = true;
vector<int> a(5010), b(5010), c(5010);
vector<vector<int>> e(5050);

void dfs(int i) {
    if (!al)
        return;
    c[i] = 1;
    for (auto to : e[i]) {
        if (c[to] == 0)
            dfs(to);
        else if (c[to] == 1) {
            al = false;
            break;
        }
    }
    c[i] = 2;
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    rep(i, 0, m) {
        cin >> a[i] >> b[i];
        e[a[i]].push_back(b[i]);
    }
    rep(i, 1, n + 1) {
        dfs(i);
    }
    if (al) {
        cout << 1 << endl;
        rep(i, 0, m) cout << 1 << ((i != m - 1) ? ' ' : '\n');
    } else {
        cout << 2 << endl;
        rep(i, 0, m) cout << (a[i] > b[i]) + 1 << ((i != m - 1) ? ' ' : '\n');
    }

    return 0;
}