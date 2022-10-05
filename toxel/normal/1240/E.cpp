#include <bits/stdc++.h>

const int N = 500010;
using ll = long long;

int cnt[N], a[N];

int get(int pos){
    return cnt[std::max(std::min(pos, N - 1), 0)];
}
int calc(int l, int r){
    return get(r) - get(l - 1);
}

bool check1(int x, int y, ll sum){
    if (x < 2){
        return false;
    }
    x *= 2;
    for (int i = x / y * y; i < N; i += y){
        if (i >= x && x % y > 0){
            if (calc(i, i + x % y - 1)){
                if (sum - x / y - 1 >= x / 2){
                    return true;
                }
            }
        }
        if (calc(i + x % y, i + y - 1)){
            if (sum - x / y >= x / 2){
                return true;
            }
        }
    }
    return false;
}

bool check2(int x, int y, ll sum){
    if (x < 2){
        return false;
    }
    int sum1 = 0, sum0 = 0;
    for (int i = x / y * y; i < N; i += y){
        if (i >= x && x % y > 0){
            sum1 += calc(i, i + x % y - 1);
        }
        sum0 += calc(i + x % y, i + y - 1);
    }
    if (sum0 + sum1 < 2){
        return false;
    }
    int sub = 2 - std::min(2, sum0);
    return sum - x / y * 2 - sub >= x;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        ++ cnt[a[i]];
    }
    std::sort(a, a + n);
    for (int i = 1; i < N; ++ i){
        cnt[i] += cnt[i - 1];
    }
    ll ans = 0;
    for (int y = 2; y <= a[n - 1]; ++ y){
        ll sum = 0;
        for (int i = y; i < N; i += y){
            sum += calc(i, i + y - 1) * (i / y);
        }
        auto binary_search = [&](int left, int right){
            while (left < right){
                int mid = (left + right + 1) / 2;
                if (sum - mid / y * 2 >= mid){
                    left = mid;
                }
                else{
                    right = mid - 1;
                }
            }
            return left;
        };
        int x = binary_search(2, a[n - 1] / 2);
        for (int i = x; i >= x - 2; -- i){
            if (check1(i, y, sum)){
                ans = std::max(ans, 1ll * i * y);
                break;
            }
        }
        if (n > 1){
            x = binary_search(2, a[n - 2]);
            for (int i = x; i >= x - 2; -- i){
                if (check2(i, y, sum)){
                    ans = std::max(ans, 1ll * i * y);
                    break;
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}