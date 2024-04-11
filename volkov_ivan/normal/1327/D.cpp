#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 7;
int c[N], p[N];
bool vis[N];

int get(vector <int> &cycle) {
    int n = cycle.size();
    for (int i = 1; i <= n; i++) {
        if (n % i != 0) continue;
        for (int j = 0; j < i; j++) {
            int cl = c[cycle[j]];
            bool flag = 1;
            for (int t = j; t < n; t += i) {
                if (c[cycle[t]] != cl) {
                    flag = 0;
                    break;
                }
            }
            if (flag) return i;
        }
    }
    exit(-1);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        vis[i] = 0;
    }
    int res = n;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vector <int> cycle;
            int cur = i;
            while (cycle.empty() || cur != i) {
                vis[cur] = 1;
                cycle.push_back(cur);
                cur = p[cur];
            }
            res = min(res, get(cycle));
        }
    }
    cout << res << "\n";
}

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}