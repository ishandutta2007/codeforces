#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200001, MAX_LG = __lg(MAX_N) + 1;

long long nxt_cost[MAX_N][MAX_LG], prv_cost[MAX_N][MAX_LG];
int nxt[MAX_N][MAX_LG], prv[MAX_N][MAX_LG];
vector<int> children[MAX_N];

long long a[MAX_N], b[MAX_N];
int perm[MAX_N], n, q;

long long query(int l, int r) {
    long long cost = 0;

    for (int i = __lg(n + 1); i >= 0; --i) {
        if (nxt[l][i] <= r) {
            cost += nxt_cost[l][i];
            l = nxt[l][i];
        }
    }

    for (int i = __lg(n + 1); i >= 0; --i) {
        if (prv[r][i] >= l) {
            cost += prv_cost[r][i];
            r = prv[r][i];
        }
    }

    return cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> perm[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> stack;
    for (int i = 0; i < n; ++i) {
        while (!stack.empty() && perm[stack.back()] < perm[i]) {
            stack.pop_back();
        }
        prv[i][0] = stack.empty() ? -1 : stack.back();
        stack.push_back(i);
    }
    prv[n][0] = -1;

    stack.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!stack.empty() && perm[stack.back()] < perm[i]) {
            stack.pop_back();
        }
        nxt[i][0] = stack.empty() ? n : stack.back();
        stack.push_back(i);
    }
    nxt[n][0] = n + 1;

    for (auto sparse : {prv, nxt}) {
        for (int i = 1; i <= __lg(n + 1); ++i) {
            for (int j = 0; j <= n; ++j) {
                sparse[j][i] = sparse[j][i - 1];
                if (0 <= sparse[j][i] && sparse[j][i] <= n) {
                    sparse[j][i] = sparse[sparse[j][i]][i - 1];
                }
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        nxt_cost[i][0] = min(b[i], a[i] + query(i + 1, nxt[i][0]));

        for (int j = 1; j <= __lg(n + 1); ++j) {
            nxt_cost[i][j] = nxt_cost[i][j - 1];
            if (nxt[i][j - 1] <= n) {
                nxt_cost[i][j] += nxt_cost[nxt[i][j - 1]][j - 1];
            }
        }

        children[nxt[i][0]].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        if (prv[i][0] == -1) {
            continue;
        }

        prv_cost[i][0] = query(prv[i][0], i - 1) + a[i - 1];
        for (auto j : children[i]) {
            prv_cost[i][0] = min(prv_cost[i][0], query(prv[i][0], j) + b[j]);
        }

        for (int j = 1; j <= __lg(n + 1); ++j) {
            prv_cost[i][j] = prv_cost[i][j - 1];
            if (prv[i][j - 1] >= 0) {
                prv_cost[i][j] += prv_cost[prv[i][j - 1]][j - 1];
            }
        }
    }

    set<int> squares = {0, n};
    long long cost = query(0, n);

    while (q--) {
        int x;
        cin >> x;

        if (--x > 0) {
            if (squares.count(x) > 0) {
                int l = *--squares.find(x);
                int r = *++squares.find(x);
                cost += query(l, r) - query(l, x) - query(x, r);
                squares.erase(x);
            } else {
                squares.insert(x);
                int l = *--squares.find(x);
                int r = *++squares.find(x);
                cost += query(l, x) + query(x, r) - query(l, r);
            }
        }

        cout << cost << "\n";
    }
}