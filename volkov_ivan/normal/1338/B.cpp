#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
vector <int> g[N];
int depth[N];
int mini = 1, maxi = 0;

int dfs(int v, int d = 0, int p = -1) {
    depth[v] = d;
    vector <int> cur;
    bool ch = 0, nech = 0;
    int ones = 0;
    int ret = 0;
    for (int u : g[v]) {
        if (u != p) {
            int x = dfs(u, d + 1, v);
            if (x > 0) {
                int cur = x - depth[v];
                if (cur == 1) ones++;
                ret = x;
                if (cur % 2 == 0) ch = 1;
                else nech = 1;
            } else {
                x *= -1; 
                int cur = x - depth[v];
                if (cur % 2 == 0) ch = 1;
                else nech = 1;
                ret = x;
            }
        }
    }
    if (ones > 1) maxi -= (ones - 1);
    if (ch & nech) mini = 3;
    if (ret != 0) {
        return -ret;
    }
    return depth[v];
}


int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    maxi = n - 1;
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int start = -1;
    for (int i = 1; i <= n; i++) {
        if ((int) g[i].size() >= 2) {
            start = i;
            break;
        }
    }
    dfs(start);
    cout << mini << ' ' << maxi << endl;
    return 0;
}