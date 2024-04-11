#include <bits/stdc++.h>

using ll = long long;

ll ask(int l, int r){
    printf("? %d %d\n", l, r);
    fflush(stdout);
    ll ret;
    scanf("%lld", &ret);
    return ret;
}

ll sqroot(ll x){
    ll ret = std::sqrt((long double)(x * 2));
    if (ret * (ret + 1) / 2 == x){
        return ret + 1;
    }
    return -1;
}

void solve(){
    int n;
    scanf("%d", &n);
    ll tot = ask(1, n);
    int l = 1, r = n;
    while (l < r){
        if (r - l == 3){
            printf("! %d %d %d\n", l, l + 2, r);
            fflush(stdout);
            return;
        }
        int mid = (l + r) / 2;
        ll num = ask(l, mid);
        if (num == tot){
            r = mid;
            continue;
        }
        if (num == 0){
            l = mid;
            continue;
        }
        // guess1
        ll num1 = ask(l, mid + 1);
        ll diff = num1 - num;
        ll middle = mid + 1 - diff;
        if (2 <= middle && middle <= n){
            ll left = ask(1, middle - 1);
            ll right = ask(middle, n);
            if (left > 0 && right > 0 && left + right == tot){
                left = sqroot(left);
                right = sqroot(right);
                if (left != -1 && right != -1){
                    printf("! %lld %lld %lld\n", middle - left, middle, middle + right - 1);
                    fflush(stdout);
                    return;
                }
            }
        }
        ll left = mid + 1 - diff;
        l = left;
        while (l < r){
            mid = (l + r) / 2;
            if (ask(left, mid) == 1ll * (mid - left) * (mid - left + 1) / 2){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        ll right = sqroot(tot - 1ll * (l - left) * (l - left - 1) / 2);
        printf("! %lld %lld %lld\n", left, ll(l), l + right - 1);
        fflush(stdout);
        return;
    }
}

int main(){
    // printf("%lld\n", sqroot(1ll * 998244353*998244352/2));
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}