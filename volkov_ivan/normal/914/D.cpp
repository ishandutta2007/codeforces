#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

const int MAX_N = 1 << 19;
int n, start;
int t[2 * MAX_N];
int a[MAX_N];

void build(int l, int r, int num) {
    if (l == r) {
        return;
    }
    int m = (l + r) / 2;
    build(l, m, 2 * num);
    build(m + 1, r, 2 * num + 1);
    t[num] = gcd(t[2 * num], t[2 * num + 1]);
}

void relax(int elem) {
    t[elem] = gcd(t[2 * elem], t[2 * elem + 1]);
}

void update(int elem, int c) {
    t[elem] = c;
    while (elem > 1) {
        elem /= 2;
        relax(elem);
    }
}

int rec(int l, int r, int a, int b, int num, int x, bool need) {
    if (l > b || r < a) return 0;
    if (a <= l && r <= b) {
        if (t[num] % x == 0) return 0;
        if (need) return 2;
        if (l == r) return 1;
        int m = (l + r) / 2;
        int tmp = rec(l, m, a, b, 2 * num, x, 0);
        if (tmp == 2) return 2;
        if (tmp == 0) {
            return rec(m + 1, r, a, b, 2 * num + 1, x, 0);
        }
        if (rec(m + 1, r, a, b, 2 * num + 1, x, 1) > 0) return 2;
        return 1;
    }
    int m = (l + r) / 2;
    int tmp = rec(l, m, a, b, 2 * num, x, need);
    if ((need && tmp > 0) || tmp == 2) return 2;
    if (tmp == 1) {
        if (rec(m + 1, r, a, b, 2 * num + 1, x, 1) > 0) return 2;
        return 1;
    }
    return rec(m + 1, r, a, b, 2 * num + 1, x, need);
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t[MAX_N + i] = a[i];
    }
    for (int i = n; i < MAX_N; i++) {
        t[MAX_N + i] = 0;
    }
    build(1, MAX_N, 1);
    cin >> q;
    int type, l, r, x, pos;
    for (int i = 0; i < q; i++) {
        cin >> type;
        if (type == 1) {
            cin >> l >> r >> x;
            if (rec(1, MAX_N, l, r, 1, x, 0) < 2) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cin >> pos >> x;
            update(MAX_N + pos - 1, x);
        }
    }
    return 0;
}