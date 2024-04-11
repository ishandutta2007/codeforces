#include <bits/stdc++.h>

using namespace std;

const int N = 500;

vector<int> v, g[N];
int used[N], n, nom[N];
string a[N];

void dfs(int x) {
    used[x] = true;
    for (int i = 0; i < g[x].size(); i++) {
        if (!used[g[x][i]]) dfs(g[x][i]);
    }
    v.push_back(x);
}

int main() {
//  freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        bool found = false;
        for (int j = 0; j < min(a[i].size(), a[i + 1].size()); j++) {
            if (a[i][j] != a[i + 1][j]) {
                g[a[i][j] - 'a'].push_back(a[i + 1][j] - 'a');
                found = true;
                break;
            }
        }
        if (!found) {
            if (a[i].size() > a[i + 1].size()) {
                puts("Impossible");
                return 0;
            }
            continue;
        }
    }
    v.clear();
    memset(used, 0, sizeof(used));
    for (int i = 0; i < 26; i++) {
        if (!used[i]) dfs(i);
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) nom[v[i]] = i;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            int y = g[i][j];
            if (nom[i] > nom[g[i][j]]) {
                puts("Impossible");
                return 0;
            }
        }
    }
    for (int i = 0; i < v.size(); i++) putchar(v[i] + 'a');
}