#include<bits/stdc++.h>

const int N = 23;

int a[N];
int sit[1 << N];

inline int lowbit(int n){return n & -n;}

int main(){
    for (int i = 0; i < N; ++ i){
        sit[1 << i] = i;
    }
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        a[i] |= 1 << i;
    }
    for (int i = 0, u, v; i < m; ++ i){
        scanf("%d%d", &u, &v);
        -- u, -- v;
        a[u] |= 1 << v;
        a[v] |= 1 << u;
    }
    bool zzh = true;
    for (int i = 0; i < n; ++ i){
        if (a[i] != (1 << n) - 1){
            zzh = false;
            break;
        }
    }
    if (zzh){
        puts("0");
        return 0;
    }
    int ans = INT_MAX, sit;
    for (int i = 0; i < 1 << n; ++ i){
        int x = lowbit(i), diff = x;
        while (true){
            int tmp = x;
            while (diff){
                x |= a[::sit[lowbit(diff)]];
                x &= i;
                diff ^= lowbit(diff);
            }
            diff = x ^ tmp;
            if (!diff){
                break;
            }
        }
        bool flag = (i & x) == i;
        if (!flag){
            continue;
        }
        for (int j = 0; j < n; ++ j){
            if (!(a[j] & i)){
                flag = false;
                break;
            }
        }
        if (flag){
            int cnt = __builtin_popcount(i);
            if (ans > cnt){
                ans = cnt;
                sit = i;
            }
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; ++ i){
        if (sit >> i & 1){
            printf("%d ", i + 1);
        }
    }
    puts("");
    return 0;
}