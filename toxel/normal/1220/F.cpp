#include <bits/stdc++.h>

const int N = 400010;
typedef std::pair <int, int> pii;

struct SegSingle{
    static const int MAX = 1 << 19;

    int seg[MAX << 1];

    void add(int sit, int value){
        seg[sit += MAX] = value;
        for (sit >>= 1; sit; sit >>= 1){
            seg[sit] = std::max(seg[sit << 1], seg[sit << 1 | 1]);
        }
    }

    int query(int l, int r){
        int ret = INT_MIN;
        for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
            if (l & 1) ret = std::max(ret, seg[l ++]);
            if (r & 1) ret = std::max(ret, seg[-- r]);
        }
        return ret;
    }
};

struct SegInter{
    static const int MAX = 1 << 19;

    int seg[MAX << 1], lazy[MAX << 1];

    void push(int sit){
        if (!lazy[sit]){
            return;
        }
        seg[sit << 1] += lazy[sit];
        lazy[sit << 1] += lazy[sit];
        seg[sit << 1 | 1] += lazy[sit];
        lazy[sit << 1 | 1] += lazy[sit];
        lazy[sit] = 0;
    }

    void pull(int sit){
        seg[sit] = std::max(seg[sit << 1], seg[sit << 1 | 1]);
    }

    void add(int sit, int ql, int qr, int l, int r, int value){
        if (ql > r || qr < l){
            return;
        }
        if (ql <= l && qr >= r){
            seg[sit] += value;
            lazy[sit] += value;
            return;
        }
        push(sit);
        int mid = (l + r) / 2;
        add(sit << 1, ql, qr, l, mid, value);
        add(sit << 1 | 1, ql, qr, mid + 1, r, value);
        pull(sit);
    }

    int query(int sit, int ql, int qr, int l, int r){
        if (ql > r || qr < l){
            return INT_MIN;
        }
        if (ql <= l && qr >= r){
            return seg[sit];
        }
        push(sit);
        int mid = (l + r) / 2;
        return std::max(query(sit << 1, ql, qr, l, mid), query(sit << 1 | 1, ql, qr, mid + 1, r));
    }

    void add(int ql, int qr, int value){
        add(1, ql, qr, 0, MAX - 1, value);
    }

    int query(int ql, int qr){
        return query(1, ql, qr, 0, MAX - 1);
    }
};

int a[N], inv[N];
int dep[N];
SegSingle seg1, seg2, seg3;
SegInter segi;

void dfs(int l, int r, int cur){
    if (l > r){
        return;
    }
    int value = -seg3.query(l, r);
    int pos = inv[value];
    dep[pos] = cur;
    dfs(l, pos - 1, cur + 1);
    dfs(pos + 1, r, cur + 1);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        a[i + n] = a[i];
        inv[a[i]] = i;
    }
    for (int i = 1; i <= n; ++ i){
        seg1.add(a[i], -i);
        seg2.add(a[i], i);
        seg3.add(i, -a[i]);
    }
    dfs(1, n, 1);
    for (int i = 1; i <= n; ++ i){
        segi.add(i, i, dep[i]);
    }
    int min = INT_MAX, pos = 0;
    for (int i = 1; i <= n; ++ i){
        int res = segi.query(i, i + n - 1);
        if (res < min){
            min = res;
            pos = i - 1;
        }
        int right = seg1.query(1, a[i] - 1);
        if (right == INT_MIN){
            right = i + n;
        }
        else{
            right = -right;
        }
        segi.add(i + 1, right - 1, -1);
        seg1.add(a[i], -(i + n));
        seg2.add(a[i], i + n);
        int left = seg2.query(1, a[i] - 1);
        if (left == INT_MIN){
            segi.add(i + 1, i + n - 1, 1);
            segi.add(i + n, i + n, 1);
        }
        else{
            segi.add(left + 1, i + n - 1, 1);
            segi.add(i + n, i + n, segi.query(left, left) + 1);
        }
    }
    printf("%d %d\n", min, pos);
    return 0;
}