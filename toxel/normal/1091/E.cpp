#include<bits/stdc++.h>

const int N = 500010;
typedef long long ll;
typedef std::pair <int, int> pii;

int d[N];
ll pre[N], suf[N];
pii p[N];
int n;

int check(){
    for (int i = 1; i <= n + 1; ++ i){
        p[i] = {d[i], i};
    }
    std::sort(p + 1, p + n + 2, std::greater <pii>());
    for (int i = 1; i <= n + 1; ++ i){
        pre[i] = pre[i - 1] + p[i].first;
    }
    for (int i = n + 1; i >= 1; -- i){
        suf[i] = suf[i + 1] + p[i].first;
    }
    int sit;
    for (int i = 1; i <= n + 1; ++ i){
        if (p[i].second == n + 1){
            sit = i;
            break;
        }
    }
    for (int k = 1, j = n + 1; k <= n + 1; ++ k){
        while (j >= 1 && p[j].first <= k){
            -- j;
        }
        ll left = pre[k];
        ll right = 1ll * k * (k - 1) + suf[std::max(j + 1, k + 1)] + 1ll * std::max(0, j - k) * k;
        if (left > right){
            return sit <= k ? -1 : 1;
        }
    }
    return 0;
}

int main(){
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &d[i]);
        sum += d[i];
    }
    int left = 0, right = (n + 2) >> 1;
    while (left <= right){
        int mid = (left + right) >> 1;
        d[n + 1] = mid << 1 | (sum & 1);
        int x = check();
        if (x == -1){
            right = mid - 1;
        }
        else if (x == 1){
            left = mid + 1;
        }
        else{
            left = mid;
            break;
        }
    }
    if (left > right){
        puts("-1");
        return 0;
    }
    int l = left, r = (n + 2) >> 1;
    while (l < r){
        int mid = (l + r + 1) >> 1;
        d[n + 1] = mid << 1 | (sum & 1);
        int x = check();
        if (x){
            r = mid - 1;
        }
        else{
            l = mid;
        }
    }
    int ansr = l;
    l = 0, r = left;
    while (l < r){
        int mid = (l + r) >> 1;
        d[n + 1] = mid << 1 | (sum & 1);
        int x = check();
        if (x){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    for (int i = l; i <= ansr; ++ i){
        printf("%lld%c", i << 1 | (sum & 1), " \n"[i == ansr]);
    }
    return 0;
}