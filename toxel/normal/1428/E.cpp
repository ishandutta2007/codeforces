#include <bits/stdc++.h>

using ll = long long;
using pii = std::pair <ll, ll>;
const int N = 100010;

int a[N];
int cur[N];

ll calc(int x, int num){
    int base = x / num;
    int up = x % num;
    int down = num - x % num;
    return 1ll * base * base * down + 1ll * (base + 1) * (base + 1) * up;
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    std::priority_queue<pii> pq;
    ll sum = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        sum += 1ll * a[i] * a[i];
        pq.push({calc(a[i], 1) - calc(a[i], 2), i});
        cur[i] = 1;
    }
    for (int i = 0; i < k - n; ++ i){
        pii p = pq.top();
        pq.pop();
        sum -= p.first;
        int pos = p.second;
        ++ cur[pos];
        pq.push({calc(a[pos], cur[pos]) - calc(a[pos], cur[pos] + 1), pos});
    }
    printf("%lld\n", sum);
    return 0;
}