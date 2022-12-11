#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int Q = 5e4 + 5;

struct dummy { int a, b, c; dummy *l, *r; };

char pool[24000000][sizeof(dummy)];
int ptr;

struct Node {
    int l, r, s;
    Node *left, *right;

    Node(int l, int r) {
        this->l = l;
        this->r = r;
        this->s = 0;
        left = right = NULL;
    }

    void update(int i, int v) {
        if (r < i || i < l) return;
        if (l == r) {
            s += v;
            return;
        }
        int mid = l + r >> 1;
        if (i <= mid) {
            if (!left) {
                left = new(pool[ptr++]) Node(l, mid);
            }
            left->update(i, v);
        } else {
            if (!right) {
                right = new(pool[ptr++]) Node(mid + 1, r);
            }
            right->update(i, v);
        }
        s = (left ? left->s : 0) + (right ? right->s : 0);
    }

    int get_less(int i) {
        if (i < l) return 0;
        if (r <= i) return s;
        return (left ? left->get_less(i) : 0) + (right ? right->get_less(i) : 0);
    }

    int get_more(int i) {
        if (r < i) return 0;
        if (i <= l) return s;
        return (left ? left->get_more(i) : 0) + (right ? right->get_more(i) : 0);
    }
};

int a[N];
int L[Q], R[Q];
int n, q;
Node* node[N];

void update(int v, int i, int change) {
    for (; i; i -= i & -i) {
        node[i]->update(v, change);
    }
}

int get_before(int pos, int val) {
    int ans = 0;
    for (++val, --pos; val < N; val += val & -val) {
        ans += node[val]->get_less(pos);
    }
    return ans;
}

int get_after(int pos, int val) {
    int ans = n - pos;
    for (++val, ++pos; val < N; val += val & -val) {
        ans -= node[val]->get_more(pos);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> q;

    for (int i = 0; i < N; ++i) {
        node[i] = new(pool[ptr++]) Node(1, N);
    }

    for (int i = 1; i <= n; ++i) {
        a[i] = i;
        update(i, a[i], 1);
    }

    long long ans = 0;        
    for (int i = 1; i <= q; ++i) {
        cin >> L[i] >> R[i];
        ans += get_before(R[i], a[L[i]]) - get_before(L[i], a[L[i]]);
        ans += get_before(L[i], a[R[i]]) - get_before(R[i], a[R[i]]);
        ans += get_after(R[i], a[L[i]]) - get_after(L[i], a[L[i]]);
        ans += get_after(L[i], a[R[i]]) - get_after(R[i], a[R[i]]);

        update(L[i], a[L[i]], -1); update(L[i], a[R[i]], +1);
        update(R[i], a[R[i]], -1); update(R[i], a[L[i]], +1); 
        swap(a[L[i]], a[R[i]]);

        cout << ans << '\n';
    }
    return 0;
}