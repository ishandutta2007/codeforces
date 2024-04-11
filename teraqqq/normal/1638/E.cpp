#include <iostream>
#include <map>

using namespace std;
using ll = long long;

const int N = 1 << 20;

int any_col[2*N], paint[2*N];
ll sum[2*N];
bool dif_col[2*N];
map<int, ll> col_x;

void update(int v) {
    dif_col[v] = dif_col[2*v] || dif_col[2*v+1] || any_col[2*v] != any_col[2*v+1];
    any_col[v] = any_col[2*v];
}

void push(int v) {
    if (paint[v]) {
        any_col[2*v] = any_col[2*v+1] = paint[v];
        dif_col[2*v] = dif_col[2*v+1] = false;
        paint[2*v] = paint[2*v+1] = paint[v];
        paint[v] = 0;
    }
}

void assign_color(int v, int vl, int vr, int l, int r, int x) {
    // cout << v << " " << vl << " " << vr << " " << l << " " << r << " " << x << endl;

    if (l <= vl && vr <= r && !dif_col[v]) {
        sum[v] += col_x[any_col[v]] - col_x[x];
        dif_col[v] = false;
        any_col[v] = x;
        paint[v] = x;
    } else if (r <= vl || vr <= l) {
        // nope :D
    } else {
        int vm = (vl + vr) / 2;
        push(v);
        assign_color(2*v, vl, vm, l, r, x);
        assign_color(2*v+1, vm, vr, l, r, x);
        update(v);
    }
}

ll query(int v, int vl, int vr, int i) {
    if (vl + 1 == vr) {
        return sum[v] + col_x[any_col[v]];
    } else {
        int vm = (vl + vr) / 2;
        push(v);
        return (i < vm ? query(2*v, vl, vm, i) : query(2*v+1, vm, vr, i)) + sum[v];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    fill(any_col, any_col+2*N, 1);

    while (q--) {
        string op; cin >> op;

        if (op[0] == 'C') {
            int l, r, x; cin >> l >> r >> x; l--;
            assign_color(1, 0, N, l, r, x);
        } else if(op[0] == 'A') {
            int c, x; cin >> c >> x;
            col_x[c] += x;
        } else if(op[0] == 'Q') {
            int i; cin >> i; --i;
            cout << query(1, 0, N, i) << '\n';
        }
    }
}