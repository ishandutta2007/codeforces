#include <bits/stdc++.h>
using namespace std;

const int N = 100;
const int A = 26;

vector<int> adj[A], order;
string author[N];
int color[N];

void dfs(int u) {
    color[u] = 1;
    for (auto c : adj[u]) {
        if (color[c] == 0) {
            dfs(c);
        } else if (color[c] == 1) {
            cout << "Impossible\n";
            exit(0);
        }
    }
    order.push_back(u);
    color[u] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> author[i];
    }

    for (int i = 1; i < n; ++i) {
        int k = (int) min(author[i - 1].size(), author[i].size());
        if (author[i - 1].substr(0, k) == author[i].substr(0, k)) {
            if (author[i - 1].size() > author[i].size()) {
                cout << "Impossible\n";
                exit(0);
            }
        } else {
            int j = 0;
            while (author[i - 1][j] == author[i][j]) {
                ++j;
            }

            int u = author[i - 1][j] - 'a', v = author[i][j] - 'a';
            adj[v].push_back(u);
        }
    }

    for (int i = 0; i < A; ++i) {
        if (color[i] == 0) {
            dfs(i);
        }
    }

    for (auto i : order) {
        cout << (char) (i + 'a');
    }
    cout << "\n";
}