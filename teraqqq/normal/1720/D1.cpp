#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+7;
const int W = 30;
const int S = N * (W + 1);

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

struct Node {
    int mx[4];
    Node *l, *r;
} nd[S];

Node* new_node() {
    static Node* cur = &nd[0];
    cur->l = cur->r = nullptr;
    fill(cur->mx, cur->mx+4, 0);
    return cur++;
}

#define get_bit(x, i) (((x)>>(i))&1)

int get_max(Node* v, int x, int i) {
    int res = 0;

    for (int t = W; t-- && v; ) {
        ckmax(res, v->mx[(get_bit(i, t) << 1) | (1 ^ get_bit(x, t))]);

        if (get_bit(x^i, t)) {
            v = v->r;
        } else {
            v = v->l;
        }
    }

    return res;
}

void insert(Node* v, int x, int i, int ans) {
    for (int t = W; t--; ) {

        ckmax(v->mx[get_bit(i, t) | (get_bit(x, t) << 1)], ans);

        if (get_bit(x^i, t)) {
            if (!v->r) v->r = new_node();
            v = v->r;
        } else {
            if (!v->l) v->l = new_node();
            v = v->l;
        }
    }
}

void solve() {
    auto root = new_node();

    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        int y = get_max(root, x, i) + 1;
        ckmax(ans, y);
        insert(root, x, i, y);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}