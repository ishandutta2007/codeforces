#include <bits/stdc++.h>

const int N = 300010;
using ll = long long;

ll c1[N], c2[N];
int a[N];

void update(ll *c, int sit, ll value){
    for ( ; sit < N; sit += sit & -sit){
        c[sit] += value;
    }
}

ll query(ll *c, int sit){
    ll ret = 0;
    for ( ; sit; sit -= sit & -sit){
        ret += c[sit];
    }
    return ret;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    ll sum = 0;
    for (int i = 1; i <= n; ++ i){
        ll prev1 = 0, prev2 = 0;
        for (int j = a[i]; j < N; j += a[i]){
            ll cur1 = query(c1, j - 1), cur2 = query(c2, j - 1);
            sum += (cur1 - prev1) - a[i] * ((j - 1) / a[i]) * (cur2 - prev2);
            prev1 = cur1, prev2 = cur2;
        }
        ll cur1 = query(c1, N - 1), cur2 = query(c2, N - 1);
        sum += (cur1 - prev1) - a[i] * ((N - 1) / a[i]) * (cur2 - prev2);
        prev1 = 0, prev2 = 0;
        for (int j = 1, k; j <= a[i]; j = k + 1){
            int x = a[i] / j;
            k = a[i] / x;
            cur1 = query(c1, k);
            sum -= (cur1 - prev1) * x;
            prev1 = cur1;
        }
        cur2 = query(c2, N - 1);
        sum += a[i] * (cur2 - prev2);
        update(c1, a[i], a[i]);
        update(c2, a[i], 1);
        printf("%lld%c", sum, " \n"[i == n]);
    }
    return 0;
}