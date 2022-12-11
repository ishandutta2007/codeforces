#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e5 + 10;
int p[N];
int p_inv[N];
int prv[N], nxt[N], sz[N];

void solve() {
    int n;
    scanf("%d", &n);
    multiset<int> values = {};
    for (int i = 0; i < n; i++) {
        prv[i] = i - 1;
        nxt[i] = i + 1;
        sz[i] = 1;
        values.insert(-1);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        p[i]--;
    }
    for (int i = 0; i < n; i++) {
        p_inv[p[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        int position = p_inv[i];
        if (sz[position] != -(*values.begin())) {
            puts("No");
            return;
        }
        values.erase(values.find(-sz[position]));
        if (nxt[position] < n) {
            values.erase(values.find(-sz[nxt[position]]));
        }
        sz[nxt[position]] += sz[position];
        if (nxt[position] < n) {
            values.insert(-sz[nxt[position]]);
        }
        prv[nxt[position]] = prv[position];
        if (prv[position] != -1) {
            nxt[prv[position]] = nxt[position];
        }
    }
    puts("Yes");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}