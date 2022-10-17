#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

struct node {
    int p0, p1, p2, s0, s1, s2, mid;
    node() : p0(0), p1(0), p2(0), s0(0), s1(0), s2(0), mid(0) {};
};

const int N = 1e5 + 10;
node t[4 * N];
string s;

void merge(int v) {
    t[v].p0 = t[2 * v].p0 + t[2 * v + 1].p0;
    t[v].p1 = min(t[2 * v].p0 + t[2 * v + 1].p1, t[2 * v].p1 + t[2 * v + 1].mid);
    t[v].p2 = min({t[2 * v].p0 + t[2 * v + 1].p2, t[2 * v].p1 + t[2 * v + 1].s1, t[2 * v].p2 + t[2 * v + 1].s0});
    t[v].mid = t[2 * v].mid + t[2 * v + 1].mid;

    t[v].s0 = t[2 * v].s0 + t[2 * v + 1].s0;
    t[v].s1 = min(t[2 * v + 1].s0 + t[2 * v].s1, t[2 * v + 1].s1 + t[2 * v].mid);
    t[v].s2 = min({t[2 * v + 1].s0 + t[2 * v].s2, t[2 * v + 1].s1 + t[2 * v].p1, t[2 * v + 1].s2 + t[2 * v].p0});
}

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = node();
        if (s[l] == 'a') {
            t[v].p0 = 1;
        } else if (s[l] == 'c') {
            t[v].s0 = 1;
        } else {
            t[v].mid = 1;
        }
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    merge(v);
}

void update(int v, int l, int r, int need, char val) {
    if (l == r) {
        t[v] = node();
        if (val == 'a') {
            t[v].p0 = 1;
        } else if (val == 'c') {
            t[v].s0 = 1;
        } else {
            t[v].mid = 1;
        }
        return;
    }
    int mid = (l + r) / 2;
    if (need <= mid) {
        update(2 * v, l, mid, need, val);
    } else {
        update(2 * v + 1, mid + 1, r, need, val);
    }
    merge(v);
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    cin >> s;
    s.insert(s.begin(), ' ');
    build(1, 1, n);
    for (int i = 0; i < q; i++) {
        int pos;
        char c;
        cin >> pos >> c;
        update(1, 1, n, pos, c);
        cout << t[1].p2 << '\n';
    }
}