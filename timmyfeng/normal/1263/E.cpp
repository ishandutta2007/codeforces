#include <bits/stdc++.h>
using namespace std;

vector<int> stMx, stMn, lazy;

void push(int v) {
    lazy[v * 2 + 1] += lazy[v];
    stMx[v * 2 + 1] += lazy[v];
    stMn[v * 2 + 1] += lazy[v];
    lazy[v * 2] += lazy[v];
    stMx[v * 2] += lazy[v];
    stMn[v * 2] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int l, int r, int a, int b, int addend) {
    if (a > b) return;
    if (l == a && b == r) {
        stMx[v] += addend;
        stMn[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int m = (l + r) / 2;
        update(v * 2, l, m, a, min(m, b), addend);
        update(v * 2 + 1, m + 1, r, max(m + 1, a), b, addend);
        stMx[v] = max(stMx[v * 2], stMx[v * 2 + 1]);
        stMn[v] = min(stMn[v * 2], stMn[v * 2 + 1]);
    }
}

int get(int v, int l, int r, int a) {
    if (l == r) return stMx[v];
    push(v);
    int m = (l + r) / 2;
    if (a <= m) return get(v * 2, l, m, a);
    return get(v * 2 + 1, m + 1, r, a);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;

    stMx.resize(n * 4);
    stMn.resize(n * 4);
    lazy.resize(n * 4);
    int cur = 0;
    vector<int> ln(n);
    for (auto i : s) {
        if (i == '(') {
            update(1, 0, n - 1, cur, n - 1, 1 - ln[cur]);
            ln[cur] = 1;
        } else if (i == ')') {
            update(1, 0, n - 1, cur, n - 1, -1 - ln[cur]);
            ln[cur] = -1;
        } else if (i == 'R') {
            ++cur;
        } else if (i == 'L') {
            cur = max(cur - 1, 0);
        } else {
            update(1, 0, n - 1, cur, n - 1, -ln[cur]);
            ln[cur] = 0;
        }

        if (get(1, 0, n - 1, n - 1) || stMn[1] < 0) {
            cout << -1 << ' ';
        } else {
            cout << stMx[1] << ' ';
        }
    }
    cout << '\n';
}