#include <bits/stdc++.h>

const int N = 100010;
using ll = long long;

int n;
ll a[N], b[N];

ll sim(int x){
    int ans = a[x];
    memset(b, 0, sizeof(b));
    for (int j = 1; j <= n; ++ j){
        if (j == 1){
            b[j % n + 1] += a[j];
        }
        else{
            b[j % n + 1] += (a[j] + 1) / 2;
            b[(j - 2 + n) % n + 1] += a[j] / 2;
        }
    }
    memcpy(a, b, sizeof(b));
    return ans;
}

ll ask(int x){
    printf("? %d\n", x);
    fflush(stdout);
    ll ans;
    scanf("%lld", &ans);
    // ans = sim(x);
    return ans;
}

int main(){
    int k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++ i){
        a[i] = k;
    }
    /*double prob = 1;
    for (int i = 1; i <= 1000; ++ i){
        prob *= 1.0 * (n - 2 * i + 2) / n;
    }
    printf("%.15f\n", prob);*/
    const int MAX = 249;
    for (int i = 0; i < MAX; ++ i){
        ask(1);
    }
    int delta = std::max(1, n / MAX + 1);
    int cur = 1;
    int pos = 0;
    for (int i = 0; i < MAX; ++ i){
        int ans = ask(cur);
        if (ans > k){
            pos = cur;
            break;
        }
        else if (ans < k){
            pos = -cur;
            break;
        }
        cur = (cur + delta) % n;
        cur += cur == 0 ? n : 0;
    }
    cur = std::abs(pos);
    if (pos > 0){
        while (ask(cur) != k){
            cur = (cur + n - 1) % n;
            cur += cur == 0 ? n : 0;
        }
    }
    else{
        while (ask(cur) != k){
            cur = (cur + 1) % n;
            cur += cur == 0 ? n : 0;
        }
    }
    printf("! %d\n", cur);
    return 0;
}