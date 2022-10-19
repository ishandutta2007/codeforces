#include <bits/stdc++.h>

using namespace std;

int n;
char S[200005];
int P[200005];
int R[200005];
vector<int> E[200005];
int par[200005], sz;

int find(int x) {
    if (par[x]) return par[x] = find(par[x]);
    return x;
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    par[y] = x;
    --sz;
}

void dfs(int x) {
    for (int i : E[x]) {
        merge(E[x][0], R[i]);
        merge(i, R[E[x].back()]);
        dfs(i);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> S + 1;
        n += n;
        sz = n;
        for (int i = 0; i <= n; ++i) {
            R[i] = 0;
            E[i].clear();
            par[i] = 0;
        }
        vector<int> s(1, 0);
        for (int i = 1; i <= n; ++i) {
            if (S[i] == '(') s.push_back(i);
            else {
                int p = s.back(); s.pop_back();
                P[p] = s.back();
                E[P[p]].push_back(p);
                R[p] = i;
            }
        }
        R[0] = n + 1;
        dfs(0);
        printf("%d\n", sz);
    }
    return 0;
}