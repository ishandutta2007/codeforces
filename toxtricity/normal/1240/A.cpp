#include <bits/stdc++.h>

const int N = 200010;
typedef long long ll;

int p[N];
int x, a;
int y, b;

ll check(int n){
    if (x < y){
        std::swap(x, y);
        std::swap(a, b);
    }
    ll lcm = 1ll * a * b / std::__gcd(a, b);
    int num1 = n / lcm, num2 = n / a - num1, num3 = n / b - num1;
    ll ret = 0;
    for (int i = 0; i < num1; ++ i){
        ret += (x + y) * p[i];
    }
    for (int i = num1; i < num1 + num2; ++ i){
        ret += x * p[i];
    }
    for (int i = num1 + num2; i < num1 + num2 + num3; ++ i){
        ret += y * p[i];
    }
    return ret;
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &p[i]);
        p[i] /= 100;
    }
    std::sort(p, p + n, std::greater <int>());
    scanf("%d%d", &x, &a);
    scanf("%d%d", &y, &b);
    ll k;
    scanf("%lld", &k);
    if (check(n) < k){
        puts("-1");
        return;
    }
    int left = 1, right = n;
    while (left < right){
        int mid = (left + right) / 2;
        if (check(mid) < k){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    printf("%d\n", left);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}