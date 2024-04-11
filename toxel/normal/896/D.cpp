#include<bits/stdc++.h>

typedef long long ll;

ll eucinv(ll a, ll moder){
    ll b = moder, s = 1, t = 0;
    while (b){
        ll tmp = a, q = a / b;
        a = b, b = tmp % a;
        tmp = s;
        s = t;
        t = tmp - s * q;
    }
    if (a > 1) return -1;
    return s < 0 ? moder + s : s;
}

const int N = 200010;

ll fac[N], inv[N], power[N];
int cnt[N];
ll moder;

ll comb(int n, int m){
    if (n < m || m < 0) return 0;
    ll ret = fac[n] * inv[m] % moder * inv[n - m] % moder;
    int cnt = ::cnt[n] - ::cnt[m] - ::cnt[n - m];
    return ret * power[cnt] % moder;
}

ll solve(int n, int l, int r, ll p, int exp){
    memset(cnt, 0, sizeof(cnt));
    power[0] = 1;
    for (int i = 1; i < N; ++ i){
        power[i] = power[i - 1] * p % moder;
    }
    fac[0] = inv[0] = 1;
    for (int i = 1; i < N; ++ i){
        int x = i;
        while (x % p == 0){
            ++ cnt[i];
            x /= p;
        }
        cnt[i] += cnt[i - 1];
        fac[i] = fac[i - 1] * x % moder;
        inv[i] = eucinv(fac[i], moder);
    }
    ll ans = 0;
    for (int i = 0; i <= n; ++ i){
        int left = (n - i + l + 1) / 2;
        int right = (n - i + r) / 2;
        if (left > right){
            continue;
        }
        ans = (ans + comb(n, i) * (comb(n - i, left) - comb(n - i, right + 1))) % moder;
    }
    ans += ans < 0 ? moder : 0;
    return ans;
}

int main(){
    int n, p, l, r;
    scanf("%d%d%d%d", &n, &p, &l, &r);
    ll nowans = 0, nowmod = 1;
    for (int i = 2; i * i <= p; ++ i){
        if (p % i == 0){
            moder = 1;
            int cnt = 0;
            while (p % i == 0){
                p /= i;
                ++ cnt;
                moder *= i;
            }
            ll ans = solve(n, l, r, i, cnt);
            ll tmp = nowmod * moder;
            nowans = (nowans * moder % tmp * eucinv(moder, nowmod) + ans * nowmod * eucinv(nowmod, moder)) % tmp;
            nowmod = tmp;
        }
    }
    if (p > 1){
        moder = p;
        ll ans = solve(n, l, r, p, 1);
        ll tmp = nowmod * moder;
        nowans = (nowans * moder % tmp * eucinv(moder, nowmod) + ans * nowmod * eucinv(nowmod, moder)) % tmp;
        nowmod = tmp;
    }
    printf("%lld\n", nowans);
    return 0;
}