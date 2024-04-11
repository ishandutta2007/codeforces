#include <bits/stdc++.h>

const int N = 600010;

int c[N];

void add(int sit, int value){
    for ( ; sit < N; sit += sit & -sit){
        c[sit] += value;
    }
}

int query(int sit){
    int ret = 0;
    for ( ; sit; sit -= sit & -sit){
        ret += c[sit];
    }
    return ret;
}

int left[N], right[N], cur[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i){
        left[i] = right[i] = i;
        cur[i] = n + 1 - i;
        add(cur[i], 1);
    }
    for (int i = 0; i < m; ++ i){
        int x;
        scanf("%d", &x);
        int pos = n - query(cur[x]) + 1;
        left[x] = 1;
        right[x] = std::max(right[x], pos);
        add(cur[x], -1);
        cur[x] = n + i + 1;
        add(cur[x], 1);
    }
    for (int i = 1; i <= n; ++ i){
        right[i] = std::max(right[i], n - query(cur[i]) + 1);
        printf("%d %d\n", left[i], right[i]);
    }
    return 0;
}