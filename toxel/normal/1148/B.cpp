#include <bits/stdc++.h>

const int N = 500010;
typedef long long ll;
const ll INF = 2.5e9;

int a[N], b[N];
int n, m, ta, tb, k;

int check(ll mid){
    int n1 = -1, m1 = -1;
    for (int i = 0; i < n; ++ i) {
        if (a[i] + ta <= mid - tb) {
            n1 = i;
        }
    }
    for (int i = 0; i < m; ++ i) {
        if (b[i] + tb <= mid) {
            m1 = i;
        }
    }
    if (n1 == -1 || m1 == -1){
        return 0;
    }
    int min = n1 + 1;
    for (int i = n1, j = m1; i >= 0; -- i){
        while (j >= 0 && b[j] >= a[i] + ta){
            -- j;
        }
        min = std::min(min, i + m1 - j);
    }
    return min;
}

int main(){
    scanf("%d%d%d%d%d", &n, &m, &ta, &tb, &k);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++ i){
        scanf("%d", &b[i]);
    }
    ll left = 0, right = INF;
    while (left < right){
        ll mid = (left + right + 1) >> 1;
        if (check(mid) <= k){
            left = mid;
        }
        else{
            right = mid - 1;
        }
    }
    if (left == INF){
        puts("-1");
        return 0;
    }
    printf("%lld\n", left + 1);
    return 0;
}