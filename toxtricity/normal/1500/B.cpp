#include <bits/stdc++.h>

const int N = 1000010;
using ll = long long;

int a[N], b[N];
int inva[N], invb[N];
int cnt[N];

int main(){
    int n, m;
    ll k;
    scanf("%d%d%lld", &n, &m, &k);
    memset(inva, -1, sizeof(inva));
    memset(invb, -1, sizeof(invb));
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        inva[a[i]] = i;
    }
    for (int j = 0; j < m; ++ j){
        scanf("%d", &b[j]);
        invb[b[j]] = j;
    }
    if (n > m){
        std::swap(n, m);
        for (int i = 0; i < N; ++ i){
            std::swap(a[i], b[i]);
            std::swap(inva[i], invb[i]);
        }
    }
    for (int i = 0; i < N; ++ i){
        if (inva[i] != -1 && invb[i] != -1){
            int pos = invb[i] - inva[i];
            pos += pos < 0 ? m : 0;
            ++ cnt[pos];
        }
    }
    for (int i = 0; i < m; ++ i){
        cnt[i] = n - cnt[i];
    }
    int cur_mod = 0;
    ll total = 0;
    for (int i = 0; i < m; ++ i){
        total += cnt[cur_mod];
        cur_mod = (cur_mod + n) % m;
    }
    ll ans = (k - 1) / total * n * m;
    k -= (k - 1) / total * total;
    cur_mod = 0;
    while (true){
        int next = cnt[cur_mod];
        if (k <= next){
            break;
        }
        k -= next;
        ans += n;
        cur_mod = (cur_mod + n) % m;
    }
    for (int i = 0; i < n && k > 0; ++ i){
        ++ ans;
        if (a[i] != b[(i + cur_mod) % m]){
            -- k;
        }
    }
    printf("%lld\n", ans);
    return 0;
}