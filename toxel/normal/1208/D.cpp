#include <bits/stdc++.h>

const int N = 200010;
const int MAX = 1 << 18;
typedef long long ll;

ll seg[MAX << 1];
ll s[N], p[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &s[i]);
    }
    for (int i = 0; i < n; ++ i){
        seg[MAX + i] = i + 1;
    }
    for (int i = MAX - 1; i; -- i){
        seg[i] = seg[i << 1] + seg[i << 1 | 1];
    }
    for (int i = n - 1; i >= 0; -- i){
        int cur = 1;
        ll sum = 0;
        for (int j = 0; j < 18; ++ j){
            if (sum + seg[cur << 1] <= s[i]){
                sum += seg[cur << 1];
                cur = cur << 1 | 1;
            }
            else{
                cur = cur << 1;
            }
        }
        p[i] = cur - MAX + 1;
        seg[cur] = 0;
        cur >>= 1;
        while (cur){
            seg[cur] = seg[cur << 1] + seg[cur << 1 | 1];
            cur >>= 1;
        }
    }
    for (int i = 0; i < n; ++ i){
        printf("%lld%c", p[i], " \n"[i == n - 1]);
    }
    return 0;
}