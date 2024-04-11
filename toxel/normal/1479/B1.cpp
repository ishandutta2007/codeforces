#include <bits/stdc++.h>

const int N = 100010;
const int MAX = 1 << 17;
const int INF = -1e9;

int seg[MAX << 1];
int a[N];

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

int main(){
    for (int i = 0; i < MAX << 1; ++ i){
        seg[i] = INF;
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    add(0, 1);
    int offset = 0;
    for (int i = 1; i < n; ++ i){
        int x = query(0, a[i] - 1);
        x = std::max(x, query(a[i] + 1, MAX - 1));
        x += offset + 1;
        x = std::max(x, query(a[i], a[i]) + offset);
        if (a[i] != a[i - 1]){
            ++ offset;
        }
        add(a[i - 1], x - offset);
    }
    int ans = INT_MIN;
    for (int i = 0; i < MAX; ++ i){
        ans = std::max(ans, query(i, i) + offset);
    }
    printf("%d\n", ans);
    return 0;
}